//
//  main.cpp
//  单链表v0.2
//
//  Created by 张亮 on 2020/3/1.
//  Copyright © 2020 张亮. All rights reserved.
//

//v0.2:解决上一版一跳转变量全部初始化的问题..不用setjump跳转了..坑爹啊
//不用setjump的话,无法偷懒,所有函数都得返回到主函数判断是否出现错误.
//也有好处,这样我就能对每个错误细分,提示用户具体是哪错了，该如何修正
//这样一来....贼多判断,时空复杂度全增加了..

//如果用户输入没有问题,此版本已经能完美解决问题.存在一些细节的bug和逻辑问题,在用户某些错误的输入下程序可能会崩溃.

#include <iostream>
using namespace std;

int menu,lenth;

struct node//定义节点结构体
{
    int value;
    node* next;
}*head;

struct info//从来存储某个节点的信息,方便进行搜索的返回
{
    int value;
    int nodenumber;
    node* p;
    node* front;
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
        //但是这个rand()生成的是伪随机数,怪不得每次运行生成的数顺序一毛一样,看网上说要改种子什么乱七八糟的,算了,反正不是重点
        end=end->next;//新节点就成了"最后一个"节点
    }//怎么偷懒怎么来
    end->next=NULL;
    return;
}

void showlinklist(node* p)//从某个节点开始展示链表
{
    for(;p->next!=NULL;p=p->next)
        cout<< p->value<< "---";
    cout<< p->value<< "\n>>>>输出完毕<<<<\n\n";
}//一开始用的是递归,感觉语句能少(tou)些(lan)..写完觉得吃饱了没事用哪门子递归,链表一长不就炸了..还是老老实实用回循环,反而简洁

int traversal(info* search,int key=1)//根据某个信息进行搜索,key决定搜索的方式,默认为1(按值)
{
    node* p=head,*front=head;
    if(key==1)
    {
        for(int i=1;i<=lenth;p=p->next,i++)//遍历链表,顺便记下序号
        {
            if(p->value==search->value)//如果满足条件
            {
                search->p=p;
                search->nodenumber=i;//写入详细信息
                search->front=front;
                return 1;//正常退出
            }
            front=p;
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
                search->front=front;
                return 1;
            }
            front=p;
        }
    }
    return 0;//异常退出
}

void deleteNode(info* deleteinfo)
{
    deleteinfo->front->next=deleteinfo->p->next;//前一节点的next指针,改为需要删除的当前的next指针,完成续接
    delete (deleteinfo->p);//删除
    lenth--;
    cout<< ">>>>删除完毕<<<<\n";
}

void exit()
{
    for(node* p;head!=NULL;head=p)
    {
        p=head->next;
        delete head;
    }
    cout<< "清理完毕!程序退出\n";
}

void clean()
{
    for(node* p=head;p!=NULL;p=p->next)
    {
        p->value=NULL;
    }
    cout<< "清理完毕!\n";
}

int main()//主函数
{
    
    cout<< "请输入需要创建的单链表的长度:";
    cin >> lenth;
    creatlinklist(lenth);
    cout<< "单链表创建成功!\n";
    showlinklist(head);//给用户瞄一眼建好的链表,防止某个输入是错的
    
    menulist:
    cout<< "链表功能菜单:\n";
    cout<< "1:输出功能 | 2:搜索功能\n3:删除功能 | 4:修改功能\n5:插入功能 | 6:退出程序\n7:清空线性表 | 请输入需要功能所对应的数字:";
    cin>> menu;
    info* search;//定义个info的变量,方便保存遍历(搜索)的启动和返回
    switch (menu)
    {
        case 1://输出
            {
                cout<< "11:输出整个链表|12:从第n位开始输出\n13:输出链表长度|14:输出第n个节点的值\n请输入需要功能所对应的数字:";
                cin>> menu;
                if(menu==11)
                    showlinklist(head);
                else if (menu==12)
                {
                    int n;
                    cout<< "请输入需要输出的始位:";
                    cin>> n;
                    search->nodenumber=n;
                    traversal(search,2);//找出始位的地址
                    showlinklist(search->p);
                }
                else if(menu==13)
                    cout<< "当前链表的长度为"<< lenth <<endl;
                else if(menu==14)
                {
                    int n;
                    cout<< "请输入需要查询的节点:";
                    cin>> n;
                    search->nodenumber=n;
                    traversal(search,2);
                cout<< "该节点的值为"<< search->value <<endl;
                }
                else
                {
                    cout<< "不存在此功能,请确认后重新输入!\n";
                    goto menulist;
                }
            }
            break;
        case 2://搜索
            {
                int n;
                cout<< "21:搜索某个值|22:找出某一结点对应的值\n请输入需要功能所对应的数字及其对应的值(空格隔开):";
                cin>> menu>> n;
                if(menu==21)
                {
                    search->value=n;
                    if(traversal(search))//使用遍历函数
                        cout<< n<< "在第"<< search->nodenumber <<"个节点!\n";
                    else
                    {
                        cout<< n<< "这个值不存在这个链表中,请确认后重新输入!\n";
                        goto menulist;
                    }
                }
                else if (menu==22)
                {
                    search->nodenumber=n;
                    if(n<lenth)
                    {
                        traversal(search,2);
                        cout<< "第"<< n<< "个节点的值为"<< search->value<< endl;
                    }else if (n==lenth)
                    {
                        traversal(search,2);
                        cout<< "该最后个节点的值为"<< search->value<< endl;
                    }
                    else
                    {
                        cout<< "此链表的长度为"<< n<< "链表没有辣么长,请重新输入\n";
                    }

                }
                else
                {
                    cout<< "不存在此功能,请确认后重新输入!\n";
                    goto menulist;
                }
            }
            break;
        case 3://删除
            {
                int n;
                cout<< "31:删除n所在的第一个节点|32:删除第n个节点\n请输入需要功能所对应的数字及其对应的n(空格隔开):";
                cin>> menu>> n;
                //info* deleteinfo; 为啥注释，看下面
                if(menu==31)
                {
                    //deleteinfo->value=n;此处xcode报错Thread 1: EXC_BAD_ACCESS (code=1, address=0x0)
                    //度娘说出现这个是因为所访问的内存空间被释放了,或者被保护，编译器找不到??????这不刚定义的么deleteinfo？？？？
                    //vscode报错zsh: segmentation fault，原因同上，百思不得其解。和我一摸一样的21、22模块,只是定义的info*指针名字不同,却正常？
                    search->value=n;//无奈尝试把info* search提出来，让这个删除模块也能凑合着用。。奇怪的是没问题了？？？？？？？？
                    //traversal(deleteinfo);
                    traversal(search);//通过变量函数找到所需的地址
                }
                else if(menu==32)
                {
                    //deleteinfo->nodenumber=n;
                    //traversal(deleteinfo,2);
                    search->nodenumber=n;
                    traversal(search,2);
                }
                else
                {
                    cout<< "不存在此功能,请确认后重新输入!\n";
                    goto menulist;
                }
                //deleteNode(deleteinfo);
                deleteNode(search);
            }
            break;
        case 4://修改
            {
                int n,m;
                cout<< "41:修改n所在的第一个节点为指定值m|42:修改第n个节点为指定值m\n请输入需要功能所对应的数字及n和m(空格隔开):";
                cin>> menu>> n>> m;
                if(menu==41)
                {
                    search->value=n;//既然上一个板块用search...干脆就全用......
                    traversal(search);
                }
                else if(menu==42)
                {
                    search->nodenumber=n;
                    traversal(search,2);
                }
                else
                {
                    cout<< "不存在此功能,请确认后重新输入!\n";
                    goto menulist;
                }
                search->p->value=m;//修改对应的即可
                cout<< ">>>>修改完毕<<<<\n";
            }
            break;
        case 5://插入
            {
                int n,m;
                node* newnode;
                cout<< "51:在n所在的第一个节点后插入节点,值为m|52:在第n个节点后插入节点,值为m\n请输入需要功能所对应的数字及n和m(空格隔开):";
                cin>> menu>> n>> m;
                if(menu==51)
                {
                    search->value=n;//先把前序的节点找出
                    traversal(search);
                }
                else if(menu==52)
                {
                    search->nodenumber=n;
                    traversal(search,2);
                }
                else
                {
                    cout<< "不存在此功能,请确认后重新输入!\n";
                    goto menulist;
                }
                newnode=creatnode(m);
                newnode->next=search->p->next;//新的节点与后序先对接
                search->p->next=newnode;//前序节点接上新节点
                lenth++;
                cout<< "欧了!\n";
            }
            break;
        case 6://退出程序(删除线性表)
            {
                exit();
                return 0;
            }
            break;
        case 7://清除
            {
                clean();
            }
                break;
        default:
            {
                cout<< "不存在此功能,请确认后重新输入!\n";
                goto menulist;
            }
            break;
    }
    cout<< "是否继续使用该程序?继续请输入1,否则退出程序\n";
    cin>> menu;
    if(menu)
        goto menulist;
    else
        exit();
    return 0;
}
