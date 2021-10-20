/* client.cpp
   Sample UDP Client in C++
   Adapted by James Skon, 2009
*/

#include <iostream>
#include <string>
using namespace std;

#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <stdio.h>
#include <unistd.h>
#include <errno.h>
#include <stdlib.h>
#include <strings.h>
#include <cstring>
#include <cstdlib>
#include <unistd.h>

int main()
{
  int sock;
  struct sockaddr_in server_addr;
  struct hostent *host;
  string send_data;
  char cs[1024];

  host= (struct hostent *) gethostbyname((char *)"127.0.0.1");


  if ((sock = socket(AF_INET, SOCK_DGRAM, 0)) == -1)
	{
	  perror("socket");
	  exit(1);
	}

  server_addr.sin_family = AF_INET;
  server_addr.sin_port = htons(5000);
  server_addr.sin_addr = *((struct in_addr *)host->h_addr);
  memset(&(server_addr.sin_zero),0,8);

  while (1)
	{

	  cout << "Type Something (q or Q to quit):";
	  cin >> send_data;

	  if (send_data == "q" || send_data == "Q")
		break;

	  else {
		strcpy(cs,send_data.c_str());
		sendto(sock, cs, strlen(cs), 0,
			   (struct sockaddr *)&server_addr, sizeof(struct sockaddr));
	  }
     
	}

}
