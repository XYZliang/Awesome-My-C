//
//  main.m
//  5.3循环应用
//
//  Created by 张亮 on 2019/9/6.
//  Copyright © 2019 张亮. All rights reserved.
//


                                //计算数列A(n)=[(-1)^n]*(1/n) {n>=1}的前n项和S n
                                //如S(4)=1+1/2-1/3+1/4
#include <stdio.h>
 
int main()
{
    int n;
    int i;
    double Sn=0.0;              //Sn输出可能为小数，故定义Sn为double类型
    int sign = 1;               //用来指示n项的正负符号，第一项为正
    printf("对于A(n)=[(-1)^n]*(1/n)，现求其前n项g和S(n)。\n请输入n值：");
    scanf("%d", &n);
    for ( i=1; i<=n; i++ )
    {
        Sn += 1.0*sign/i;       //若为1*sign，整数除以整数，结果仍为整数，显然有问题，故改成1.0*sign
        sign = -sign;           //改变符使得奇数项为正，偶数项为负
    }
    printf("S(n)=%f\n", Sn);
 
    return 0;
}
