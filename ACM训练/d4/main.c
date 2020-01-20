//青年歌手大奖赛中，评委会给参赛选手打分。选手得分规则为去掉一个最高分和一个最低分，然后计算平均得分，请编程输出某选手的得分。
//Input
//输入数据有多组，每组占一行，每行的第一个数是n(2<n<=100)，表示评委的人数，然后是n个评委的打分。
//Output
//对于每组输入数据，输出选手的得分，结果保留2位小数，每组输出占一行。
//Sample Input
//3 99 98 97
//4 100 99 98 97
//Sample Output
//98.00
//98.50
#include <stdio.h>
#include <stdlib.h>
void Bubble(int *a,int len)
{
    int i=0,j=0,temp=0;
    for(i=1;i<len;i++)
    {
        for(j=len-1;j>=i;j--)
        {
            if(a[j]<a[j-1])
            {
              temp=a[j];
              a[j]=a[j-1];
              a[j-1]=temp;
            }
        }
    }
}
int main()
{
    int a[100],i,n;
    while(scanf("%d",&n) != EOF)
    {
        if(n==0)
            break;
        for(i = 0; i < n; i++)
        {
            scanf("%d", &a[i]);
        }
        int b[100];
        for(i = 0; i < n; i++)
        {
            b[i]=abs(a[i]);
        }
        Bubble(b,n);
        for(i = 0; i < n; i++)
        {
            if(a[i]<0)
                printf("-%d ",b[i]);
            else
                printf("%d ",b[i]);
        }
        printf("\n");
    }
    return 0;
}
