//
//  main.m
//  5.1循环控制/3/循环的嵌套
//
//  Created by 张亮 on 2019/9/1.
//  Copyright © 2019 张亮. All rights reserved.
//
//
//
//
//                             >>>>>>>>输出前50个素数<<<<<<<<
#include <stdio.h>
 
int main()
{
    int x;
    int cnt = 0;                     //设置一个变量记录素数的个数
 
    for(x=1;cnt<50;x++)
    {
        int i;
        int isPrime = 1;            //x是素数
        for ( i=2; i<x; i++ )
        {
            if ( x % i == 0 )       //如果x能被一个大于2的数整除
            {
                isPrime = 0;        //令该变量为0（否）
                break;              //并跳出此if
            }
        }
        if ( isPrime == 1 )         //如果该变量任是1（是）
        {
            cnt ++;                 //记录的素数自增一
            printf("%d\t", x);      //并输出此素数，  自动调整（\t）「后面会讲」
            if ( cnt %5 == 0 )      //每隔5个素数时
            {
                printf("\n");       //换行
            }
        }
    }
    return 0;
}
