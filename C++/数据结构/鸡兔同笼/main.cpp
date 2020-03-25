//
//  main.cpp
//  鸡兔同笼
//
//  Created by 张亮 on 2020/2/16.
//  Copyright © 2020 张亮. All rights reserved.
//

#include "1.hpp"
#include <time.h>

int chicken,rabbit;
clock_t start, stop;

int main()
{
    int head,jio;
    cout << "请输入头和腿的数目,以空格分隔,回车结束" << endl;
    cin >> head >> jio;
    
    一元方程法(head, jio);
    二元方程法(head, jio);
    抬脚法(head, jio);
}
