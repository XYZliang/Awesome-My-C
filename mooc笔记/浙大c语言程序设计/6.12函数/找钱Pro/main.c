//
//  main.c
//  找钱Pro
//
//  Created by 张亮 on 2019/10/26.
//  Copyright © 2019 张亮. All rights reserved.
//

#include <stdio.h>
int calculate(double price1,double money1,double number1)       //此处用来计算，并判断是否付款足够
{                                                               //（函数返回类型：数据类型int，double，void等）（函数名）（输入的变量1，变量2等等）
    int end;                                                    //每个函数独立，需要重新定义，与main函数的end不会重复
    double change1,averages1;
    change1 = money1 - price1;
    averages1= price1/number1;
    
    if(change1<0)
    {
        end=0;
    }
    
    else
    {
        printf("欢迎光临！本次找您%.2f元。\n", change1);
        printf("本次商品均价为%.2f元。\n",averages1);
        end=1;
    }
    return end;
}

void hello()
{
    printf("Hello！\n");
    return;                                                 //return不一定需要表达式来返回一个值。return退出函数。一个函数可以有多个return。
}

int main()
{
    int end;
    double price,number,money;
    
    hello();
    printf("请输入收款金额：");
    scanf("%lf", &money);
    
    printf("请输入商品价格：");
    scanf("%lf", &price);
    
    printf("请输入商品件数：");
    scanf("%lf", &number);
    
    end=calculate(price,money,number);
    
    switch(end)
        
    {
        case 0:
            printf("付款金额不够，还需付款。\n");
            break;
        case 1:
            printf("$$¥¥ 欢迎下次光临！¥¥$$\n");
            break;
    }
    
    return 0;
}


