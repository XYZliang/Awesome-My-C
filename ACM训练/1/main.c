//
//  main.c
//  1
//
//  Created by 张亮 on 2020/1/7.
//  Copyright © 2020 张亮. All rights reserved.
//

#include <stdio.h>
void exchange(char a[3])
{
    char n;
    if(a[0]>a[1]) {n=a[0];a[0]=a[1];a[1]=n;}
    if(a[0]>a[2]) {n=a[0];a[0]=a[2];a[2]=n;}
    if(a[1]>a[2]) {n=a[1];a[1]=a[2];a[2]=n;}
}
int main()
{
    char a[3],b;
    while(scanf("%c%c%c\n",&a[0],&a[1],&a[2]) != EOF)
    {
        exchange(a);
        printf("%c %c %c\n",a[0],a[1],a[2]);
    }
}
