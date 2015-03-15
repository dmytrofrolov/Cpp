#include <iostream>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

//includes datatypes to use
//
#include <sys/types.h>

//definitions for sockets
#include <sys/socket.h>

//contains constants for internet addresses
#include <netinet/in.h>

using namespace std;

void error(const char * errorText);

int main(int argc, char *argv[])
{
    //sockfd and newsockfd numbers in filde descriptor table
    //what program will use to communticate sockets
    int sockfd = 0, newsockfd = 0;

    int connectId = 0;

    //port where server accept connections
    unsigned short int port = 1334;

    //stores the size of the address of the client
    unsigned int clientLen = 0;

    //for read or write - size of block to accept or send
    int bufLen = 0;

    //server reads from socket
    char buffer[256];

    //sockaddr_in - structure with internet address
    struct sockaddr_in serverAddress, clientAddress;

    //if user forget to input address for server
    if (argc < 2){
        error("Not enought arguments!");
    }

    //socket() - address domain of the socket, type of socket, protocol (0 - for most appropriate one)
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0)
        error("ERROR opening socket");

    //sets all values in buffer to zero
    bzero((char *) &serverAddress, sizeof(serverAddress));

    port = atoi(argv[1]);

    //set parameters for serverAddress
    serverAddress.sin_family = AF_INET;
    serverAddress.sin_port = htons(port);       //convert to network byte order and copy to sin_port
    serverAddress.sin_addr.s_addr = INADDR_ANY; //contains an IP address of the host


    //binds socket to an address
    if (bind(sockfd, (struct sockaddr *) &serverAddress, sizeof(serverAddress)) < 0)
        error("ERROR on binding");

    //listen to socket, 5 - for the size of the backlog queue
    //the number of connections that can be waiting while
    //the process is handling a particular connection
    //5 is the maximum size for most systems
    listen(sockfd,5);

    //block until connect to the server
    clientLen = sizeof(clientAddress);

    while(1){
        //accept returns new file description
        newsockfd = accept(sockfd, (struct sockaddr *) &clientAddress, &clientLen);
        if (newsockfd < 0)
            error("ERROR on accept");

         connectId = fork();
         if (connectId < 0)
             error("ERROR on fork");

         if (connectId == 0)  {
            close(sockfd);
            bzero(buffer,256);

            bufLen = read(newsockfd, buffer, 255);
            if (bufLen < 0) error("ERROR reading from socket");
            cout << "Here is the message: " << buffer << endl;
            bufLen = write(newsockfd,"I got your message",18);
            if (bufLen < 0) error("ERROR writing to socket");
                 exit(0);
         }
         else close(newsockfd);
    }
    close(sockfd);
    return 0;
}


void error(const char * errorText){
    cerr << errorText << endl;
    exit(1);
}
