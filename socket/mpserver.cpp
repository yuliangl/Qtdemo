#include <iostream>
#include <sys/types.h>
#include <sys/socket.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <string.h>
#include <signal.h>
#include <sys/wait.h>
#include <errno.h>

#define onhway_error(msg) \
    do { perror(msg); exit(EXIT_FAILURE);} while(0)

void hander(int a){
    pid_t wpid;
    while((wpid = waitpid(-1, NULL, WNOHANG)) > 0 ){
        std::cout<< "child process " << wpid << " wait sucess" << std::endl;
    }
}

int main(int argc, char** argv){
    int lFd = socket(AF_INET, SOCK_STREAM, 0);
    if(lFd == -1) {
        onhway_error("socket error");
    }
    sockaddr_in sersock;
    sersock.sin_family = AF_INET;
    sersock.sin_addr.s_addr = htonl(INADDR_ANY);
    sersock.sin_port = htons(5000);

    if( bind(lFd, (sockaddr*)&sersock, sizeof(sersock)) == -1){
        onhway_error("bind serror");
    }
    
    if( listen(lFd, 30) == -1 ){
        onhway_error("listen error");
    }

    struct sigaction sct;
    sct.sa_flags = 0;
    sct.sa_handler = hander;
    sigemptyset(&sct.sa_mask);
    sigaction(SIGCHLD, &sct, NULL);

    //sigset_t socset, oldset;
    //sigaddset(&socset, SIGCHLD);
    //sigprocmask(SIG_BLOCK, &socset, &oldset);
    
    sockaddr_in clisock;
    socklen_t soclen = sizeof(clisock);
    while(1){
        int cfd = accept(lFd, (sockaddr*)&clisock, &soclen);
        while(cfd==-1 && errno == EINTR){
            cfd = accept(lFd, (sockaddr*)&clisock, &soclen);
        }
        std::cout<< "connect success" << std::endl;
        pid_t pid = fork();
        if(pid == 0){
            close(lFd);
            char wbuf[] = "reci";
            char buf[1024];
            while(1){
                memset(buf, 0, sizeof(buf));
                int len = read(cfd, buf, sizeof(buf));
                if(len == -1){
                    onhway_error("read error");
                }else if( len == 0 ){
                    std::cout<< "disconnect" <<std::endl;
                    close(cfd);
                    break;
                }else{
                    std::cout<< "from client: " << buf << std::endl;
                    write(cfd, wbuf, sizeof(wbuf));
                }
            }
            return 0;
        }else{
            close(cfd);
        }
    }
    close(lFd);
    return 0;

}//end flag
