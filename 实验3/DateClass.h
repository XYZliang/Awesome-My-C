//
//  DateClass.h
//  实验3
//
//  Created by 张亮 on 4/5/20.
//  Copyright © 2020 张亮. All rights reserved.
//

#ifndef DateClass_h
#define DateClass_h

#include <iostream>
#include <iomanip>//保留小数
#include <cstring>//字符串拼接，用于合成控制台指令
#include <time.h>//使用ISO C99 标准日期时间头文件，用于系统日期相关操作
using namespace std;
int monthDay[]={0,31,28,31,30,31,30,31,31,30,31,30,31};
#ifndef __APPLE__
    #ifndef __LIUNX__//非macos，liunx，默认为windwos，则编译，否则忽略
    //#include <windows.h>//用于修改windows系统时间,此方法与实验二雷同，本实验使用新方法
    #pragma warning( disable : 4996 )
    //vs过于严格，强制其允许使用跨平台的localtime函数，而不是他自己的localtime_s函数，省得又需要判断系统
    #endif
#endif

class DateType//自定义时间类DateType
{
private://私有数据成员.
    int year,month,day,hour,min;//表示当前日期的年、月、日、时、分（时分用于liunx系统下修改日期）
    bool leapYear;//布尔类型，储存闰年/非闰年信息
    int sumDay;//以1年1月1日为基准，经过的总天数，用于下方的加减法
public://共有数据成员,类的对外接口.
    DateType(int h=0,int m=0,int s=0){year=h;month=m;day=s;leapYear=isLeapYear();sumDay=0;};//初始化，并设定默认值
    void display();//输出DateType
    int isLegal(int);//判断时间格式是否合法，且是否输出提示
    void correction();//对不合法数据进行修正
    bool isLeapYear();//判断是否是闰年
    //void getChineseCalendar();//求对应农历的。。。百度了下农历的计算方法。。。有的变态。。。放弃放弃。。。。
    //void nextFestival();//获取下一个节日。技术含量不高，事还多。。。懒得做。。。。。。。。。。。。。。。。。。
    int getWeek(int);//获取对应的星期
    int getSumDay();//以1年1月1日为基准，计算经过的日期，用于下方日期的加减法及日期的计算
    void returnSumDay();//以1年1月1日为基准后的天数，反求日期，用于下方日期的加减法
    DateType operator+(DateType);//重载+运算符，使其能处理日期的加法，支持跨年
    DateType operator-(DateType);//计算两个时间之间的差值天数,支持跨年
    //不建议进行日期的相减，得出的年月日没有很大的意义，应获取差值的天数，既.sumDay
    DateType getNowDate(int);//获取系统时间
    void setSystemDate();//将此时间设置为系统时间
    void calendarm(int);//输出月历
    void calendary();//输出年历
};

//在类外定义成员函数
void DateType::display()
{
    cout<<year<<"年"<<month<<"月"<<day<<"日"<<endl;
}

int DateType::isLegal(int model=0)//model=0（默认），只检查是否合法。1检查是否合法，并显示提示内容。2在1的基础上强制跳过对年份小于0的检查，适用于减法。
{
    string wrong="数据不合法！";
    string right="数据合法！";
    if(year<0&&model!=2)
    {
        wrong+="年份不能为负！当前进程退出！";//+=合并错误代码方便输出
        return 0;
    }
    if(month<=0)
        wrong+="月份必须为正！";
    else if(month>12)
        wrong+="月份不能超过12！";
    if(leapYear&&month==2)//闰年2月分别讨论
    {
        if(day<=0)
            wrong+="天数必须为正！";
        else if(day>29)
            wrong+="天数不能超过当月最大天数！";
    }
    else
    {
        if(day<=0)
            wrong+="天数必须为正！";
        else if(day>monthDay[month])
            wrong+="天数不能超过当月最大天数！";
    }
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
                DateType::correction();//修正数据
                cout<<"修正后的日期为：";
                DateType::display();//显示修正后的数据
                return 1;
            }
        }
        else
        {
            DateType::correction();//自动修正
            return 1;
        }
        return 0;
    }
    if (model==1)
        cout<<right<<endl;
    return 1;
}

void DateType::correction()
//对于X月0日，在星历表上指X月1日的上一天，既X-1月最后一天。
//以此类推，X年0月即X-1年的12月。
//使用公元年，第一天即为1年1月1日。
//本函数依照此逻辑进行修正。
{
    if(month<=0)
    {
        month+=12;
        year--;goto finish;//解决完当下发现的问题立即跳转结尾，递归进入correction()再次从头修正问题
    }
    else if(month>12)
    {
        month-=12;
        year++;goto finish;
    }
    if(leapYear&&month==2)//对两个运算与二月份最后一天密切相关的月份单独处理
    {
        if(day<=0)
        {
            day+=31;
            month=1;goto finish;
        }
        else if(day>29)
        {
            day-=29;
            month=3;goto finish;
        }
    }
    else if(leapYear&&month==3)
    {
        if(day<=0)
        {
            day+=29;
            month=2;goto finish;
        }
        else if(day>31)
        {
            day-=31;
            month=4;goto finish;
        }
    }
    else
    {
        if(day<=0)
        {
            day+=monthDay[month-1];
            month--;goto finish;
        }
        else if(day>monthDay[month])
        {
            day-=monthDay[month];
            month++;goto finish;
        }
    }
    finish:
    isLegal();//再次判断是否合法，否则递归继续修正，直到合法再退出。
}

bool DateType::isLeapYear()
{
    return ((year%4==0&&year%100!=0)||year%400==0);
}

DateType DateType::operator+(DateType plus)//不通过同实验2的方法，直接将年月日相加后进行修正即可。
//每个月的天数也不同，实用旧方法会十分复杂，存在过多逻辑问题。
//选择以1年1月1日为基准，经过的总天数，再进行加减，最后将总天数转换回年月日。
{
    DateType sum;
    getSumDay();
    plus.getSumDay();
    sum.sumDay=sumDay+plus.sumDay;
    sum.returnSumDay();
    return sum;
}

DateType DateType::operator-(DateType sub)
{
    DateType delta;
    if(year<=sub.year)
        if(month<=sub.year)
        {
            if(day<sub.day)
            {
                int go;
                cout<<"被减日期小于减日期，结果年份为负。不符合逻辑。是否更换相减顺序？是输入0，否则退出进程。";
                cin>>go;
                if(!go)
                {
                    getSumDay();
                    sub.getSumDay();
                    delta.sumDay=-sumDay+sub.sumDay;
                    delta.returnSumDay();
                    return delta;
                }
                else
                {
                    cout<<"进程退出";
                    return NULL;
                }
            }
            else if(day==sub.day)
            {
                delta.year=0;
                delta.month=0;
                delta.day=0;
                delta.sumDay=0;
                cout<<"两日期相等。"<<endl;
                return delta;
            }
        }
    getSumDay();
    sub.getSumDay();
    delta.sumDay=sumDay-sub.sumDay;
    delta.returnSumDay();
    return delta;
}

int DateType::getWeek(int model=1)
{
    int week=getSumDay()%7;
    if(model)
    {
        string a[]={"NULL","一","二","三","四","五","六","日"};
        cout<<"今天星期"<<a[week]<<"鸭"<<endl;
    }
    return week;
}

int DateType::getSumDay()//配合加减法、计算星期
{
    correction();//先自动修正
    int m[]={0,31,28,31,30,31,30,31,31,30,31,30,31};
    if((year%4==0&&year%100!=0)||year%400==0)
        m[2]++;
    int sum = 0;
    for(int i = 1;i < year;i++)
    {
        sum += 365;
        if((i%4==0&&i%100!=0)||i%400==0)
            sum ++;
    }
    for(int i = 1;i < month;i++)
    {
        sum += m[i];
    }
    sum += day;
    sumDay=sum;
    return sum;
}

void DateType::returnSumDay()
{
    int n=sumDay;
    int m[]={0,31,28,31,30,31,30,31,31,30,31,30,31};
    for(year=1;;year++)//算出年份
    {
        if((year%4==0&&year%100!=0)||year%400==0)
        {
            if(n<=366)
                break;
            else
                n-=366;
        }
        else
        {
            if(n<=365)
                break;
            else
                n-=365;
        }
        
    }
    if((year%4==0&&year%100!=0)||year%400==0)
    {
        m[2]++;
        leapYear=true;
    }
    else
        leapYear=false;
    for(month=1;month<=12;month++)
    {
        if(n>m[month])
        {
            n-=m[month];
            continue;
        }
        else
        {
            day=n;
            break;
        }
    }
}
DateType DateType::getNowDate(int model=0)
{
    DateType nowTime;
    struct tm* ptr;
    time_t lt;
    lt=time(NULL);
    ptr=localtime(&lt);//获取系统时间
    nowTime.year = ptr->tm_year+1900;
    nowTime.month = ptr->tm_mon+1;
    nowTime.day = ptr->tm_mday;
    if(model)
    {//linux修改日期时需要
        nowTime.hour=ptr->tm_hour;
        nowTime.min=ptr->tm_min;
    }
    return nowTime;
}

void get(int n,char *m)//配合获取liunx控制台的指令
{
    char a[4];
    if(n<10)
    {
        sprintf(a,"%d",0);
        strcat(m, a);
        sprintf(a,"%d",n);
        strcat(m, a);
    }
    else
    {
        sprintf(a,"%d",n);
        strcat(m, a);
    }
    return;
}

void DateType::setSystemDate()
{
#if defined (__APPLE__)||defined (__LIUNX__)//如果是macos/liunx系统
    correction();
    int go=0;
    if(year<1970)
    {
        cout<<"很少有系统支持更改时间至格林威治时间起始前(1970年01月01日00时00分00秒)！"<<endl;
        cout<<"继续很有可能造成修改失败甚至是系统崩溃！！！输入0强制继续，输入其他退出:";
        cin>>go;
    }
    if(go)
        return;
    cout << endl<<"当前系统为macos/linux,系统日期为";
    getNowDate().display();
    char command[18]="date ";
    DateType now=getNowDate(1);
    get(month,command);
    get(day,command);
    get(now.hour,command);
    get(now.min,command);
    char a[4];
    sprintf(a,"%d",year);
    strcat(command, a);
    system(command);//给系统控制台发送date指令
    cout<<"已发送修改时间命令！请确保是以root权限并在控制台内运行该程序，否则修改将不成功！"<<endl;
    cout<<"请关闭自动同步时间，否则日期不久后会恢复。";
#endif

#ifndef __APPLE__
#ifndef __LIUNX__//windows
    correction();
    int go=0;
    if(year<1970)
    {
        cout<<"很少有系统支持更改时间至格林威治时间起始前(1970年01月01日00时00分00秒)！"<<endl;//windows10能hold住1940+
        cout<<"继续很有可能造成修改失败甚至是系统崩溃！！！输入0强制继续，输入其他退出:";
        cin>>go;
    }
    if(go)
        return;
    cout << "当前系统为windows,系统时间为";
    getNowDate().display();
/* 同实验2windows修改时间的方法，不再演示
    SYSTEMTIME system_time;
    GetLocalTime(&system_time);//获取系统时间
    system_time.wDay = day;//分别加上时分秒
    system_time.wMonth = month;
    system_time.wYear = year;
    if (SetLocalTime(&system_time))//设定时间（需要权限）
        cout << "修改成功！请关闭自动同步时间，否则日期不久会恢复。"<<endl;
    else
        cout << "修改失败！缺少管理员权限，请右键编译生成的exe文件以管理员身份运行。或者修改的年份早于系统规定，访问被拒绝。"<<endl;
 */
    
//同本实验macos/liunx的方法，利用系统控制台命令进行修改
    char command[15]="date ";
    char y[4];
    char split[] = {"-"};
    sprintf(y,"%d",year);
    strcat(command, y);
    strcat(command, split);
    get(month,command);
    strcat(command, split);
    get(day,command);
    strcat(command, split);
    system(command);
    cout << "已发送修改时间命令！请确保是以管理员身份运行该程序，否则修改将不成功！" << endl;
    cout << "请关闭自动同步时间，否则日期不久后会恢复。";
#endif
#endif
    cout<<endl<<"当前系统日期为：";//输出修改后的结果
    getNowDate().display();
#ifndef __APPLE__
#ifndef __LIUNX__
    system("pause");//windows运行完exe文件默认关闭窗口，看不见结果，用pause暂停
    //vs编译的exe在此处回莫名崩溃，还没找到原因。不影响程序的使用。
#endif
#endif
}

void DateType::calendarm(int model=1)//model=1:月历模式；0:年历模式且不输出*；2:年历模式且在对应的日子标上*
{
    string m[]={"NULL","一","二","三","四","五","六","七","八","九","十","十一","十二"};
    int week=(getSumDay()-day+1)%7;
    if(model)
    {
        if(leapYear&&month==2)
            monthDay[2]++;
        if(model!=2)
        {
            cout << "-------------------------------------------------" << endl;
            cout << setw(8) << "日" << setw(8) << "一" << setw(8) << "二" << setw(8) << "三" << setw(8) << "四" << setw(8) << "五" << setw(8) << "六"<< endl;
            cout << "-------------------------------------------------" << endl;
            cout<<" "<<year<<"年"<<m[month]<<"月"<< endl;
        }
        else
            cout<<" "<<m[month]<<"月"<< endl;
    }
    else
        cout<<" "<<m[month]<<"月"<< endl;
    for(int i=0;i<week;i++)
        cout<<setw(9)<<"  ";
    for(int d=1;d<=monthDay[month];week++)
    {
        if(d==day&&model)
        {
            if(d<10)
            {
                string a="*0";
                a=a+to_string(d++);
                cout<<setw(7) <<a;
            }
            else
            {
                string a="*";
                a=a+to_string(d++);
                cout<<setw(7) <<a;
            }
            if(week==6)
            {
                cout<<endl;
                week=-1;
            }
        }
        else
        {
            if(d<10)
            {
                string a="0";
                a=a+to_string(d++);
                cout<<setw(7) <<a;
            }
            else
                cout<<setw(7) <<d++;
            if(week==6)
            {
                cout<<endl;
                week=-1;
            }
        }
    }
    cout <<endl<< "-------------------------------------------------" << endl;
    if(leapYear&&month==2&&model)
        monthDay[2]--;
}

void DateType::calendary()
{
    string m[]={"NULL","一","二","三","四","五","六","七","八","九","十","十一","十二"};
    cout << "-------------------------------------------------" << endl;
    cout << setw(8) << "日" << setw(8) << "一" << setw(8) << "二" << setw(8) << "三" << setw(8) << "四" << setw(8) << "五" << setw(8) << "六"<< endl;
    cout << "-------------------------------------------------" << endl;
    cout<<setw(33)<<year<<"年"<<endl;
    for(int i=1;i<=12;i++)
    {
        if(i==month)
        {
            DateType print(year,i,day);
            print.calendarm(2);
        }
        else
        {
            DateType print(year,i,day);
            print.calendarm(0);
        }
    }
}
#endif /* DateClass_h */
