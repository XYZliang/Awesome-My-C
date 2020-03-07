//
//  main.cpp
//  单链表v0.1
//
//  Created by 张亮 on 2020/2/28.
//  Copyright © 2020 张亮. All rights reserved.
//

//setjump这个跨函数跳转有个很蛋疼的问题:会将原有的变量全部初始化!!!总是得不到预期的结果debug半天才发现是setjump的锅..百度一下他还真有初始化变量这个功能..没有很好的解决办法,此版本夭折..老老实实出错还是返回主函数后再goto吧......
//可能没搞清楚setjump和longjump的更深用法,longjump好像是能带一个参数传回去让setjump返回的..所以我只要确保我的链表首地址不被初始化,跳转的时候把它传回的话..他还是能用的.不过我很多地方是依据lenth链表长度来进行判断是否到了链表尾部,因此需要修改一下我所有用lenth判断的地方,改成p->next!=NULL即可.花里胡哨的算了,还是别偷懒.

#include <iostream>
#include <setjmp.h>//setjmp\longjmp,其实就是跨函数的goto,当用户输入非法,跳回菜单,很多地方要用,干脆写成函数.
using namespace std;

int menu,lenth;

struct node//定义节点结构体
{
    int value;
    node* next=NULL;//顺便初始化一下
}*head;

struct info//从来存储某个节点的信息,方便进行搜索的返回
{
    int value=NULL;
    int nodenumber=NULL;
    node* p=NULL;
};

node* creatnode(int date)//新建节点
{
    node* newnode=new node;//申请一段空间
    newnode->value=date;//初始化新节点value为date
    return newnode;//返回新指针地址
}

void creatlinklist(int lenth)//创建链表
{
    head=creatnode(1);//先把链表头做好;
    node* end=head;//用一个变量保存"最后一个"节点的地址(这个最后指的是当前已经创建的链表的那一部分的最后一个节点)
    for(int i=1;i<lenth;i++)//创建长度为lenth的单链表
    {
        end->next=creatnode(rand()%1000);//最后一个节点和新节点接上
        //creatnode()内是新节点的值,本来应该是让用户输入的,这里暂时只管单链表的操作,用rand()&1000生成一个千内随机数代替
        end=end->next;//新节点就成了"最后一个"节点
    }//怎么偷懒怎么来
    return;
}

void showlinklist(node* p)//从某个节点开始展示链表
{
    for(;p->next!=NULL;p=p->next)
        cout<< p->value<< "---";
    cout<< p->value<< "\n>>>>输出完毕<<<<\n\n";
}//一开始用的是递归,感觉语句能少(tou)些(lan)..写完觉得吃饱了没事用哪门子递归,链表一长不就炸了..还是老老实实用回循环,反而简洁

void inputError()
    {
        cout<< "输入错误!请重新输入\n\n";
        longjmp(&menu, NULL);//不知道为毛他需要一个指针和一个值..随便搞一个?
    }

void traversal(info* search,int key=1)//根据某个信息进行搜索,key决定搜索的方式,默认为1(按值)
{
    node* p = head;
    if(key==1)
    {
        for(int i=1;i<=lenth;p=p->next,i++)//遍历链表,顺便记下序号
        {
            if(p->value==search->value)//如果满足条件
            {
                search->p=p;
                search->nodenumber=i;//写入详细信息
                return;//正常退出
            }
        }
    }
    else
    {
        for(int i=1;i<=lenth;p=p->next,i++)
        {
            if(i==search->nodenumber)//如果满足条件
            {
                search->p=p;
                search->value=p->value;//写入详细信息
                return;
            }
        }
    }
    cout<< "此节点不存在,";//异常退出,显示错误信息
    inputError();//并跳转回主菜单
}
int main()//主函数
{
    cout<< "请输入需要创建的单链表的长度:";
    cin >> lenth;
    creatlinklist(lenth);
    cout<< "单链表创建成功!\n";
    showlinklist(head);//给用户瞄一眼建好的链表,防止某个输入是错的
    
    lenth=setjmp(&menu);
    cout<< "链表功能菜单:\n";
    cout<< "1:输出功能|2:搜索功能\n3:删除功能|4:修改功能\n5:插入功能|6:退出程序\n请输入需要功能所对应的数字:";
    cin>> menu;
    switch (menu)
    {
        case 1:
            {
                cout<< "11:输出整个链表|12:从某一位开始输出\n请输入需要功能所对应的数字:";
                cin>> menu;
                if(menu==11)
                    showlinklist(head);
                else if (menu==12)
                {
                        cout<< "请输入需要输出的始位:";
                }
                else
                    inputError();
            }
            break;
        case 2:
            {
                int n;
                cout<< "21:搜索某个值|22:找出某一结点对应的值\n请输入需要功能所对应的数字及其对应的值(空格隔开):";
                cin>> menu>> n;
                info* search;
                if(menu==21)
                {
                    search->value=n;
                    traversal(search);
                    cout<< n<< "在第"<< search->nodenumber <<"个节点!\n";
                }
                else if (menu==22)
                {
                    search->nodenumber=n;
                    if(n<lenth)
                    {
                        traversal(search,2);
                        cout<< n<< "在第"<< search->nodenumber <<"个节点!\n";
                    }else if (n==lenth)
                        cout<< n<< "在最后个节点!\n";
                    else
                    {
                        cout<< "链表没有辣么长,";
                        inputError();
                    }

                }
                else
                    inputError();
            }
            break;
        case 3:
            {
                
            }
            break;
        case 4:
            {
                
            }
            break;
        case 5:
            {
                
            }
            break;
        case 6:
            {
                
            }
            break;
        default:
            inputError();
            break;
    }
    
    return 0;
}
