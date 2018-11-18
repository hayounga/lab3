#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

int main(){
	time_t start_time, end_time;
	float result;
	char msg[3][30] = {{"Hello World"},
			   {"My name is Hayoung"},
			   {"Have a nice day!!"}
	};
	char input[3][30];
	system("clear");
	int i, j, msg_len, input_len, longer_len, total, chk=0;
        char c;
       
       	start_time = time(NULL);
        for(i=0; i<3; i++) {
                puts(msg[i]);
                scanf("%[^\n]s", input[i]);     
                msg_len = strlen(msg[i]);
                input_len = strlen(input[i]);
                printf("원래 글자수 : %d, 입력한 글자수 : %d\n", msg_len, input_len);
                total += input_len;

                if(msg_len > input_len) longer_len = msg_len;
                else if(msg_len <= input_len) longer_len = input_len;

                for(j=0; j<longer_len; j++) {
                        if(msg[i][j] != input[i][j]) chk++;
                }
                printf("오타수 : %d\n", chk);
                chk=0;
                printf("press enter...\n\n\n");
                getchar();
        }
        end_time = time(NULL);
        result = (float)(end_time - start_time);
        printf("평균 %.2f초 걸렸습니다.\n", result/3);
        printf("분당 타자수 %.2f타\n", (60/result)*total);
}
