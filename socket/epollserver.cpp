#include <iostream>
#include <sys/types.h>
#include <sys/socket.h>
#include <sys/epoll.h>
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

    int epfd = epoll_create(1024);
    epoll_event oevent[1024];
    epoll_event evs;
    evs.events = EPOLLIN;
    evs.data.fd = lFd;
    epoll_ctl(epfd, EPOLL_CTL_ADD, lFd, &evs);

    while(1){

        int iofds = epoll_wait(epfd, oevent, 1024, -1);
        for(int i=0; i<iofds; ++i){
            if(oevent[i].data.fd == lFd){
                int cfd = accept(lFd, (sockaddr*)&clisock, &soclen);
                if(cfd == -1)
                onhway_error("accept error");
                else
                std::cout<< "connect success" << std::endl;

                evs.events = EPOLLIN;
                evs.data.fd = cfd;
                epoll_ctl(epfd, EPOLL_CTL_ADD, cfd, &evs);
            }else{
                char wbuf[] = "reci";
                char buf[1024];
                memset(buf, 0, sizeof(buf));
                int len = read(oevent[i].data.fd, buf, sizeof(buf));
                if(len > 0){
                    std::cout<< "from client: " << buf << std::endl;
                    write(oevent[i].data.fd, wbuf, sizeof(wbuf));
                }else if( len == 0 ){
                    std::cout<< "disconnect" <<std::endl;
                    epoll_ctl(epfd, EPOLL_CTL_DEL, oevent[i].data.fd, &oevent[i]);
                    close(oevent[i].data.fd);
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
