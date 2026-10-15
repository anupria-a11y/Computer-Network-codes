//SERVER
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>

#define PORT 45678

int main()
{
    int server_socket, client_socket;
    struct sockaddr_in server, client;
    char buffer[1024];

    server_socket = socket(AF_INET, SOCK_STREAM, 0);

    server.sin_family = AF_INET;
    server.sin_addr.s_addr = INADDR_ANY;
    server.sin_port = htons(PORT);

    bind(server_socket, (struct sockaddr *)&server, sizeof(server));

    listen(server_socket, 5);
    printf("Server is waiting for client...\n");

    int size = sizeof(client);
    client_socket = accept(server_socket,
                           (struct sockaddr *)&client,
                           &size);

    printf("Client connected.\n");

    memset(buffer, 0, sizeof(buffer));
    recv(client_socket, buffer, sizeof(buffer), 0);

    printf("Message from client: %s\n", buffer);

    char reply[] = "Hello Client!";
    send(client_socket, reply, strlen(reply), 0);

    close(client_socket);
    close(server_socket);

    printf("Server closed.\n");

    return 0;
}



//CLIENT
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>

#define PORT 45678

int main()
{
    int client_socket;
    struct sockaddr_in server;
    char message[1024];
    char buffer[1024];

    client_socket = socket(AF_INET, SOCK_STREAM, 0);

    server.sin_family = AF_INET;
    server.sin_port = htons(PORT);

    inet_pton(AF_INET, "127.0.0.1", &server.sin_addr);

    connect(client_socket,
            (struct sockaddr *)&server,
            sizeof(server));

    printf("Connected to server.\n");

    printf("Enter message: ");
    fgets(message, sizeof(message), stdin);

    message[strcspn(message, "\n")] = '\0';

    send(client_socket, message, strlen(message), 0);

    memset(buffer, 0, sizeof(buffer));
    recv(client_socket, buffer, sizeof(buffer), 0);

    printf("Reply from server: %s\n", buffer);

    close(client_socket);

    return 0;
}