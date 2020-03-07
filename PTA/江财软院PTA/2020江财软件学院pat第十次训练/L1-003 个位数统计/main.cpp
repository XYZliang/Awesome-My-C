#include<stdio.h>
    int main() {
    int n,i,mask=1,copy;
    scanf("%d",&n);
    if(n<0) {
        n=-n;
        printf("fu");
    }
    copy=n;
    while(copy>9) {
        mask*=10;
        copy/=10;
    }
    //while循环算出位数，10代表两位
    for (;mask>0;) {
        i=n/mask;
        switch (i) {
            case 0:printf(" ling");
            break;
            case 1:printf(" yi");
            break;
            case 2:printf(" er");
            break;
            case 3:printf(" san");
            break;
            case 4:printf(" si");
            break;
            case 5:printf(" wu");
            break;
            case 6:printf(" liu");
            break;
            case 7:printf(" qi");
            break;
            case 8:printf(" ba");
            break;
            default:printf(" jiu");
        }
        n=n%mask;
        mask=mask/10;
    }
        return 0;
}
