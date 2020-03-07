//
//  1.hpp
//  鸡兔同笼
//
//  Created by 张亮 on 2020/2/16.
//  Copyright © 2020 张亮. All rights reserved.
//

#ifndef _____hpp
#define _____hpp

#include <iostream>

using namespace std;

void 一元方程法(int head,int jio);//兔为未知数X
void 二元方程法(int head,int jio);
void 抬脚法(int head,int jio);//鸡兔各抬起两只jio

extern int chicken,rabbit;
extern clock_t start,stop;

#define cycletimes 100000000

#endif
