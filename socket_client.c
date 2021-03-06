//#include <stdio.h>
//#include <stdlib.h>
//#include <errno.h>
//#include <string.h>
//#include <netdb.h>
//#include <netinet/in.h>
//#include <arpa/inet.h>
//#include <sys/socket.h>
//#include <sys/types.h>
//#include <sys/wait.h>
//
//#define DEST_HOST "localhost"	// 目标主机域名
//#define DEST_PORT 1500			// 目标主机端口号
//#define BUF_SIZE 100			// 接收到的数据最大字节数
//
//int main() {
//	// socket 句柄
//	int socket_fd = socket(AF_INET, SOCK_STREAM, 0);
//	if (socket_fd == -1) {
//		printf("init socket failed: %d\n", errno);
//		return -1;
//	}
//
//	// 目标地址信息
//	struct sockaddr_in dest_addr;
//	dest_addr.sin_family = AF_INET;
//	struct hostent* host = gethostbyname(DEST_HOST);
//	const char* dest_ip = inet_ntoa(*(struct in_addr*)host->h_addr_list[0]);
//	dest_addr.sin_addr.s_addr = inet_addr(dest_ip);
//	dest_addr.sin_port = htons(DEST_PORT);
//	bzero(&(dest_addr.sin_zero), 8);
//
//	// 储存接收数据
//	char buf[BUF_SIZE];
//	// 连接，传入句柄，目标地址和大小
//	if (connect(socket_fd, (struct sockaddr*)&dest_addr, sizeof(struct sockaddr)) == -1) {
//		// 失败时打印 errno
//		printf("connect failed: %d\n", errno);
//	}
//	else {
//		printf("connect success, dest_ip: %s, dest_port: %d\n", dest_ip, DEST_PORT);
//		char request[] = "Hi, I'm socket client";
//		send(socket_fd, request, strlen(request), 0);
//		printf("sending: %s\n", request);
//		// 将接收数据存入 buf，参数分别是句柄，储存位置，最大长度，其他信息（设为0即可）
//		recv(socket_fd, buf, BUF_SIZE, 0);
//		printf("received: %s\n", buf);
//	}
//	// 关闭 socket
//	close(socket_fd);
//	return 0;
//}
