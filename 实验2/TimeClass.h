#ifndef TimeClass_h //确保只被定义一次
#define TimeClass_h

#include <iostream>
#include <iomanip> //保留小数
using namespace std;

#if defined(__APPLE__) || defined(__LIUNX__) //如果在macos/liunx下，则编译，否则忽略
#include <sys/time.h>                        //使用liunx下的日期时间头文件，包含time.h，用于获取、修改liunx系统时间
#endif

#ifndef __APPLE__
#ifndef __LIUNX__    //非macos，liunx，默认为windwos，则编译，否则忽略
#include <time.h>    //使用ISO C99 标准日期时间头文件，用于获取系统时间
#include <windows.h> //用于修改windows系统时间
#include <string>   //用于字符串
#pragma warning(disable : 4996)
//vs过于严格，强制其允许使用跨平台的localtime函数，而不是他自己的localtime_s函数，省得又需要判断系统
#endif
#endif

class TimeType //自定义时间类TimeType
{
private:                      //私有数据成员
    int hour, minute, second; //表示当前时间的时、分、秒
    bool fullFormat;          //布尔类型。ture为24小时格式，flase为12小时格式，用于十二小时制时间
    string APm;               //保存上下午数据，用于十二小时制时间。
public:                       //共有数据成员,类的对外接口.
    TimeType(int h = 0, int m = 0, int s = 0, string apm = " ")
    {
        hour = h;
        minute = m;
        second = s;
        APm = apm;
        apm == " " ? fullFormat = true : fullFormat = false;
    };                            //初始化，并设定默认值
    void display();               //输出TimeType
    int printf(int);              //格式化为秒/分/时后输出/返回
    int isLegal(int);             //判断时间格式是否合法，且是否输出提示
    void correction();            //对不合法数据进行修正
    TimeType operator+(TimeType); //重载+运算符，使其能处理时间的加法
    TimeType operator-(TimeType); //计算两个时间之间的差值
    TimeType conversion();        //十二小时/二十四小时进制互相转化
    TimeType getNowTime();        //获取系统时间
    //以下函数需要在控制台中运行，且需要root权限
    void increaseSystemTime();   //将此时间增加到系统时间
    void setTimingShutdown(int); //将此时间设置为系统定时关机/重启
};

//在类外定义成员函数
void TimeType::display()
{
    cout << hour << "时" << minute << "分" << second << "秒";
    !fullFormat ? cout << APm << endl : cout << endl; //若为十二进制时间则输出AM/PM
}

int TimeType::printf(int model = 0) //model=1转化为秒输出，2转为分输出，3转为小时输出。其他返回秒数
{
    correction();          //先修正数据
    cout.setf(ios::fixed); //用于保留两位小数后的0
    switch (model)
    {
    case 0:
        cout << second + 60 * minute + 3600 * hour << "秒" << endl;
        break; //转换为秒
    case 1:
        cout << fixed << setprecision(2) << 1.0 * second / 60 + minute + hour * 60 << "分钟" << endl;
        break; //转换为分
    case 2:
        cout << fixed << setprecision(2) << 1.0 * second / 3600 + 1.0 * minute / 60 + hour << "小时" << endl;
        break; //转换为时
    default:
        break;
    }
    return second + 60 * minute + 3600 * hour; //返回秒钟，方便其他函数调用
}

int TimeType::isLegal(int model = 0) //model=0（默认），只检查是否合法。1检查是否合法，并显示提示内容。
{
    string wrong = "数据不合法！";
    string right = "数据合法！";
    if (hour < 0)
        wrong += "时钟不能为负！"; //+=合并错误代码方便输出
    else if (hour > 24)
        wrong += "时钟不能超过24！";
    if (minute < 0)
        wrong += "分钟不能为负！";
    else if (minute > 60)
        wrong += "分钟不能超过60！";
    if (second < 0)
        wrong += "秒钟不能为负！";
    else if (second > 60)
        wrong += "秒钟不能超过60！";
    if (wrong != "数据不合法！")
    {
        if (model == 1)
        {
            int correction;
            wrong += "是否自动进行修正？是请输入0，其他为否：";
            cout << wrong;
            cin >> correction;
            if (!correction)
            {
                TimeType::correction(); //修正数据
                cout << "修正后的时间为：";
                TimeType::display(); //显示修正后的数据
                return 1;
            }
        }
        else
        {
            TimeType::correction(); //自动修正
            return 1;
        }
        return 0;
    }
    if (model == 1)
        cout << right << endl;
    return 1;
}

void TimeType::correction()
{
    if (hour < 0) //开始修正
        hour += 24;
    else if (hour > 24)
        hour -= 24;
    if (minute < 0)
    {
        minute += 60;
        hour--;
    }
    else if (minute > 60)
    {
        minute -= 60;
        hour++;
    }
    if (second < 0)
    {
        second += 60;
        minute--;
    }
    else if (second > 60)
    {
        second -= 60;
        minute++;
    }
    isLegal(); //再次判断是否合法，否则递归继续修正，直到合法再退出。
}

TimeType TimeType::operator+(TimeType plus) //直接将对应变量相加，最后修正即可
{
    TimeType sum;
    sum.hour = hour + plus.hour;
    sum.minute = minute + plus.minute;
    sum.second = second + plus.second;
    sum.correction();
    return sum;
}

TimeType TimeType::operator-(TimeType sub)
{
    TimeType delta;
    delta.hour = hour - sub.hour;
    delta.minute = minute - sub.minute;
    delta.second = second - sub.second;
    delta.correction();
    return delta;
}

TimeType TimeType::conversion()
{
    TimeType conversion(hour, minute, second); //建立新的对象来存储，防止原数据被覆盖
    correction();                              //先修正
    if (fullFormat)                            //如果是24进制
    {
        if (hour < 12)
            conversion.APm = "AM";
        else if (hour == 12)
            conversion.APm = "AM";
        else if (hour == 24)
        {
            conversion.hour -= 12;
            conversion.APm = "AM";
        }
        else
        {
            conversion.hour -= 12;
            conversion.APm = "PM";
        }
        conversion.fullFormat = false;
    }
    else //如果是12进制
    {
        if (APm == "PM")
            conversion.hour += 12;
        conversion.fullFormat = true;
    }
    return conversion;
}

TimeType TimeType::getNowTime()
{
    TimeType nowTime;
    struct tm *ptr;
    time_t lt;
    lt = time(NULL);
    ptr = localtime(&lt); //获取系统时间
    nowTime.hour = ptr->tm_hour;
    nowTime.minute = ptr->tm_min;
    nowTime.second = ptr->tm_sec;
    return nowTime;
}

void TimeType::increaseSystemTime()
{
#if defined(__APPLE__) || defined(__LIUNX__) //如果是macos/liunx系统
    correction();
    cout << "\033[32m当前系统为liunx/macos,系统时间为\033[0m"; //\033[32m为控制台绿色文字代码，\033[0m为重置文字格式
    getNowTime().display();                                    //获取当前时间
    timeval p;
    gettimeofday(&p, NULL);
    p.tv_sec = p.tv_sec + printf(4); //在当日的总秒数上加上需要增加的总秒数
    //因为不同系统对时间的处理不同，无法直接指定时间，比如，在macos下0秒为8:00，既东八区的时间；在liunx下为正常的00:00
    if (!settimeofday(&p, NULL))                                                         //设定时间（需要权限）
        cout << "\033[31m修改成功！请关闭自动同步时间，否则时间会恢复。\033[0m" << endl; //\033[31m为控制台红色文字代码
    else
        cout << "\033[31m修改失败！缺少root权限，需要在控制台以root权限(sudo命令)运行。\033[0m" << endl;
#endif

#ifndef __APPLE__
#ifndef __LIUNX__ //windows
    correction();
    cout << "\033[32m当前系统为windows,系统时间为";
    getNowTime().display();
    SYSTEMTIME system_time;
    GetLocalTime(&system_time);                         //获取系统时间
    system_time.wSecond = system_time.wSecond + second; //分别加上时分秒
    system_time.wMinute = system_time.wMinute + minute;
    system_time.wHour = system_time.wHour + hour;
    if (SetLocalTime(&system_time)) //设定时间（需要权限）
        cout << "\033[31m修改成功！请关闭自动同步时间，否则时间会恢复。\033[0m" << endl;
    else
        cout << "\033[31m修改失败！缺少管理员权限。请右键编译生成的exe文件以管理员身份运行。\033[0m" << endl;
#endif
#endif
    cout << "\033[31m当前系统时间为：\033[0m"; //输出修改后的结果
#ifndef __APPLE__
#ifndef __LIUNX__
    system("pause");
#endif
#endif
    getNowTime().display();
}

void get(int n, string& m) //配合获取控制台的指令
{
    if (n < 10)
    {
        m=m+"0"+to_string(n);
    }
    else
    {
        m=m+to_string(n);
    }
    return;
}

void TimeType::setTimingShutdown(int model = 0) //model0为定时关机，1为定时重启
{
#if defined(__APPLE__) || defined(__LIUNX__) //如果是macos/liunx系统
    correction();
    cout << "\033[32m当前系统为liunx/macos,";
    cout << "\033[32m系统将在当天" << hour << "点" << minute << "分关机！\033[32m" << endl;
    string command= "shutdown -";
    if (model)
    {
        command=command+"r ";
    }
    else
    {
        command=command+"h ";
    }
    get(hour, command);
    command=command+":";
    get(minute, command);
    command=command+" '需取消定时关机请在控制台输入shutdown -c'";
    system(command.data()); //给系统控制台发送关机指令
    cout << "\033[32m已发送定时关机命令！请确保是以\033[31mroot权限并在控制台内运行该程序，\033[32m否则设置将不成功！\033[0m" << endl;
    cout << "\033[32m如需取消定时关机请在控制台输入\033[31mshutdown -c()liunx或sudo kill 对应的pid进程号（macos）\033[0m" << endl;
#endif
#ifndef __APPLE__
#ifndef __LIUNX__ //非macos，liunx，默认为windwos，则编译，否则忽略
    correction();
    cout << "\033[32m当前系统为windwos,";
    cout << "\033[32m系统将在当天" << hour << "点" << minute << "分关机！\033[0m" << endl;
    string command = "at ";
    get(hour, command);
    command = command + ":";
    get(minute, command);
    command=command+ " shutdown -";
    if (model)
    {
        command = command + "r ";
    }
    else
    {
        command = command + "s ";
    }
    system(command.data()); //给系统控制台发送关机指令
    cout << "\033[32m已发送定时关机命令！请确保是\033[31m通过右键编译生成的exe文件以管理员身份运行，\033[32m否则设置将不成功！\033[0m" << endl;
    cout << "\033[32m如需取消定时关机请在cmd命令提示符或者运行处输入shutdown -a" << endl;
    system("pause");
#endif
#endif
    return;
}

#endif /* TimeClass_h */
