#include <sys/socket.h>
#include <netinet/in.h>
#include <netinet/ip.h>
#include <sys/types.h>
#include <arpa/inet.h>
#include <string.h>
#include <iostream>
    using namespace std;

#define MYADDR "192.168.000.148" //Just fill in your IPv4 address.
#define BACKLOG 0 //Define your backlog
int main()
{

    sockaddr_in my_sock, client_sock;
    memset(&my_sock, 0, sizeof(my_sock));
    memset(&client_sock, 0, sizeof(client_sock));
    socklen_t client_sock_len = sizeof(client_sock);
    my_sock.sin_family = AF_INET;
    my_sock.sin_port = htons(2250);
    if (inet_aton(MYADDR, &my_sock.sin_addr) != 1 )
    {
        cerr << "erro na conversão do ip" << endl;
        return -1;
    }


    int server_tcp_socket = socket(AF_INET, SOCK_STREAM, 0);

    if (server_tcp_socket < 0 ) 
    {
        cerr << "erro ao criar socket" << endl;
        return -1;
    }


    if (bind(server_tcp_socket, (struct sockaddr *) &my_sock, sizeof(my_sock)) != 0)
    {
        cerr << "erro em bindar" << endl;
        return -1;
    }


    if (listen(server_tcp_socket, BACKLOG) < 0 )
    {
        cerr << "erro ao entrar em modo listen" << endl;
    }

    int conection = accept(server_tcp_socket, (struct sockaddr *) &client_sock, &client_sock_len );

    if(conection < 0 )
    {
        cerr << "erro ao aceitar conexão." << endl;
        return -1;
    }

    return 0;
}