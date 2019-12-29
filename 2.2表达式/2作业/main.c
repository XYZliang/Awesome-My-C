//
//  main.c
//  2作业
//
//  Created by 张亮 on 2019/8/15.
//  Copyright © 2019 张亮. All rights reserved.
//
#include <stdio.h>

int main()
{
    int a,b,c,d;
    
    printf("请输入一个三位数:\n");
    scanf("%d",&a);
    
    b=a/10;
    b=b%10;
    
    c=a%10;
    
    d=a%100;
    d=(a-d)/100;
    
    a=100*c+10*b+d;
    printf("%d\n",a);
    
    return 0;
}
