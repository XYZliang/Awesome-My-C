
#include<stdio.h>
int main()
{
    long long n,m,v;
    while(scanf("%llx%llx",&n,&m)==2)
    {
        v=n+m;
        if(v<0)
        {
            v=-v;
            printf("-%llX\n",v);
        }
        else
        printf("%llX\n",v);
    }
     return 0;
 }
