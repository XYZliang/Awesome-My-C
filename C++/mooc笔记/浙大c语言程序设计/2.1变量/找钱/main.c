//
//  main.c
//  2.1变量/1/找钱
//
//  Created by 张亮 on 2019/8/11.
//  Copyright © 2019 张亮. All rights reserved.
//int


#include <stdio.h>
int main()
{
    int price = 0;
    int money = 0;
    
    printf("请输入收款金额 (元)：");
    scanf("%d", &money);

    printf("请输入商品价格（元）：");
    scanf("%d", &price);
    
    int change = money - price;
    printf("欢迎光临！本次找您%d元。\n", change);
    return 0;
}
