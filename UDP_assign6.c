//SERVER 
#include <iostream>
#include <string>
#include <algorithm>
#include <cctype>
#include <cstring>
#include <sys/socket.h>
#include <netinet/in.h>
#include <unistd.h>

#define PORT 8080

struct Packet
{
    int choice;
    char text[1024];
};

int main()
{
    int sockfd;
    struct sockaddr_in server, client;

    sockfd = socket(AF_INET, SOCK_DGRAM, 0);

    server.sin_family = AF_INET;
    server.sin_addr.s_addr = INADDR_ANY;
    server.sin_port = htons(PORT);

    bind(sockfd, (struct sockaddr *)&server, sizeof(server));

    std::cout << "UDP Server started...\n";

    while (true)
    {
        Packet pkt;
        socklen_t len = sizeof(client);

        recvfrom(sockfd, &pkt, sizeof(pkt), 0,
                 (struct sockaddr *)&client, &len);

        if (pkt.choice == 3)
        {
            std::cout << "Client exited.\n";
            break;
        }

        std::string result = pkt.text;

        if (pkt.choice == 1)
        {
            for (char &c : result)
            {
                if (isupper(c))
                    c = tolower(c);
                else if (islower(c))
                    c = toupper(c);
            }
        }

        else if (pkt.choice == 2)
        {
            reverse(result.begin(), result.end());
        }

        else
        {
            result = "Invalid choice";
        }

        sendto(sockfd, result.c_str(), result.length(), 0,
               (struct sockaddr *)&client, len);
    }

    close(sockfd);

    return 0;
}



//CLIENT
#include <iostream>
#include <cstring>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>

#define PORT 8080

struct Packet
{
    int choice;
    char text[1024];
};

int main()
{
    int sockfd;
    struct sockaddr_in server;

    sockfd = socket(AF_INET, SOCK_DGRAM, 0);

    server.sin_family = AF_INET;
    server.sin_port = htons(PORT);
    server.sin_addr.s_addr = inet_addr("127.0.0.1");

    while (true)
    {
        Packet pkt;

        std::cout << "\n1. Change Case\n";
        std::cout << "2. Reverse String\n";
        std::cout << "3. Exit\n";
        std::cout << "Enter choice: ";

        std::cin >> pkt.choice;
        std::cin.ignore();

        if (pkt.choice == 3)
        {
            sendto(sockfd, &pkt, sizeof(pkt), 0,
                   (struct sockaddr *)&server, sizeof(server));

            break;
        }

        if (pkt.choice != 1 && pkt.choice != 2)
        {
            std::cout << "Invalid choice!\n";
            continue;
        }

        std::cout << "Enter string: ";
        std::cin.getline(pkt.text, 1024);

        sendto(sockfd, &pkt, sizeof(pkt), 0,
               (struct sockaddr *)&server, sizeof(server));

        char buffer[1024];

        socklen_t len = sizeof(server);

        int n = recvfrom(sockfd, buffer, 1023, 0,
                         (struct sockaddr *)&server, &len);

        buffer[n] = '\0';

        std::cout << "Server result: " << buffer << "\n";
    }

    close(sockfd);

    return 0;
}