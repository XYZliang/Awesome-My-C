#include<time.h>
#include<stdio.h>
int main(void)
{
    struct tm* ptr;
    time_t lt;
    char str[80];
    lt=time(NULL);
    ptr=localtime(&lt);
    strftime(str,sizeof(str),"%H,%M,%S",ptr);
    printf("%s\n",str);
    
    return 0;
}
struct tm* ptr;
time_t lt;
char nowTime[8];
lt=time(NULL);
ptr=localtime(&lt);
strftime(str,sizeof(str),"%H,%M,%S",ptr);
