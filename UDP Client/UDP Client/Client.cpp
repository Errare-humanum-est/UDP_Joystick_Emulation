#undef UNICODE

#define WIN32_LEAN_AND_MEAN

#pragma comment (lib, "Ws2_32.lib")

#include <WinSock2.h>
#include <windows.h>
#include <iostream>


using namespace std;

int main(void) 
{
    WSADATA wsaData;
	SOCKET sd;							/* Socket descriptor of server */
    int iResult;

    WORD DllVersion = MAKEWORD(2,2);
    // Initialize Winsock
    int startup_RetVal = WSAStartup(DllVersion, &wsaData);
   
	sd = socket(AF_INET, SOCK_DGRAM, IPPROTO_UDP);

	if (sd == INVALID_SOCKET)
	{
		fprintf(stderr, "Could not create socket.\n");
		WSACleanup();
		exit(0);
	}

	SOCKADDR_IN addr;

	addr.sin_addr.s_addr = inet_addr("127.0.0.1");
	addr.sin_family = AF_INET;
	addr.sin_port = htons(2015);

	bind(sd, (SOCKADDR*)&addr, sizeof(addr));

	char buf[2048] ={0};

	do
	{
	recvfrom(sd, buf, 2048, NULL, NULL, NULL); 

	printf("%s \n",buf);

	}while(1);

	getchar();
    return 0;
}