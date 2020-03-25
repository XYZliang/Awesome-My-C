//
//  抬脚法.cpp
//  鸡兔同笼
//
//  Created by 张亮 on 2020/2/16.
//  Copyright © 2020 张亮. All rights reserved.
//
#include "1.hpp"
void 抬脚法(int head,int jio)
{
    start = clock();
    for (int i=1; i<=cycletimes;i++)
    {
        rabbit=(jio-2*head)/2;
        chicken=head-rabbit;
    }
    stop = clock();
    cout <<  __FUNCTION__ << "运行" << cycletimes << "次花费" << (stop-start)/ (1.0*CLOCKS_PER_SEC) << "秒" << endl;
}
