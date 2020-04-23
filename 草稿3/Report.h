//
//  Header.h
//  草稿3
//
//  Created by 张亮 on 2020/4/14.
//  Copyright © 2020 张亮. All rights reserved.
//

#ifndef Header_h
#define Header_h

#include <iostream>
#include <time.h>
using namespace std;

#ifndef __APPLE__
#ifndef __LIUNX__ //非macos，liunx，默认为windwos，则编译，否则忽略
#pragma warning(disable : 4996)
//vs过于严格，强制其允许使用跨平台的localtime函数
#include <string> //win下to_string函数头文件
#endif
#endif


class info
{
private:
    string name;
    string address;
    string number;
    int day,month,qq;
    void Date();//获取系统日期
public:
    info(string a=nullptr,string b=nullptr,string c=nullptr,int Q=1424625705){name=a;address=b;number=c;qq=Q;Date();};
    void epidemicReport();
};

void info::epidemicReport() //用不来复杂的纯c++请求，只能走捷径用我自己熟悉的系统命令的方式
{
    int length = 0;
    
start:
    FILE *fp = NULL;
    string cmda;
    cmda = "curl -X POST -d 'username="; //第一段命令
    string cmdb = "&formId=107&datas=%5b%7b%22ffId%22%3a383%2c%22fid%22%3a%22107%22%2c%22content%22%3a%22";                                                                                                                                                                                                                                                                          //第二段命令
    string cmdc = "%22%7d%2c%7b%22ffId%22%3a384%2c%22fid%22%3a%22107%22%2c%22content%22%3a%22%e8%bd%af%e4%bb%b6%e4%b8%8e%e7%89%a9%e8%81%94%e7%bd%91%e5%b7%a5%e7%a8%8b%e5%ad%a6%e9%99%a2%ef%bc%88%e7%94%a8%e5%8f%8b%e8%bd%af%e4%bb%b6%e5%ad%a6%e9%99%a2%ef%bc%89(%e8%bd%af%e4%bb%b6%e5%b7%a5%e7%a8%8b192)%22%7d%2c%7b%22ffId%22%3a385%2c%22fid%22%3a%22107%22%2c%22content%22%3a%22"; //第三段命令
    string cmdd = "%22%7d%2c%7b%22ffId%22%3a386%2c%22fid%22%3a%22107%22%2c%22content%22%3a%22";
    string cmde = "2201904240%22%7d%2c%7b%22ffId%22%3a387%2c%22fid%22%3a%22107%22%2c%22content%22%3a%22%e5%ad%a6%e7%94%9f%22%7d%2c%7b%22ffId%22%3a388%2c%22fid%22%3a%22107%22%2c%22content%22%3a%22%e7%94%b7%22%7d%2c%7b%22ffId%22%3a389%2c%22fid%22%3a%22107%22%2c%22content%22%3a%22362502200103210810%22%7d%2c%7b%22ffId%22%3a390%2c%22fid%22%3a%22107%22%2c%22content%22%3a%2218797945431%22%7d%2c%7b%22ffId%22%3a391%2c%22fid%22%3a%22107%22%2c%22content%22%3a%22%e6%ad%a3%e5%b8%b8%22%7d%2c%7b%22ffId%22%3a392%2c%22fid%22%3a%22107%22%2c%22content%22%3a%22%e6%97%a0%22%7d%2c%7b%22ffId%22%3a393%2c%22fid%22%3a%22107%22%2c%22content%22%3a%22%e5%90%a6%22%7d%2c%7b%22ffId%22%3a394%2c%22fid%22%3a%22107%22%2c%22content%22%3a%22%e6%b1%9f%e8%a5%bf%e7%9c%81%22%7d%2c%7b%22ffId%22%3a395%2c%22fid%22%3a%22107%22%2c%22content%22%3a%22";
    string cmdf = "%22%7d%2c%7b%22ffId%22%3a396%2c%22fid%22%3a%22107%22%2c%22content%22%3a%22%e5%90%a6%22%7d%2c%7b%22ffId%22%3a397%2c%22fid%22%3a%22107%22%2c%22content%22%3a%22%e5%90%a6%22%7d%2c%7b%22ffId%22%3a398%2c%22fid%22%3a%22107%22%2c%22content%22%3a%22%e5%90%a6%22%7d%2c%7b%22ffId%22%3a399%2c%22fid%22%3a%22107%22%2c%22content%22%3a%22%e5%90%a6%22%7d%2c%7b%22ffId%22%3a400%2c%22fid%22%3a%22107%22%2c%22content%22%3a%22%e5%90%a6%22%7d%2c%7b%22ffId%22%3a401%2c%22fid%22%3a%22107%22%2c%22content%22%3a%22%e5%90%a6%22%7d%2c%7b%22ffId%22%3a402%2c%22fid%22%3a%22107%22%2c%22content%22%3a%22%e5%90%a6%22%7d%2c%7b%22ffId%22%3a403%2c%22fid%22%3a%22107%22%2c%22content%22%3a%22%22%7d%2c%7b%22ffId%22%3a404%2c%22fid%22%3a%22107%22%2c%22content%22%3a%22%22%7d%2c%7b%22ffId%22%3a405%2c%22fid%22%3a%22107%22%2c%22content%22%3a%22%22%7d%2c%7b%22ffId%22%3a406%2c%22fid%22%3a%22107%22%2c%22content%22%3a%22%22%7d%2c%7b%22ffId%22%3a407%2c%22fid%22%3a%22107%22%2c%22content%22%3a%22%e6%98%af%22%7d%2c%7b%22ffId%22%3a408%2c%22fid%22%3a%22107%22%2c%22content%22%3a%22%e6%98%af%22%7d%2c%7b%22ffId%22%3a409%2c%22fid%22%3a%22107%22%2c%22content%22%3a%22%22%7d%5d&dateStr=";
    string cmdg= "' \"https://wxcourse.jxufe.cn/universal_form/front/submit\"";
    string date;
    if (day < 10)
        date = to_string(2020) + "-" + to_string(0) + to_string(month) + "-" + to_string(0) + to_string(day);
    else
        date = to_string(2020) + "-" + to_string(0) + to_string(month) + "-" + to_string(day);
    string cmdCommand = cmda + number + cmdb + date + cmdc + name + cmdd + number + cmde + address + cmdf + date + cmdg; //命令中加入个人信息，合成完整curl命令
    length = (int)cmdCommand.length() - 2;
    char *cmd= new char[length];
    cmdCommand.copy(cmd, cmdCommand.length());
    if ((fp = popen(cmd, "r")) != NULL)      //下面两行用来获取命令行返回的数据，百度copy来的。。说什么隧道
    {
        fgets(cmd, length, fp);
        pclose(fp);
    }
    if (cmd[0] != '{')
        goto start;
    string returnMessage = cmd;
    string noSuccess = "-1";
    string showMessage;
    if (returnMessage.find(noSuccess) == string::npos)
        showMessage = name+ "填报成功！返回信息：" + returnMessage;
    else
        showMessage = name+ "填报失败！返回信息：" + returnMessage;
    cout<<showMessage;
    for(int i=0;i<=showMessage.length();i++)
        if(showMessage[i]=='{'||showMessage[i]=='}')
            showMessage[i]='$';
    string sendmessage;
    if(name=="叶怡麟")
        return;
    else
        sendmessage="curl \"http://47.107.145.93:5700/send_private_msg?user_id="+to_string(qq)+"&message="+showMessage+"\"";
    system(sendmessage.data());
}
void info::Date()
{
    struct tm *ptr;
    time_t lt;
    lt = time(NULL);
    ptr = localtime(&lt); //获取系统时间
    month=ptr->tm_mon + 1;
    day=ptr->tm_mday;
}


#endif /* Header_h */
