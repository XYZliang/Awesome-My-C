/*
实践题二
自定义一个简单的时间类 TimeType，它具有数据成员 h、m、s，用来表示当前时间的时、 分、秒。而后设计该类欲实现（完成）的功能，进而设计出相应的类成员函数。

例如，下面给出的“雏形”可用来实现对时分秒的增加、判断两个时间是否相等以及对 时间的输出等操作。请完成其各个类成员函数，并编制主函数，说明 TimeType 类对象，对定 义的各成员函数进行调用，以验证它们的正确性。
class TimeType
{ //自定义的时间类 TimeType
    int h,m,s; //私有数据成员，表示当前时间的时、分、秒
public:
    TimeType(int h0=0, int m0=0, int s0=0); //构造函数，设定时、分、秒；并设置参数默认值
    void incrementSec(int sec); //增加若干秒，sec>0
    void incrementMin(int min); //增加若干分，min>0
    void incrementHou(int hrs); //增加若干小时，hrs>0
    bool equal(TimeType t2); //判断二时间是否相等 void printTime(); //屏幕输出时间对象的有关数据（时、分、秒）
};

【实验目的】
设计并编制自定义类 TimeType 来对“时间数据”进行所设定的各种处理；并编制主函数， 通过类对象对所定义的成员函数进行调用。

【实现方法】
1．通过自定义类 TimeType，来对“时间数据”进行各种所指定的处理。一个“时间数 据”可通过“时、分、秒”来唯一确定，从而为该类设立私有数据成员 h、m、s 来表示这一数据。由于要对“时间”进行多种不同的处理，进而设立不同的类成员函数来实现其各自的设 定功能。

2．对时间进行增加的 incrementSec、incrementMin、incrementHou 成员函数中，要注 意所谓的 “进位”处理：秒数超过 60 要“进位”到分；超过 60 分则要“进位”到时；而超 过 24 时后要“甩掉”24 以上的部分等。
例如，秒数超过 60 则“进位”到分，可通过如下语句来实现：
if(s>=60) { m+=s/60; s=s%60; }
判断超过 24 时而后“甩掉”24 以上的部分，则可使用语句： if(h>=24) h=h%24;

3．编制类似于如下样式的主函数，说明 TimeType 类对象，并通过类对象对 TimeType 类的各个成员函数进行调用，以验证每一成员函数的正确性。
 void main()
 {
    TimeType t1(11, 48, 59), t2(11, 59, 48), t3;
    cout<<"t1="; t1.printTime();
    cout<<"t2="; t2.printTime();
    cout<<"t3="; t3.printTime();
    if(t1.equal(t2))
        cout<<"t1==t2"<<endl;
    else
        cout<<"t1!=t2"<<endl;
    t1.incrementMin(30);
    cout<<"'t1.incrementMin(30);' => ";
    cout<<"t1=";
    ...
    t1.printTime();
}

程序执行后，屏幕显示结果样式可设计为： t1=11:48:59 t2=11:59:48 t3=0:0:0 t1!=t2 't1.incrementMin(30);' => t1=12:18:59 ...

【编程提示】

可进一步思考对该类增加你所考虑到的其他功能，如，对时间进行输入，计算二时间的 间隔秒数，对两个时间进行其他五种比较运算，一次就可以增加若干小时、若干分、若干秒， 以 Am（上午）或 Pm（下午）的格式在屏幕上输出时间对象等，而后逐步增加相应的成员函数 来实现这些功能，最终可将 TimeType 设计并实现为一个简洁实用并具有多种所需功能的自定 义类。
*/

#include "TimeClass.h"
#include <iostream>

int main()
{
    TimeType test1(3,0,0);
    test1.setTimingShutdown(0);
    return 0;
}
