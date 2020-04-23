<<<<<<< HEAD
#include<vector>
#include<iostream>
#include <cstring>
using namespace std;
//头尾不可以有切分字符
vector<string> spilt(string s,char ch)
{
    s.push_back(ch);
    int start = 0,end = 0,size = (int)s.size();
    vector<string> vs;
    
    for(int i = 0;i < size;i++)
    {
        if(s[i]==ch)
        {
            end = i;
            string temp = s.substr(start,end-start);
            start = i+1;
            vs.push_back(temp);
        }
    }
    return vs;
}
int main()
{
    char ss[1000000];
    fgets(ss, 1000000, stdin);
    ss[strlen(ss)-1]='\0';
    string s=ss;
    vector<string> v = spilt(s,' ');
    for(int i = (int)(v.size()-1);i >= 0;i--)
    {
        if(i)
            cout << v[i]<<" ";
        else
            cout << v[i]<<endl;
    }
}
=======
class TimeType//自定义时间类TimeType
{
private://私有数据成员.
    int hour,minute,second;//表示当前时间的时、分、秒
    bool fullFormat;//布尔类型。ture为24小时格式，flase为12小时格式，用于十二小时制时间
    string APm;//保存上下午数据，用于十二小时制时间。
public://共有数据成员,类的对外接口.
    TimeType(int h=0,int m=0,int s=0,string apm=" "){hour=h;minute=m;second=s;APm=apm;apm==" "?fullFormat=true:fullFormat=false;};//初始化，并设定默认值
    void display();//输出TimeType
    int printf(int);//格式化为秒/分/时后输出/返回
    int isLegal(int);//判断时间格式是否合法，且是否输出提示
    void correction();//对不合法数据进行修正
    TimeType operator+(TimeType);//重载+运算符，使其能处理时间的加法
    TimeType operator-(TimeType);//计算两个时间之间的差值
    TimeType conversion();//十二小时/二十四小时进制互相转化
    TimeType getNowTime();//获取系统时间
    //以下函数需要在控制台中运行，且需要root权限
    void increaseSystemTime();//将此时间增加到系统时间
    void setTimingShutdown(int);//将此时间设置为系统定时关机/重启
};
>>>>>>> b393d37ae64208e363078c7bfdee84ec686e5038
