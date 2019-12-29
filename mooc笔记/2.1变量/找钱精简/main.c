//
//  main.c
//  2.1变量/3/找钱精简
//
//  Created by 张亮 on 2019/8/12.
//  Copyright © 2019 张亮. All rights reserved.
//scanf

#include <stdio.h>
int main()
{
    int price1 = 0;
    int money1 = 0;
    
    printf("请输入第一位客人收款金额和商品价格 (元) 用空格隔开：");
    scanf("%d %d",&money1,&price1);
    

    int change1 = money1 - price1;
    printf("欢迎光临！本次找您%d元。\n", change1);
    
    int price2 = 0;
    int money2 = 0;
    
    printf("请输入第二问客人收款金额和商品价格 (元) 用逗号隔开：");
    scanf("%d,%d",&money2,&price2);
    
    
    int change2 = money2 - price2;
    printf("欢迎光临！本次找您%d元。\n", change2);
    return 0;
}
