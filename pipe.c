#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

int main()
{
    int pid, n, fd[2];
    char buf[255];
    
    if(pipe(fd) <0)
    {
        perror("pipe error : ");
        exit(0);
    }

    if((pid = fork()) < 0 )//pipe create
    {
        perror("fork error :");
        exit(0);
    }

    else if(pid ==0)//chile process
    {
        close(fd[0]);
        while(1)
        {
            memset(buf, 0x00, 255);
            sprintf(buf, "Send to parent process. from child process pid(%d)\n",getpid());
            write(fd[1],buf,strlen(buf));
            sleep(1);
        }
    }
    else //parent process
    {
        close(fd[1]);
        memset(buf, 0x00, 255);
        n =read(fd[0], buf, 255);
        fprintf(stderr, "%s", buf);
    }

}


