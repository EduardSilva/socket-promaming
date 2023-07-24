#include <sys/socket.h>
#include <netinet/in.h>
#include <netinet/ip.h>
#include <sys/types.h>
#include <arpa/inet.h>
#include <string.h>
#include <iostream>
    using namespace std;

#define SERVER_IP "192.168.000.148"
#define MYIP ""

int main ()
{
    sockaddr_in my_sock, server_sock;
    memset(&my_sock, 0 , sizeof(my_sock));
    memset(&server_sock, 0, sizeof(server_sock));

    socklen_t server_sock_len;

    //configurações do socket do servidor

    server_sock.sin_family = AF_INET;

    server_sock.sin_port = htons(2250);

    if (inet_aton(SERVER_IP, &server_sock.sin_addr) != 1){
        cerr << "Erro em traduzir o ip" << endl;
        return -1;
    }

    server_sock_len = sizeof(server_sock);

    //Configurações do socket cliente

    my_sock.sin_family = AF_INET;
    my_sock.sin_port = htons(2250);

    if (inet_aton(MYIP, &my_sock.sin_addr) != 1){
        cerr << "Erro em traduzir o ip" <<endl;
        return -1;
    }

    int tcp_socket = socket(AF_INET, SOCK_STREAM, 0);

    if(tcp_socket < 0)
    {
        cerr << "Erro ao criar socket" << endl;
        return -1;
    }

    int connection = connect(tcp_socket, (const sockaddr *) &server_sock, server_sock_len);

    if(connection < 0 )
    {
        cerr << "Erro ao aceitar conexão" << endl;
        return -1;
    }

    while (true)
    {
        
    }
    

    return 0;
}