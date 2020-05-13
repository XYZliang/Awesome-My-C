//
//  main.cpp
//  单链表v0.4
//
//  Created by 张亮 on 2020/3/10 in Xcode.
//  Copyright © 2020 张亮. All rights reserved.
//

//v0.1:由顺序表程序改造而来（主要是菜单部分），紧凑菜单选项，加入更多功能，但操作略显烦杂
//v0.2:解决上一版一跳转变量全部初始化的问题.
//v0.3:修复上一版的一些细节问题,修改部分逻辑,防止因用户的某些操作导致崩溃.
//v0.4:修复上一版的一些细节问题，完善错误提示,完善class,完善菜单，完善输出函数

#include <iostream>
using namespace std;

int lenth = 0; //单链表长度

class node //节点类
{
    friend class nodelist;

private:
    int value;               //节点的值
    node *next;              //下一个节点的地址
    static node *creat(int); //新建节点
public:
    struct info //从来存储某个节点的信息,方便进行搜索的返回，保证节点元素仍为private
    {
        int value;
        int nodenumber;
        node *p;
        node *front;
    };
    static void deleteNode(info *);  //删除节点
    static void modify(info *, int); //修改某个节点的值
    static void insert(info *, int); //插入节点
} * head;

class nodelist //单链表类
{
public:
    void creat(int lenth);                      //创建单链表
    void show(node *p);                         //输出单链表
    int traversal(node::info *search, int key); //遍历搜索单链表
    void destroy();                             //单链表销毁
    int isEmpty();                              //单链表判空
    int exit();                                 //退出单链表
};

node *node::creat(int date) //新建节点
{
    node *newnode = new node; //申请一段空间
    newnode->value = date;    //初始化新节点value为date
    return newnode;           //返回新指针地址
}

void node::deleteNode(info *deleteinfo)
{
    deleteinfo->front->next = deleteinfo->p->next; //前一节点的next指针,改为需要删除的当前的next指针,完成续接
    delete (deleteinfo->p);                        //删除
    lenth--;
    cout << ">>>>>>>>>>>>>>>>>>>>>删除完毕<<<<<<<<<<<<<<<<<<<<<<<<\n";
}

void node::modify(info *search, int m)
{
    search->p->value = m;
    cout << ">>>>修改完毕<<<<\n";
};

void node::insert(info *search, int m)
{
    node *newnode;
    newnode = node::creat(m);
    newnode->next = search->p->next; //新的节点与后序先对接
    search->p->next = newnode;       //前序节点接上新节点
    lenth++;
    cout << "完成!\n";
};

void nodelist::creat(int lenth) //创建链表
{
    head = node::creat(1);          //先把链表头做好;
    node *end = head;               //用一个变量保存"最后一个"节点的地址(这个最后指的是当前已经创建的链表的那一部分的最后一个节点)
    for (int i = 1; i < lenth; i++) //创建长度为lenth的单链表
    {
        end->next = node::creat(rand() % 1000); //最后一个节点和新节点接上
        end = end->next;                        //新节点就成了"最后一个"节点
    }
    end->next = NULL;
    return;
}

void nodelist::show(node *p) //从某个节点开始展示链表
{
    for (int i = 1; p->next != NULL; p = p->next) //依次输出
    {
        cout << p->value << "---";
        if (i++ % 8 == 0 || i == 1) //每8个元素换行
            cout << endl;
    }
    cout << p->value << "\n\n>>>>>>>>>>>>>>>>>>>>>输出完毕<<<<<<<<<<<<<<<<<<<<<<<<\n";
}

int nodelist::traversal(node::info *search, int key = 1) //根据某个信息进行搜索,key决定搜索的方式,默认为1(按值)，2为按节点数
{
    node *p = head, *front = head;
    if (key == 1)
    {
        for (int i = 1; i <= lenth; p = p->next, i++) //遍历链表,顺便记下序号
        {
            if (p->value == search->value) //如果满足条件
            {
                search->p = p;
                search->nodenumber = i; //写入详细信息
                search->front = front;
                return 1; //正常退出
            }
            front = p;
        }
    }
    else
    {
        for (int i = 1; i <= lenth; p = p->next, i++)
        {
            if (i == search->nodenumber) //如果满足条件
            {
                search->p = p;
                search->value = p->value; //写入详细信息
                search->front = front;
                return 1;
            }
            front = p;
        }
    }
    search->p = nullptr;
    return 0; //异常退出
}

void nodelist::destroy()
{
    for (node *p; head != NULL; head = p)
    {
        p = head->next;
        delete head; //释放所有节点
    }
    lenth = 0;
    cout << ">>>>>>>>>>>>>>>>>>当前链表销毁完毕<<<<<<<<<<<<<<<<<<<<<\n";
}

int nodelist::isEmpty()
{
    return lenth ? 0 : 1; //有长度就返回0，没有就是1
}

int nodelist::exit()
{
    cout << "欢迎下次再使用本系统！\n";
    return 0;
}

int main() //主函数
{
    int menu = 66666;
    nodelist L;
start:
    cout << "请输入需要创建的单链表的长度:";
    cin >> lenth;
    if(lenth<1)
    {
        cout<<"数据不合法！清重新输入！"<<endl;
        goto start;
    }
    L.nodelist::creat(lenth);
    cout << "单链表创建成功!（为了方便实验，已经随机生成长度为" << lenth << "的单链表：\n";
    L.nodelist::show(head); //展示单链表
    cout << "按任意键进入菜单";
    fflush(stdin); //清空输入缓存区
    system("pause");
    while (menu)
    {
        system("cls"); //清屏
        cout << endl
             << endl;
        cout << "----------------------------------------------------\n";
        cout << "         单      链      表      菜      单           \n";
        cout << "----------------------------------------------------\n";
        cout << "         1. 输出菜单        5. 插入菜单    \n";
        cout << "         2. 搜索菜单        6. 销毁单链表  \n";
        cout << "         3. 删除菜单        7. 链表判空    \n";
        cout << "         4. 修改菜单        0. 退出程序    \n";
        cout << "\n    请选择你的操作[0~7]:";
        cin >> menu;
        cout << "----------------------------------------------------\n";
        node::info *search = new node::info; //定义个info的变量,方便保存遍历(搜索)的启动和返回
        switch (menu)
        {
        case 1: //输出
        {
            cout << "          输      出           菜      单            \n";
            cout << "----------------------------------------------------\n";
            cout << "      11. 输出整个链表        13. 输出链表长度          \n";
            cout << "      12. 从第n位开始输出     14. 输出第n个节点的值       \n";
            cout << "\n    请选择你的操作[11~14]:";
            cin >> menu;
            cout << "****************************************************\n";
            if (menu == 11)
                L.show(head);
            else if (menu == 12)
            {
                int n;
                cout << "请输入需要输出的始位n:";
                cin >> n;
                if (0 < n < +lenth) //判断合法
                {
                    search->nodenumber = n; //输入信息
                    L.traversal(search, 2); //找出始位的地址
                    L.show(search->p);
                }
                else
                    cout << "数据非法，链表没有那么长或者不可为负数！\n\n";
            }
            else if (menu == 13)
                cout << "当前链表的长度为" << lenth << endl;
            else if (menu == 14)
            {
                int n;
                cout << "请输入需要查询的节点:";
                cin >> n;
                search->nodenumber = n; //输入信息
                L.traversal(search, 2); //调用遍历进行搜索
                cout << "该节点的值为" << search->value << endl;
            }
            else
                cout << "不存在此功能,请确认后重新输入!\n";
        }
        break;
        case 2: //搜索
        {
            int n;
            cout << "请输入需要搜索的值:";
            cin >> n;
            search->value = n;
            if (L.traversal(search)) //使用遍历函数
                cout << n << "第一次出现在第" << search->nodenumber << "个节点!\n";
            else
                cout << n << "这个值不存在这个链表中,请确认后重新输入!\n";
        }
        break;
        case 3: //删除
        {
            int n;
            cout << "          删      除           菜      单          \n";
            cout << "--------------------------------------------------\n";
            cout << "   31. 删除值n所在的第一个节点       32. 删除第n个节点  \n";
            cout << "\n    请选择你的操作[31~32]，并输入对应的n，以空格分开   \n";
            cout << "    如删除第一个节点请输入  32 1  :";
            cin >> menu >> n;
            cout << "**************************************************\n";
            if (menu == 31)
            {
                search->value = n;        //存入信息
                if (!L.traversal(search)) //通过变量函数找到所需的地址
                {
                    cout << "这个值不存在这个链表中,请确认后重新输入!\n";
                    search->p = nullptr;
                }
            }
            else if (menu == 32) //判断合法
            {
                if (n > lenth || n < 1)
                {
                    cout << "数据非法，链表没有那么长或者为非正数！\n";
                    search->p = nullptr;
                }
                else
                {
                    search->nodenumber = n;
                    L.traversal(search, 2);
                }
            }
            else
            {
                cout << "不存在此功能,请确认后重新输入!\n";
                search->p = nullptr;
            }
            if (search->p != nullptr) //如果正常，删除所查询的这个节点
                node::deleteNode(search);
        }
        break;
        case 4: //修改
        {
            int n, m;
            cout << "          修      改           菜      单          \n";
            cout << "--------------------------------------------------\n";
            cout << "           41. 修改值n所在的第一个节点为指定值m         \n";
            cout << "           42. 修改第n个节点为指定值m                 \n";
            cout << "\n    请选择你的操作[41~42]，并输入对应的n、m，以空格分开 \n";
            cout << "    如修改第二个节点为666请输入  42 2 666 :";
            cin >> menu >> n >> m;
            cout << "**************************************************\n";
            if (menu == 41)
            {
                search->value = n;
                if (!L.traversal(search))
                {
                    cout << "这个值不存在这个链表中,请确认后重新输入!\n";
                    search->p = nullptr;
                }
            }
            else if (menu == 42)
            {
                if (n > lenth)
                {
                    cout << "数据非法，链表没有那么长或者不可为负数！\n";
                    search->p = nullptr;
                }
                else
                {
                    search->nodenumber = n;
                    L.traversal(search, 2);
                }
            }
            else
            {
                cout << "不存在此功能,请确认后重新输入!\n";
                search->p = nullptr;
            }
            if (search->p != nullptr)
                node::modify(search, m);
        }
        break;
        case 5: //插入
        {
            int n, m;
            cout << "          插      入           菜      单          \n";
            cout << "--------------------------------------------------\n";
            cout << "        51. 在值n所在的第一个节点后插入值为m的节点       \n";
            cout << "        52. 在第n个节点后插入值为m的节点               \n";
            cout << "\n    请选择你的操作[51~52]，并输入对应的n、m，以空格分开 \n";
            cout << "    如在第二个节点后插入值为666的节点请输入  52 2 666 : \n";
            cin >> menu >> n >> m;
            cout << "**************************************************\n";
            if (menu == 51)
            {
                search->value = n; //先把前序的节点找出
                if (!L.traversal(search))
                    cout << "这个值不存在这个链表中,请确认后重新输入!\n";
            }
            else if (menu == 52)
            {
                if (n > lenth)
                {
                    cout << "数据非法，链表没有那么长或者不可为负数！\n";
                    search->p = nullptr;
                }
                else
                {
                    search->nodenumber = n;
                    L.traversal(search, 2);
                }
            }
            else
            {
                cout << "不存在此功能,请确认后重新输入!\n";
                search->p = nullptr;
            }
            if (search->p != nullptr)
                node::insert(search, m);
        }
        break;
        case 6: //销毁
        {
            L.destroy();
            cout << "输入0以退出程序，输入1以重新创建单链表，输入2以继续程序：";
            cin >> menu;
            if (menu)
            {
                if (menu == 1)
                    goto start;
            }
            else
                return (L.exit());
        }
        break;
        case 7:
        {
            if (L.isEmpty())
                cout << "链表为空！\n";
            else
                cout << "链表不为空!\n";
        }
        case 0:
            break;
        default:
            cout << "不存在此功能,请确认后重新输入!\n";
            break;
        }
        delete search;
        if (menu)
        {
            cout << "按任意键返回菜单\n";
            fflush(stdin); //清空输入缓存区
            system("pause");
        }
    }
    L.destroy();
    cout<<"made by"<<"\n     ___  __  ___  _  _ ___  _  _    ___  \n    / _ \\/_ |/ _ \\| || |__ \\| || |  / _ \\ \n   | | | || | (_) | || |_ ) | || |_| | | |\n   | | | || |\\__, |__   _/ /|__   _| | | |\n   | |_| || |  / /   | |/ /_   | | | |_| |\n    \\___/ |_| /_/    |_|____|  |_|  \\___/ \n\n";//Easter eggs
    return (L.exit());
}
