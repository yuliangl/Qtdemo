#include <iostream>
#include <sys/types.h>
#include <sys/socket.h>
#include <sys/select.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <string.h>

#define onhway_error(msg) \
    do { perror(msg); exit(EXIT_FAILURE);} while(0)

int main(int argc, char** argv){
    int lFd = socket(AF_INET, SOCK_STREAM, 0);
    if(lFd == -1) {
        onhway_error("socket error");
    }
    sockaddr_in sersock;
    sersock.sin_family = AF_INET;
    sersock.sin_addr.s_addr = htonl(INADDR_ANY);
    sersock.sin_port = htons(5000);

    if(bind(lFd, (sockaddr*)&sersock, sizeof(sersock)) == -1){
        onhway_error("bind serror");
    }
    
    if(listen(lFd, 30) == -1){
        onhway_error("listen srror");
    }
    
    sockaddr_in clisock;
    socklen_t soclen = sizeof(clisock);

    fd_set reads, tmep;
    FD_ZERO(&reads);
    FD_SET(lFd, &reads);
    uint32_t maxfd = lFd + 1;

    while(1){
        tmep = reads;
        if(select(maxfd+1, &tmep, NULL, NULL, NULL) == -1){
            onhway_error("accept error");
        }
        if(FD_ISSET(lFd, &tmep)){
            int cfd = accept(lFd, (sockaddr*)&clisock, &soclen);
            if(cfd == -1)
                onhway_error("accept error");
            else
                std::cout<< "connect success" << std::endl;

            FD_SET(cfd, &reads);
            maxfd = maxfd < cfd ? cfd : maxfd;
        }
        for(int i=lFd+1; i<maxfd+1; ++i){
            if(FD_ISSET(i, &tmep)){
                char wbuf[] = "reci";
                char buf[1024];
                memset(buf, 0, sizeof(buf));
                int len = read(i, buf, sizeof(buf));
                if(len > 0){
                    std::cout<< "from client: " << buf << std::endl;
                    write(i, wbuf, sizeof(wbuf));
                }else if( len == 0 ){
                    std::cout<< "disconnect" <<std::endl;
                    FD_CLR(i, &reads);
                    close(i);
                    break;
                }else{
                    onhway_error("read error");
                }
            }
        }
    }
    close(lFd);
    return 0;

}//end flag
