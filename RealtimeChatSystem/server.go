package main

import (
	"fmt"
	"net"
	"sync"
	"time"
)

type Server struct {
	Ip   string
	Port int
	// 在线用户的列表
	OnlineMap map[string]*User
	mapLock   sync.RWMutex
	// 消息广播的channel
	Message chan string
}

// 创建一个新的Server的接口
func NewServer(ip string, port int) *Server {
	server := &Server{
		Ip:        ip,
		Port:      port,
		OnlineMap: make(map[string]*User),
		Message:   make(chan string),
	}
	return server
}

// 监听Message广播的goroutine，一旦有消息就发送给全部的在线user
func (this *Server) ListenMessager() {
	for {
		msg := <-this.Message
		// 将msg发送给全部的在线用户
		this.mapLock.Lock()
		for _, cil := range this.OnlineMap {
			cil.C <- msg
		}
		this.mapLock.Unlock()
	}
}

// 广播消息的方法
func (this *Server) BroadCase(user *User, msg string) {
	sendMsg := "[" + user.Addr + "]" + user.Name + ":" + msg
	this.Message <- sendMsg
}

func (this *Server) Handler(conn net.Conn) {
	// 用户上线，将用户加入到onlineMap中
	user := NewUser(conn, this)
	user.Online()
	// 监听用户是否活跃的channel
	isLive := make(chan bool)

	// 接收客户端发送的消息
	go func() {
		buf := make([]byte, 4096)
		for {
			n, err := conn.Read(buf)
			if n == 0 {
				user.Offline()
				return
			}
			if err != nil {
				fmt.Println("Read", err)
				return
			}
			// 提取用户的消息，去除\n
			msg := string(buf[:n-1])
			// 将得到的消息进行广播
			user.DoMessage(msg)
			// 用户的任意消息代表当前的用户是活跃的
			isLive <- true
		}

	}()
	// 当前handler阻塞
	for {
		select {
		case <-isLive:
			// 当前用户是活跃的，应该重置计时器
			// 不做任何事情，为了激活select，更新下面的计时器
		case <-time.After(time.Second * 300):
			// 已经超时，将当前的user强制的关闭
			user.SendMessage("你被踢了")
			// 销毁用户的资源
			close(user.C)
			// 关闭链接
			conn.Close()
			// 退出当前的handler
			return // 或者使用runtime.Goexit()
		}
	}
}

// 启动服务器的接口
func (this *Server) Start() {
	// socket listen
	listener, err := net.Listen("tcp", fmt.Sprintf("%s:%d", this.Ip, this.Port))
	if err != nil {
		fmt.Println("Listen", err)
		return
	}
	defer listener.Close()
	// 启动监听Message的goroutine
	go this.ListenMessager()
	for {
		// accept
		conn, err := listener.Accept()
		if err != nil {
			fmt.Println("Accept", err)
			continue
		}
		// do handler
		go this.Handler(conn)
	}
}
