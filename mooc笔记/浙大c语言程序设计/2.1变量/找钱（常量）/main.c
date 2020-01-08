//
//  main.c
//  2.1变量/2/找钱（常量）
//
//  Created by 张亮 on 2019/8/12.
//  Copyright © 2019 张亮. All rights reserved.
//const

#include <stdio.h>
int main()
{
    int const PAYMENT= 100;  //const(常量，常数) int const定义常量，不可修改,仅可读,通常大写以提醒。
    int price = 0;
    
    printf("请输入商品价格（元）：");
    scanf("%d", &price);
    
    int change = PAYMENT - price;
    printf("欢迎光临！您已付款%d元，本次找您%d元。\n", PAYMENT,change);
    return 0;
}
