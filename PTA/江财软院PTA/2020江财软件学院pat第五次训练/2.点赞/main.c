/*
 https://pintia.cn/problem-sets/1209303932722429952/problems/1209303983133761537
 
 微博上有个“点赞”功能，你可以为你喜欢的博文点个赞表示支持。每篇博文都有一些刻画其特性的标签，而你点赞的博文的类型，也间接刻画了你的特性。本题就要求你写个程序，通过统计一个人点赞的纪录，分析这个人的特性。

 输入格式：
 输入在第一行给出一个正整数N（≤1000），是该用户点赞的博文数量。随后N行，每行给出一篇被其点赞的博文的特性描述，格式为“K   F1⋯FK ”，其中1≤K≤10，Fi（i=1,⋯,K）是特性标签的编号，我们将所有特性标签从1到1000编号。数字间以空格分隔。

 输出格式：
 统计所有被点赞的博文中最常出现的那个特性标签，在一行中输出它的编号和出现次数，数字间隔1个空格。如果有并列，则输出编号最大的那个。

 输入样例：
 4
 3 889 233 2
 5 100 3 233 2 73
 4 3 73 889 2
 2 233 123

 输出样例：
 233 3
 
 14/20
 
 */
#include<stdio.h>
int main()
{
    int a[999]={0},sum[999]={0},n,b=0;
    scanf("%d\n",&n);
    for(int i=1;i<=n;i++)
    {
        int c=0;char d = '\0';
        c=getchar()-48;
        for(int ii=b;d!='\n';ii++)
        {
            scanf("%d",&a[ii]);
            d=getchar();
        }
        
        b+=c;
    }
    for(int i=0;i<b;i++)
    {
        for(int ii=0;ii<=i;ii++)
        {
            if(a[i]==a[ii])
                sum[i]++;
        }
    }
    int maxnumber=0,max=a[0];
    for(int i=1;i<b;i++)
    {
        if (sum[i]>sum[maxnumber])
        {
                max=a[i];
                maxnumber=i;
        }
        else if(sum[i]==sum[maxnumber])
        {
            if(a[i]>a[maxnumber])
            {
                max=a[i];
                maxnumber=i;
            }
        }
    }

    printf("%d %d\n",max,sum[maxnumber]);
    return 0;
}
