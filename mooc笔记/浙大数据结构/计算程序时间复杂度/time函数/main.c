//
//  main.c
//  time函数
//
//  Created by 张亮 on 2020/1/8.
//  Copyright © 2020 张亮. All rights reserved.
//

//#include <stdio.h>
//#include <time.h>
//int main()
//   time_t t1, t2; //分别声明两种time()使用方式的赋值对象,只能精确到秒,适合耗时长的大程序
//
//    t1=time(0);t1=time(NULL); //第一种使用方式 将空指针传递给time()函数，并将time()返回值赋给变量t1
//    time(&t2); //第二种使用方式 将变量t2的地址作为实参传递给time()函数，函数自动把结果传递给t2，不需要额外的赋值语句。
//
//    printf("t1=%ld\n",t1);
//    printf("t2=%ld",t2);
//
//
//  return(0);
//}





//比较多项式的普通算法和秦九韶算法
#include <math.h>
#define MAXN 1000000        /* 多项式最大项数，即多项式阶数 + 1 */
#define TIME 1000           /* 算法运行的次数 */
#include <stdio.h>
#include <time.h>
double duration;
void testFunc(double a[], int m);
double f1(int n, double a[], double x);
double f2(int n, double a[], double x);
time_t t1, t2;

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
    t1=time(0);
    for(int i=1;i<=TIME;i++)
        m == 0 ? f1(MAXN - 1, a, 1.1) : f2(MAXN - 1, a, 1.1);
    t2=time(0);
    printf("1000遍算法%d用时%lds\n", m+1,(t2 - t1));
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
