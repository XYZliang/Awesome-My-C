//
//  main.m
//  5.2循环控制/4/离开多重循环
//
//  Created by 张亮 on 2019/9/1.
//  Copyright © 2019 张亮. All rights reserved.
//
#include <stdio.h>

int main()
{
    int x;
    int one, two, five;
    printf("你想用零钱凑成多少元钱:");
    scanf("%d", &x);
    
    
    printf("先输出全部结果：\n");
    int n=1;
    for ( one = 1; one < x*10; one++ )
    {
        for ( two = 1; two < x*10/2; two++ )
        {
            for ( five = 1; five < x*10/5; five++ )
            {
                if ( one + two*2 + five*5 == x*10 )
                {
                    printf("方法%d：可以用%d个1角加%d个2角加%d个5角得到%d元\n",n,one, two, five, x);
                    n++;
                    break;                          //只离开此if循环
                }
            }
        }
    }
    
    
    
    int exit = 0;                                   //定义一个变量exit为0（否）
    printf("\n\n离开多重循环的方案一所输出的结果：\n");
    printf("当匹配到第一个结果就直接跳出\n");
    for ( one = 1; one < x*10; one++ )
    {
        for ( two = 1; two < x*10/2; two++ )
        {
            for ( five = 1; five < x*10/5; five++ )
            {
                if ( one + two*2 + five*5 == x*10 )
                {
                    printf("可以用%d个1角加%d个2角加%d个5角得到%d元\n",
                           one, two, five, x);
                    exit = 1;
                    break;                          //当得到第一个符合题意的结果时直接输出并将exit赋值为1（是）,跳出（break）for循环（43），并结束if
                }
            }
            if ( exit == 1 ) break;                 //监测到exit为1，跳出此for循环（41）
        }
        if ( exit == 1 ) break;                     //监测到exit为1，跳出此for循环（39）
    }
    
    
    
    printf("\n\n离开多重循环的方案二所输出的结果：\n");
    printf("同样当匹配到第一个结果就直接跳出\n");
    for ( one = 1; one < x*10; one++ )
    {
        for ( two = 1; two < x*10/2; two++ )
        {
            for ( five = 1; five < x*10/5; five++ )
            {
                if ( one + two*2 + five*5 == x*10 )
                {
                    printf("3可以用%d个1角加%d个2角加%d个5角得到%d元\n",
                           one, two, five, x);
                    goto out;                       //当得到第一个符合题意的结果时直接输出并直接前往out（76）
                }
            }
        }
    }                                               //goto语句通常与条件语句配合使用。可用来实现条件转移， 构成循环，跳出循环体等功能。
   out:
 return 0;                                           //但是，在结构化程序设计中一般不主张使用goto语句，
}                                                   //以免造成程序流程的混乱，使理解和调试程序都产生困难。
    
    
                                                    //PS::::::goto此方法尽量少用！！！！最好只用在离开循环之中！！！
                                                    // 且out（out字符可以自定义）最好在goto out后面！！！
                                                    //（其实out可以在goto out前，goto可随意跳转)
                                                    //但是，在结构化程序设计中一般不主张使用goto语句，
                                                    //以免造成程序流程的混乱，使理解和调试程序都产生困难。
    

