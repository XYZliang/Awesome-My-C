//
//  main.c
//  2.1变量/4/找钱 带小数版
//
//  Created by 张亮 on 2019/8/12.
//  Copyright © 2019 张亮. All rights reserved.
//在c中，整数与整数的计算结果也只能是整数
//浮点数-带小数点的数
//double-双精度浮点数-printf %f-scanf %lf

#include <stdio.h>
int main()
{
    double price = 0;
    double money = 0;
    double number = 0;
    
    printf("请输入收款金额：");
    scanf("%lf", &money);
    
    printf("请输入商品价格：");
    scanf("%lf", &price);
    
    printf("请输入商品件数：");
    scanf("%lf", &number);
    
    double change = money - price;
    double averages= price/number;
    
    printf("欢迎光临！本次找您%f元。\n", change);
    printf("本次商品均价为%f元。\n",averages);
    
    return 0;
}
