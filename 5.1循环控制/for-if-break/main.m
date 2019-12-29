//
//  main.m
//  5.1循环控制/2/for-if-break
//
//  Created by 张亮 on 2019/8/29.
//  Copyright © 2019 张亮. All rights reserved.
//
                                          //判断一个数是否是素数
                                          //输入一个非素数以查看for-if-break和for-if-continue的区别
#include <stdio.h>
 
int main()
{
    int x,i,n;
    int isPrime=1;
    printf("请输入一个数:");
    scanf("%d",&x);
    for ( i=2; i<x; i++ )
    {
        n=i-1;
        printf("for循环运行了%d次。\n",n);
        if ( x % i == 0 )
        {
            isPrime = 0;                      //如果if条件成立，令isPrime = 0
            break;                            //并立即跳出for循环（break），跳过剩余代码（for循环中的），直接结束for循环，来到29行。
        }
        printf("此次for循环完整结束！！\n");      //只有if不成立时，没有break跳出循环，则这个for循环完整运行了
    }
    if ( isPrime == 1 ) {
        printf("%d是素数！\n",x);
    } else {
        printf("%d不是素数！\n",x);
    }
    
                                                //  >>>只能控制所在循环的跳出/继续<<<
    
    isPrime=1;
    printf("请再次输入一个数:");
    scanf("%d",&x);
    for ( i=2; i<x; i++ )
    {
        n=i-1;
        printf("for循环运行了%d次。\n",n);
        if ( x % i == 0 )
        {
            isPrime = 0;                       //如果if条件成立，令isPrime = 0
            continue;                          //并立即继续for循环（continue），跳过剩下的代码（for循环中的），返回40行。
        }
        printf("此次for循环完整结束！！\n");      //只有if不成立时，没有continue返回循环，则这个for循环才完整运行了
    }
    if ( isPrime == 1 ) {
        printf("%d是素数！\n",x);
    } else {
        printf("%d不是素数！\n",x);
    }
    return 0;
}
