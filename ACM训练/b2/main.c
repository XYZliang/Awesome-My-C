#include<stdio.h>
typedef long long ll;
const int maxn=30;
ll c[maxn][maxn];
ll f[maxn];

void init()
{
    c[0][0]=1;
    for(int i=1;i<maxn;i++)
        for(int j=0;j<=i;j++)
        c[i][j]=c[i-1][j-1]+c[i-1][j];
     f[1]=0;
     f[2]=1;
     for(int i=3;i<=20;i++)
        f[i]=(i-1)*(f[i-1]+f[i-2]);
}
int main()
{
    init();
    int T;
    scanf("%d",&T);
    while(T--){
        int n,m;
    scanf("%d %d",&n,&m);
        printf("%lld\n",c[n][m]*f[m]);
    }
    return 0;
}
