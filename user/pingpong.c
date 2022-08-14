#include "kernel/types.h"
#include "user/user.h"

int main(int argc, char** argv ){
    int pid;
    int parent_fd[2];
    int child_fd[2];
    char buf[20];
    //为父子进程建立管道
    //pipe(pipefd) 系统调用会创建管道，并把读取和写入的文件描述符返回到 pipefd中。 pipefd[0] 指管道的读取端， pipefd[1] 指管道的写入端。
    pipe(child_fd); 
    pipe(parent_fd);
 
    //使用 fork 创建子进程，子进程的 fork 返回值为 0 ，父进程的 fork 返回子进程的 进程 ID ，所以通过 if 语句就能让父进程和子进程执行不同的代码块。
    // Child Progress
    if((pid = fork()) == 0){
        close(parent_fd[1]);
        read(parent_fd[0],buf, 4);
        printf("%d: received %s\n",getpid(), buf);
        close(child_fd[0]);
        write(child_fd[1], "pong", sizeof(buf));
    }
    // Parent Progress
    else{
        close(parent_fd[0]);
        write(parent_fd[1], "ping",4);
        close(child_fd[1]);
        read(child_fd[0], buf, sizeof(buf));
        printf("%d: received %s\n", getpid(), buf);
    }
    exit(0);
}
