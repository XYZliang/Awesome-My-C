//求曲线（或直线）y=ax^2+bx+c与X轴的交点坐标。系数a、 b、 c通过键盘随机输入。
#include<stdio.h>
#include<math.h>
int main()
{
    double a,b,c,z,t,s;
    printf("对于方程ax^2+bx+c=0，请输入三个数，分别为a，b，c，用逗号隔开，回车键结束：\n");//写好提示语，方便别人看懂
    scanf("%lf,%lf,%lf",&a,&b,&c);
    t=0;s=1;//任何变量都需要定义初始值 ，否则会输出乱代码
    if(a==0)
        {
            if(b==0)
            {
                printf("该方程与x轴无交点\n");
            }
            else//else的后面不需要再跟条件，if条件不满足直接运行else后面的语句
            {
                t=-c/b;
                printf("与x轴交点坐标为：(%lf,0)\n",t);//记住double输出是用%lf，float才是%f
            }
        }
    else
        {
            z=b*b-4*a*c;
            if(z<0)
            {
                printf("该方程与x轴无交点\n");
            }
            else if(z==0)
            {
                t=-b/2*a;
                printf("与x轴交点坐标为：(%lf,0)\n",t);//else中间想让他执行的东西必须{}起来，否则将出现错误
            }
            else
            {
                t=(-b+sqrt(b*b-4*a*c))/(2*a);
                s=(-b-sqrt(b*b-4*a*c))/(2*a);//注意一下,和;的用处
                printf("与x轴交点坐标为：(%lf,0),(%lf,0)\n",t,s);
            }
        }
    return 0;
}
