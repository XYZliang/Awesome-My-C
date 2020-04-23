#include <iostream>
#include <unistd.h>
#include <string>
using namespace std;
int main()
{
    FILE* fp = NULL;
    string cmd[]="curl -X POST -d 'username=2201904240&formId=107&datas=%5b%7b%22ffId%22%3a383%2c%22fid%22%3a%22107%22%2c%22content%22%3a%222020-04-08%22%7d%2c%7b%22ffId%22%3a384%2c%22fid%22%3a%22107%22%2c%22content%22%3a%22%e8%bd%af%e4%bb%b6%e4%b8%8e%e7%89%a9%e8%81%94%e7%bd%91%e5%b7%a5%e7%a8%8b%e5%ad%a6%e9%99%a2%ef%bc%88%e7%94%a8%e5%8f%8b%e8%bd%af%e4%bb%b6%e5%ad%a6%e9%99%a2%ef%bc%89(%e8%bd%af%e4%bb%b6%e5%b7%a5%e7%a8%8b192)%22%7d%2c%7b%22ffId%22%3a385%2c%22fid%22%3a%22107%22%2c%22content%22%3a%22张亮%22%7d%2c%7b%22ffId%22%3a386%2c%22fid%22%3a%22107%22%2c%22content%22%3a%222201904240%22%7d%2c%7b%22ffId%22%3a387%2c%22fid%22%3a%22107%22%2c%22content%22%3a%22%e5%ad%a6%e7%94%9f%22%7d%2c%7b%22ffId%22%3a388%2c%22fid%22%3a%22107%22%2c%22content%22%3a%22%e7%94%b7%22%7d%2c%7b%22ffId%22%3a389%2c%22fid%22%3a%22107%22%2c%22content%22%3a%22362502200103210810%22%7d%2c%7b%22ffId%22%3a390%2c%22fid%22%3a%22107%22%2c%22content%22%3a%2218797945431%22%7d%2c%7b%22ffId%22%3a391%2c%22fid%22%3a%22107%22%2c%22content%22%3a%22%e6%ad%a3%e5%b8%b8%22%7d%2c%7b%22ffId%22%3a392%2c%22fid%22%3a%22107%22%2c%22content%22%3a%22%e6%97%a0%22%7d%2c%7b%22ffId%22%3a393%2c%22fid%22%3a%22107%22%2c%22content%22%3a%22%e5%90%a6%22%7d%2c%7b%22ffId%22%3a394%2c%22fid%22%3a%22107%22%2c%22content%22%3a%22%e6%b1%9f%e8%a5%bf%e7%9c%81%22%7d%2c%7b%22ffId%22%3a395%2c%22fid%22%3a%22107%22%2c%22content%22%3a%22江西省抚州市临川区六水桥街道二仙桥32号%22%7d%2c%7b%22ffId%22%3a396%2c%22fid%22%3a%22107%22%2c%22content%22%3a%22%e5%90%a6%22%7d%2c%7b%22ffId%22%3a397%2c%22fid%22%3a%22107%22%2c%22content%22%3a%22%e5%90%a6%22%7d%2c%7b%22ffId%22%3a398%2c%22fid%22%3a%22107%22%2c%22content%22%3a%22%e5%90%a6%22%7d%2c%7b%22ffId%22%3a399%2c%22fid%22%3a%22107%22%2c%22content%22%3a%22%e5%90%a6%22%7d%2c%7b%22ffId%22%3a400%2c%22fid%22%3a%22107%22%2c%22content%22%3a%22%e5%90%a6%22%7d%2c%7b%22ffId%22%3a401%2c%22fid%22%3a%22107%22%2c%22content%22%3a%22%e5%90%a6%22%7d%2c%7b%22ffId%22%3a402%2c%22fid%22%3a%22107%22%2c%22content%22%3a%22%e5%90%a6%22%7d%2c%7b%22ffId%22%3a403%2c%22fid%22%3a%22107%22%2c%22content%22%3a%22%22%7d%2c%7b%22ffId%22%3a404%2c%22fid%22%3a%22107%22%2c%22content%22%3a%22%22%7d%2c%7b%22ffId%22%3a405%2c%22fid%22%3a%22107%22%2c%22content%22%3a%22%22%7d%2c%7b%22ffId%22%3a406%2c%22fid%22%3a%22107%22%2c%22content%22%3a%22%22%7d%2c%7b%22ffId%22%3a407%2c%22fid%22%3a%22107%22%2c%22content%22%3a%22%e6%98%af%22%7d%2c%7b%22ffId%22%3a408%2c%22fid%22%3a%22107%22%2c%22content%22%3a%22%e6%98%af%22%7d%2c%7b%22ffId%22%3a409%2c%22fid%22%3a%22107%22%2c%22content%22%3a%22%22%7d%5d&dateStr=2020-04-08'  https://wxcourse.jxufe.cn/universal_form/front/submit ";
    cmd[sizeof(cmd)-2]='"';cmd[sizeof(cmd)-56]='"';
    if ((fp = popen(cmd, "r")) != NULL)
    {
            fgets(cmd, sizeof(cmd), fp);
            pclose(fp);
    }
    system("clear");
    string returnMessage=cmd;
    string noSuccess="-1";
    string sendMessage;
    if(returnMessage.find(noSuccess)==string::npos)
        sendMessage="填报成功！返回信息："+returnMessage;
    else
        sendMessage="填报失败！返回信息："+returnMessage;
    string url="curl  http://47.107.145.93:5700/send_private_msg?user_id=1424625705&message="+sendMessage+" ";
    url[5]='"';url[url.length()-1]='"';
    cout<<url;
    const char *p=url.data();
    system(p);
    return 0;
}
