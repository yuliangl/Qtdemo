#include <string.h> 
#include <iostream>
#include <sys/socket.h>
#include <sys/types.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <arpa/inet.h>


#define onhway_error(msg) \
    do { perror(msg); exit(EXIT_FAILURE);} while(0)

int main(int argc, char** argv){
    int lfd = socket(AF_INET, SOCK_STREAM, 0);
    if(lfd == -1)
        onhway_error("socket error");

    sockaddr_in sersock;
    sersock.sin_family = AF_INET;
    sersock.sin_port = htons(5000);
    //sersock.sin_addr.s_addr = htonl(INADDR_ANY);
    inet_pton(AF_INET, "127.0.0.1", &sersock.sin_addr.s_addr);
    
    int cfd = connect(lfd, (sockaddr*)&sersock, sizeof(sersock));
    if(cfd == -1)
        onhway_error("connect error");

    char buf[10];
    while(1){
        fgets(buf, 10, stdin);
        write(lfd, buf, strlen(buf));
        std::cout<< "w buf size: " << strlen(buf) << std::endl;
        
        int len = read(lfd, buf, sizeof(buf));
        std::cout<< "r buf size: " << strlen(buf) << std::endl;
        if(len == -1){
            onhway_error("read error");
        }else if( len == 0 ){
            std::cout<< "disconnect" <<std::endl;
            close(cfd);
            break;
        }else{
            std::cout<< "from server: " << buf << std::endl;
        }
    }
    close(lfd);
    return 0;
}//end flag
