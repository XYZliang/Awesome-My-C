//
//  main.c
//  3.1判断/2/找钱plus
//
//  Created by 张亮 on 2019/8/18.
//  Copyright © 2019 张亮. All rights reserved.
//

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
    
    if(change<0)       //若该条件下（if/else）仅有一句代码，则{}可以忽略不写，如此处的if可不用{} （尽量用）<<<<<<<<<<<<<
    {
        printf("付款金额不够，还需付款%f元。\n",-change);
    }
    
    else
    {
        printf("欢迎光临！本次找您%f元。\n", change);
        printf("本次商品均价为%f元。\n",averages);
        printf("$$¥¥ 欢迎下次光临！¥¥$$\n");
    }
    
    return 0;
}
