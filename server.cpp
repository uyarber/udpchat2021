/* server.cpp
   Sample UDP server in C++
   Adapted by James Skon, 2009
*/

#include <iostream>
#include <string>
using namespace std;

#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <stdio.h>
#include <unistd.h>
#include <errno.h>
#include <string.h>
#include <stdlib.h>

int main()
{
  int sock;
  int addr_len, bytes_read;
  char recv_data[1024];
  struct sockaddr_in server_addr , client_addr;


  if ((sock = socket(AF_INET, SOCK_DGRAM, 0)) == -1) {
	perror("Socket");
	exit(1);
  }

  server_addr.sin_family = AF_INET;
  server_addr.sin_port = htons(5000);
  server_addr.sin_addr.s_addr = INADDR_ANY;
  memset(&(server_addr.sin_zero),0,8);

  if (bind(sock,(struct sockaddr *)&server_addr,
		   sizeof(struct sockaddr)) == -1)
	{
	  perror("Bind");
	  exit(1);
	}

  addr_len = sizeof(struct sockaddr);
  
  cout << "\nUDPServer Waiting for client on port 5000";
  fflush(stdout);

  while (1)
	{

	  bytes_read = recvfrom(sock,recv_data,1024,0,
							(struct sockaddr *)&client_addr, (socklen_t *) &addr_len);

	  recv_data[bytes_read] = '\0';

	  cout << endl << inet_ntoa(client_addr.sin_addr) << " , " << ntohs(client_addr.sin_port);
	  cout << " said: " << recv_data;
	  cout.flush();


	}
  return 0;
}