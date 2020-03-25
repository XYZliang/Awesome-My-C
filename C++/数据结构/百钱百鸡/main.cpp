//
//  main.cpp
//  单链表
//
//  Created by 张亮 on 2020/2/19.
//  In Xcode
//  Copyright © 2020 张亮. All rights reserved.
//

/*“百钱买百鸡问题”记载于中国古代约5～6世纪成书的《张邱建算经》中，是原书卷下第38
题，也是全书的最后一题。该问题的描述为：今有鸡翁一，值钱五；鸡母一，值钱三；鸡雏三，
值钱一。凡百钱买鸡百只，问鸡翁、母、雏各几何?翻译与现代汉语的意思是：公鸡每只值5文
钱，母鸡每只值3文钱，而3只小鸡值1文钱。用100文钱买100只鸡，问：这100只鸡中，公鸡、
母鸡和小鸡各有多少只?*/


#include <iostream>
#include <time.h>
using namespace std;

clock_t start, stop;
#define cycles 10000  //因为程序运行速度太快，时间较短不方便统计，故运行多次
#define plan 7
int times;

void plan1(){
    if(times==1)//当第一次时运行时
        cout << __FUNCTION__<< ",三重枚举:"<<endl;//输出提示信息
    for(int cock=0;cock<=100;cock++)//公鸡
        for(int hen=0;hen<=100;hen++)//母鸡
            for(int chicken=0;chicken<=100;chicken++)//小鸡
                if((cock+hen+chicken==100)&&(5*cock+3*hen+chicken/3==100)&&(chicken%3==0)&&(times==1))//(chicken&3==0),防止chicken/3相除后丢失数据造成意外结果
                    cout << "公鸡"<< cock<< "只,母鸡"<< hen<< "只,小鸡"<< chicken<< "只;  ";
    return;
}

//plan1只是单纯进行枚举,没有进一步分析公鸡母鸡小鸡可能的取值范围(100元最多能买多少鸡),故有了plan2
void plan2(){
    if(times==1)
        cout << __FUNCTION__<< ",优化的三重枚举:"<<endl;
    for(int cock=0;cock<=20;cock++)
        for(int hen=0;hen<=33;hen++)
            for(int chicken=0;chicken<=99;chicken+=3)
                if((cock+hen+chicken==100)&&(5*cock+3*hen+chicken/3==100)&&(times==1))//上一层已经确保小鸡数是三的倍数,无需担心chicken/3
                    cout << "公鸡"<< cock<< "只,母鸡"<< hen<< "只,小鸡"<< chicken<< "只;  ";
    return;
}

//plan1循环了三层,公母小鸡都枚举,,其实只要确定公母鸡的数量,小鸡的数量就可确定
void plan3(){
    if(times==1)
        cout << __FUNCTION__<< ",二重枚举:"<<endl;
    for(int cock=0;cock<=100;cock++)
        for(int hen=0;hen<=100;hen++)
            if((5*cock+3*hen+(100-cock-hen)/3==100)&&((100-cock-hen)%3==0)&&(times==1))
                cout << "公鸡"<< cock<< "只,母鸡"<< hen<< "只,小鸡"<< 100-cock-hen<< "只;  ";
    return;
}

//接合plan2和plan3的优点改进后的plan4
void plan4(){
    if(times==1)
        cout << __FUNCTION__<< ",优化的二重枚举:"<<endl;
    for(int cock=0;cock<=20;cock++)
        for(int hen=0;hen<=30;hen++)
            if((5*cock+3*hen+(100-cock-hen)/3==100)&&((100-cock-hen)%3==0)&&(times==1))
                cout << "公鸡"<< cock<< "只,母鸡"<< hen<< "只,小鸡"<< 100-cock-hen<< "只;  ";
    return;
}

//1.    公+母+小=100
//2.    5公+3母+小/3=100
//一式与二式连立可得3. 7公+4母=100,进一步发现公鸡最多14只,母鸡最多25只
//进一步改进plan4(不再对三重循环进行改进,孰快孰慢已经很明显)
void plan5(){
    if(times==1)
        cout << __FUNCTION__<< ",再优化的二重枚举:"<<endl;
    for(int cock=0;cock<=14;cock++)
        for(int hen=0;hen<=25;hen++)
            if((5*cock+3*hen+(100-cock-hen)/3==100)&&((100-cock-hen)%3==0)&&(times==1))
                cout << "公鸡"<< cock<< "只,母鸡"<< hen<< "只,小鸡"<< 100-cock-hen<< "只;  ";
    return;
}

//之前得到的三式可以进一步利用,仅用一个循环
void plan6(){
    if(times==1)
        cout << __FUNCTION__<< ",一重枚举:"<<endl;
    for(int cock=0;cock<=14;cock++)
            if((5*cock+3*(100-7*cock)/4+(100-cock-(100-7*cock)/4)/3==100)&&((100-cock-(100-7*cock)/4)%3==0)&&(times==1)&&((100-7*cock)%4==0))
                cout << "公鸡"<< cock<< "只,母鸡"<< (100-7*cock)/4<< "只,小鸡"<< 100-cock-(100-7*cock)/4<< "只;  ";
    return;
}

//三式转化可得母=25-(7/4)公,带入一式,得小=75+(3/4)公
//因为鸡数必须为整数,所以公鸡必须为4的倍数
void plan7(){
    if(times==1)
        cout << __FUNCTION__<< ",优化的一重枚举:"<<endl;
    for(int cock=0;cock<=12;cock+=4)
            if(times==1)
                cout << "公鸡"<< cock<< "只,母鸡"<< 25-7*cock/4<< "只,小鸡"<< 75+3*cock/4<< "只;  ";
    return;
}

//主函数
int main(void){
    for(int i=1;i<=plan;i++){ //依次运行不同的方案
        start=clock();  //获取进入函数时的cpu时钟计时
        for(times=1;times<=cycles;times++)  //运行指定的次数
        switch (i) {
            case 1:plan1();
                break;
            case 2:plan2();
                break;
            case 3:plan3();
                break;
            case 4:plan4();
                break;
            case 5:plan5();
                break;
            case 6:plan6();
                break;
            default:plan7();
                break;
        }
        stop=clock();   //获取退出函数时的cpu时钟计时
        cout<< "\n运行"<< cycles<< "次耗时"<< (double)(stop-start)/CLOCKS_PER_SEC << "秒----------------------------------------------------\n";//输出相应函数运算时间
    }
    return 0;
}


//我的电脑运行结果：
/*
 plan1,三重枚举:
 公鸡0只,母鸡25只,小鸡75只;  公鸡4只,母鸡18只,小鸡78只;  公鸡8只,母鸡11只,小鸡81只;  公鸡12只,母鸡4只,小鸡84只;
 运行10000次耗时20.7105秒----------------------------------------------------
 plan2,优化的三重枚举:
 公鸡0只,母鸡25只,小鸡75只;  公鸡4只,母鸡18只,小鸡78只;  公鸡8只,母鸡11只,小鸡81只;  公鸡12只,母鸡4只,小鸡84只;
 运行10000次耗时0.536262秒----------------------------------------------------
 plan3,二重枚举:
 公鸡0只,母鸡25只,小鸡75只;  公鸡4只,母鸡18只,小鸡78只;  公鸡8只,母鸡11只,小鸡81只;  公鸡12只,母鸡4只,小鸡84只;
 运行10000次耗时0.367442秒----------------------------------------------------
 plan4,优化的二重枚举:
 公鸡0只,母鸡25只,小鸡75只;  公鸡4只,母鸡18只,小鸡78只;  公鸡8只,母鸡11只,小鸡81只;  公鸡12只,母鸡4只,小鸡84只;
 运行10000次耗时0.024204秒----------------------------------------------------
 plan5,再优化的二重枚举:
 公鸡0只,母鸡25只,小鸡75只;  公鸡4只,母鸡18只,小鸡78只;  公鸡8只,母鸡11只,小鸡81只;  公鸡12只,母鸡4只,小鸡84只;
 运行10000次耗时0.014119秒----------------------------------------------------
 plan6,一重枚举:
  公鸡0只,母鸡25只,小鸡75只;  公鸡4只,母鸡18只,小鸡78只;  公鸡8只,母鸡11只,小鸡81只;  公鸡12只,母鸡4只,小鸡84只;
 运行10000次耗时0.001478秒----------------------------------------------------
 plan7,优化的一重枚举:
 公鸡0只,母鸡25只,小鸡75只;  公鸡4只,母鸡18只,小鸡78只;  公鸡8只,母鸡11只,小鸡81只;  公鸡12只,母鸡4只,小鸡84只;
 运行10000次耗时0.000196秒----------------------------------------------------
 Program ended with exit code: 0
 */


