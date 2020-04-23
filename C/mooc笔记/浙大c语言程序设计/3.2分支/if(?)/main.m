//
//  main.m
//  3.2分支/1.1/if (?)
//
//  Created by 张亮 on 2019/8/24.
//  Copyright © 2019 张亮. All rights reserved.
//

#include <stdio.h>

int main()
{
    int a=5,b=6;
    if (a=b)                        //警告>>>>>>>>
                                    //b先把自己的值赋值给变量a
                                    //再if（6）进行判断
                                    //if（6）>>>if（！=0）>>>if(成立)>>>执行if
        printf("if输出%d\n",a);

    else
        printf("else输出%d\n",b);
}
                                    //   Using the result of an assignment as a condition without parentheses
                                    //                              ^^             ^^                  ^^
                                    //                          分配，分派，任务    条件，状态             括号
                                    //使用赋值的结果作为没有括号的条件。
                                    //这是一个警告,就是说你利用一个赋值表达式的值作为判断条件。
                                    //一般是本想用==的,却错用了=,由于这是初学者常犯的错误,所以编译器给出了警告。
                                    //这里只是作为演示，指出if（?）的一种用法。
                                    //同时也指出=赋值号与==等号混淆的一种错误。
