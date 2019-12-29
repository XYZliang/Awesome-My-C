//
//  main.m
//  5.1循环控制/1/For循环
//
//  Created by 张亮 on 2019/8/28.
//  Copyright © 2019 张亮. All rights reserved.
//
//
//                  计算一个数的阶乘
//
#include <stdio.h>

int main()
{
    int a,b,n,sum;
    printf("请输入一个数:");
    scanf("%d",&a);
    
    n=1;
    sum=1;
    while(n<=a)             //while循环
    {
        sum*=n;
        n++;
    }
    printf("while循环输出：%d!=%d\n",a,sum);
    
    
    printf("请再次输入一个数:");
    scanf("%d",&a);
    sum=1;
    
    for(n=1;n<=a;n++)        //for循环   for(循环变量赋初值; 循环条件; 循环变量增量),可以留空
    {
        sum*=n;             //第一种方法,从1乘到a
    }
    printf("第一种for循环输出：%d!=%d\n",a,sum);
    
    printf("^_^请再再次输入一个数:");
    scanf("%d",&a);
    sum=1;
    b=a;
    for(a=a;a>1;a--)        //第二种方法，从a乘到1，且可以简写为 for(;a>1;a--)
    {
        sum*=a;
    }
    printf("第二种for循环输出：%d!=%d\n",b,sum);
    
    return 0;
}
                            //对于for循环中语句的一般形式，就是如下的while循环形式：
                            //表达式1;
                            //while(表达式2){
                            //语句
                            //    表达式3;
                            //}


                            //如果有固定的次数，用for循环
                            //如果必须执行一次，用do while
                            //其他情况一般while

                            //5.2循环控制
                            //for可搭配if-break/continue
                            //当if条件满足时，执行if下的语句并直接跳出循环(break)
                            //当if条件满足时，执行完if里的语句后直接忽略continue后面的语句，返回for循环
                            //只能控制所在循环的跳出/继续

                            //5.2.2!!!!!!!!!!!!!!!!
