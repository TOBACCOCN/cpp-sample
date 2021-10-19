//#include <stdio.h>
//#include <stdlib.h>
//#include <errno.h>
//#include <string.h>
//#include <netinet/in.h>
//#include <arpa/inet.h>
//#include <sys/socket.h>
//#include <sys/types.h>
//#include <sys/wait.h>
//
//#define PORT            1500            // 端口号
//#define BACKLOG         5               // 最大监听数
//#define BUF_LENGTH      100             // 接收到的数据最大字节数
//
//int main() {
//	// socket 句柄
//	int socket_fd = socket(AF_INET, SOCK_STREAM, 0);
//	if (socket_fd == -1) {
//		printf("init socket failed: %d\n", errno);
//		return -1;
//	}
//
//	// 服务端和客户端连接地址信息
//	struct sockaddr_in server_addr;
//	// 该属性表示接收本机或其他机器传输
//	server_addr.sin_family = AF_INET;
//	// 本机 IP
//	server_addr.sin_addr.s_addr = htonl(INADDR_ANY);
//	// 端口号
//	server_addr.sin_port = htons(PORT);
//	// 将其他属性置 0
//	bzero(&(server_addr.sin_zero), 8);
//
//	// 绑定地址结构体和 socket
//	if (bind(socket_fd, (struct sockaddr*)&server_addr, sizeof(struct sockaddr)) < 0) {
//		printf("bind error\n");
//		return -1;
//	}
//
//	// 开启监听
//	listen(socket_fd, BACKLOG);
//	printf("socket server started, port: %d\n", PORT);
//	struct sockaddr_in client_addr;
//	int addr_size = sizeof(struct sockaddr_in);
//	char buf[BUF_LENGTH];
//	char response[BUF_LENGTH];
//	while (1) {
//		// 阻塞直到接收到消息，参数分别是 socket 句柄，接收到的地址信息以及大小
//		int accept_fd = accept(socket_fd, (struct sockaddr*)&client_addr, &addr_size);
//		if (accept_fd == -1) {
//			printf("accept error\n");
//		}
//		else {
//			recv(accept_fd, buf, BUF_LENGTH, 0);
//			printf("received: %s, remote_ip: %s, remote_port: %d\n", buf, inet_ntoa(client_addr.sin_addr), ntohs(client_addr.sin_port));
//			// 发送内容，参数分别是连接句柄，内容，大小，其他信息（设为 0 即可）
//			sprintf(response, "Hi, I'm socket server, timestamp: %d\n", time(NULL));
//			send(accept_fd, response, strlen(response), 0);
//			printf("sending: %s\n", response);
//		}
//	}
//	return 0;
//}
