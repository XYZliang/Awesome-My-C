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


#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

#if defined (__APPLE__)||defined (__LIUNX__)//如果在mac/liunx下
#include <sys/time.h>
#endif

#ifndef __APPLE__
    #ifndef __LIUNX__//非macos，liunx，默认为windwos
    #include <time.h>
    #include <windows.h>
    #pragma warning( disable : 4996 )
    #endif
#endif

//本次实验测试的数据
#define time1 0,0,0//测试样例1：0时0分0秒
#define time2 8,9,10//测试样例2：8时9分10秒
#define time3 8,9,10,"PM"//测试样例3：下午8时9分10秒
#define time4 20,9,10//测试样例4：20时9分10秒
#define time5 0,0,0//测试样例5：24时0分0秒
char timenow[8];//测试样例6:当前时间

class TimeType//自定义时间类TimeType
{
private://私有数据成员.
    int hour,minute,second;//表示当前时间的时、分、秒
    bool fullFormat;//布尔类型。ture为24小时格式，flase为12小时格式，用于十二小时制时间
    string APm;//保存上下午数据，用于十二小时制时间。
public://共有数据成员,类的对外接口.
    TimeType(int h=0,int m=0,int s=0,string apm=" "){hour=h;minute=m;second=s;APm=apm;apm==" "?fullFormat=true:fullFormat=false;};//初始化，并设定默认值
    void display();//输出TimeType√
    int printf(int);//格式化为秒/分/时后输出/返回
    int isLegal(int);//判断时间格式是否合法，且是否输出提示√
    void correction();//对不合法数据进行修正√
    TimeType operator+(TimeType);//重载+运算符，使其能处理时间的加减法√
    TimeType operator-(TimeType);//计算两个时间之间的差值√
    TimeType conversion();//十二小时/二十四小时进制互相转化√
    TimeType getNowTime();//获取系统时间
    void setSystemTime();//将此时间设置为系统时间
};

//在类外定义成员函数
void TimeType::display()
{
    cout<<hour<<"时"<<minute<<"分"<<second<<"秒";
    !fullFormat?cout<<APm<<endl:cout<<endl;
}

int TimeType::printf(int model=0)
{
    correction();
    cout.setf(ios::fixed);
    switch (model)
    {
        case 0:cout<<second+60*minute+3600*hour<<"秒"<<endl;break;
        case 1:cout<<fixed<<setprecision(2)<<1.0*second/60+minute+hour*60<<"分钟"<<endl;break;
        case 2:cout<<fixed<<setprecision(2)<<1.0*second/3600+1.0*minute/60+hour<<"小时"<<endl;break;
        default:break;
    }
    return second+60*minute+3600*hour;
}

int TimeType::isLegal(int model=0)
{
    string wrong="数据不合法！";
    string right="数据合法！";
    if(hour<0)
        wrong+="时钟不能为负！";
    else if(hour>24)
        wrong+="时钟不能超过24！";
    if(minute<0)
        wrong+="分钟不能为负！";
    else if(minute>60)
        wrong+="分钟不能超过60！";
    if(second<0)
        wrong+="秒钟不能为负！";
    else if(second>60)
        wrong+="秒钟不能超过60！";
    if(wrong!="数据不合法！")
    {
        if (model==1)
        {
            int correction;
            wrong+="是否自动进行修正？是请输入0，其他为否：";
            cout<<wrong;
            cin>>correction;
            if(!correction)
            {
                TimeType::correction();
                cout<<"修正后的时间为：";
                TimeType::display();
                return 1;
            }
        }
        else
        {
            TimeType::correction();
            return 1;
        }
        return 0;
    }
    if (model==1)
        cout<<right<<endl;
    return 1;
}

void TimeType::correction()
{
    if(hour<0)
        hour+=24;
    else if(hour>24)
        hour-=24;
    if(minute<0)
    {
        minute+=60;
        hour--;
    }
    else if(minute>60)
    {
        minute-=60;
        hour++;
    }
    if(second<0)
    {
        second+=60;
        minute--;
    }
    else if(second>60)
    {
        second-=60;
        minute++;
    }
    isLegal();
}

TimeType TimeType::operator+(TimeType plus)
{
    TimeType sum;
    sum.hour=hour+plus.hour;
    sum.minute=minute+plus.minute;
    sum.second=second+plus.second;
    sum.correction();
    return sum;
}

TimeType TimeType::operator-(TimeType sub)
{
    TimeType delta;
    delta.hour=hour-sub.hour;
    delta.minute=minute-sub.minute;
    delta.second=second-sub.second;
    delta.correction();
    return delta;
}

TimeType TimeType::conversion()
{
    TimeType conversion(hour,minute,second);
    correction();
    if(fullFormat)
    {
        if(hour<12)
            conversion.APm="AM";
        else if(hour==12)
            conversion.APm="AM";
        else if(hour==24)
        {
            conversion.hour-=12;
            conversion.APm="AM";
        }
        else
        {
            conversion.hour-=12;
            conversion.APm="PM";
        }
        conversion.fullFormat=false;
    }
    else
    {
        if(APm=="PM")
            conversion.hour+=12;
        conversion.fullFormat=true;
    }
    return conversion;
}

TimeType TimeType::getNowTime()
{
    TimeType nowTime;
    struct tm* ptr;
    time_t lt;
    lt=time(NULL);
    ptr=localtime(&lt);
    nowTime.hour = ptr->tm_hour;
    nowTime.minute = ptr->tm_min;
    nowTime.second = ptr->tm_sec;
    return nowTime;
}

void TimeType::setSystemTime()
{
#if defined (__APPLE__)||defined (__LIUNX__)
    cout<<"当前系统为liunx/macos,系统时间为";
    getNowTime().display();
    timeval p;
    gettimeofday(&p, NULL);
    p.tv_sec = p.tv_sec + printf(4);
    if (!settimeofday(&p, NULL))
        cout << "修改成功！请关闭自动同步时间，否则时间会恢复。"<<endl;
    else
        cout << "修改失败！缺少root权限，需要以root权限(sudo命令)运行。"<<endl;
#endif
#ifndef __APPLE__
#ifndef __LIUNX__
    cout << "当前系统为windows,系统时间为";
    getNowTime().display();
    SYSTEMTIME system_time;
    GetLocalTime(&system_time);
    system_time.wSecond = system_time.wSecond+second;
    system_time.wMinute = system_time.wMinute+minute;
    system_time.wHour = system_time.wHour+hour;
    if (SetLocalTime(&system_time))
        cout << "修改成功！请关闭自动同步时间，否则时间会恢复。"<<endl;
    else
        cout << "修改失败！缺少管理员权限。请右键编译生成的exe文件以管理员身份运行。"<<endl;
#endif
#endif
    cout<<"当前系统时间为：";
    getNowTime().display();
#ifndef __APPLE__
#ifndef __LIUNX__
    system("pause");
#endif
#endif
}
int main()
{
    TimeType test1(3,0,0);
    test1.setSystemTime();
}
