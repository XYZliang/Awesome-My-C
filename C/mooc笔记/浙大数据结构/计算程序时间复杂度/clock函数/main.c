//
//  main.c
//  clock函数
//
//  Created by 张亮 on 2020/1/7.
//  Copyright © 2020 张亮. All rights reserved.
//

//#include<stdio.h>
//#include<time.h>
//
//clock_t    start,   stop;
//clock_t是clock()函数返回的变量类型,是一种数据类型,长整型,单位为时钟计时
//double   duration;
//记录被测函数运行时间，以秒为单位
//int main()
//{
//不在测试范围内的准备工作写在clock()调用之前
//start = clock();    开始计时
//**************      把被测函数加在这里
//stop = clock();     停止计时
//duration = ((double)(stop - start)) / CLK_TCK;  CLK_TCK是当前系统每秒的时钟计时个数,不同系统电脑可能不同
//计算运行时间                                     有的编译器是CLOCKS_PER_SEC
//其他不在测试范围的处理写在这里， 例如输出duration的值
//return 0;
//}

//clock()函数误差较大,clock调用在多核情况下会产生巨大误差。原因是clock的实现方式决定了它不适合多核cpu场景。
//Clock实现原理：
//clock tick：时钟计时单元（而不把它叫做时钟滴答次数），一个时钟计时单元的时间长短是由CPU控制的，一个clock tick不是CPU的一个时钟周期，而是C/C++的一个基本计时单位。
//clock函数：clock_t clock(); 这个函数返回从“开启这个程序进程”到“程序中调用clock（）函数”时之间的CPU时钟计时单元（clock tick）数，在MSDN中称之为挂钟时间（wal-clock）。
//Clock的实现是基于时钟计时单元的。问题出在cpu的时钟计时单元上。当采用多核cpu时，进程或线程调用clock，记录了当前核时钟。但在下次调用clock之前很可能发生cpu调度，进程或线程被调度到其他cpu上运行。这导致两次取得计时单元并不是同一个cpu的，产生计时错误。
//只能小程序用用


//比较多项式的普通算法和秦九韶算法
#include<stdio.h>
#include <time.h>
#include <math.h>
#define MAXN 1000000     /* 多项式最大项数，即多项式阶数 + 1 */

clock_t start, stop;
double duration;
void testFunc(double a[], int m);
double f1(int n, double a[], double x);
double f2(int n, double a[], double x);

int main()
{
    int i;
    double a[MAXN];     /*存储多项式的系数*/
    for (i = 0; i < MAXN; i++) a[i] = (double)i;

    for (i = 0; i < 2; i++)
        testFunc(a, i);

    return 0;
}

void testFunc(double a[], int m)
{
    start = clock();
    m == 0 ? f1(MAXN - 1, a, 1.1) : f2(MAXN - 1, a, 1.1);
    stop = clock();
    duration = (double)(stop - start) / CLOCKS_PER_SEC;
    printf("ticks%d = %f\n", m, (double)(stop - start));
    printf("duration = %6.2e\n", duration);
}

double f1(int n, double a[], double x)
{
    int i;
    double p = a[0];
    for (i = 1; i <= n; i++)
        p += (a[i] * pow(x, i));
    return p;
}

double f2(int n, double a[], double x)
{
    int i;
    double p = a[n];
    for (i = n; i > 0; i--)
        p = a[i - 1] + x * p;
    return p;
}
//秦九韶算法所用时间比普通算法小一个数量级
