//
//  main.m
//  4.1循环/1/ while - do while
//
//  Created by 张亮 on 2019/8/27.
//  Copyright © 2019 张亮. All rights reserved.


//          计算一个输的位数

#include <stdio.h>

int main()
{
    int n,a,b;
    printf("请输入一个数字:");
    scanf("%d",&a);
    
    n=0;
    n++;
    b=a;
    a/=10;
    
    while(a>0)          //while函数，一进入程序便进行判断，成立则执行25-28行代码，执行完又跳回24行
    {
        n++;
        a/=10;
    }
    
    printf("while函数法输出：%d有%d位数\n",b,n);
    
    ///////////////////////////////////////////////////////////////////////////////////////////////
    
    printf("请再次输入一个数字:");
    scanf("%d",&a);
    
    n=0;
    n++;
    b=a;
   
    
    do                //do-while函数，先执行一遍，再进行判断，符合则跳回43-46行执行
    {
        n++;
        a/=10;
    }
    while(a>0);
    
    
    printf("do-while函数法输出：%d有%d位数\n",b,n);
    
    return 0;
}

