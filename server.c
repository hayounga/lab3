#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>
#include <mqueue.h>

int main(int argc, char* argv[]){
    struct mq_attr attr;
    attr.mq_maxmsg = 10;
    attr.mq_msgsize = 4;
    char msg[100];
    mqd_t mfd;

    mfd = mq_open("/lab3_test", O_RDWR | O_CREAT, 0666, &attr);
    if(mfd == -1){
        perror("open error");
        exit(0);
    }
    if((mq_receive(mfd, msg, attr.mq_msgsize, NULL)) == -1) {
        exit(-1);
    }

    printf("Client Say : %s\n", msg);
    printf("Close...\n");
}


