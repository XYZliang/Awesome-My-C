#include<stdio.h>
#include<string.h>
int main()
{
    char str1[1001];
    static int i,a,x,y,N,b;
    
    scanf("%d\n",&N);
    char str[N][1001];
    for(i=0;i<N;i++){              /*输入对话，存入二维数组*/
        gets(str[i]);
    }
    
    for(b=0;b<N;b++){               /*对输入的对话一行一行 进行改造*/
    i=0;
    a=0;
    x=0;
    while(str[b][i]!='\0'){               /*改造开始，以单个字母进行改变*/
        if(str[b][i]==' '&&x==1){          /*多个空格变成一个*/
            str1[a]=' ';
            a++;
            x=0;
        }
        
        if(str[b][i]!=' '){               /*清除符号前的空格*/
            if((str1[a-1]==' ')&&((str[b][i]<'a'||str[b][i]>'z')&&(str[b][i]<'A'||str[b][i]>'Z'))&&((str[b][i]<'0')||(str[b][i]>'9'))){
                if(str[b][i]=='?'){                       /*改变问号为叹号*/
                    str1[--a]='!';
                    a++;
                    x=1;
                }
                else{
                    str1[--a]=str[b][i];
                    a++;
                    x=1;
                }
            }
            else{
                if(str[b][i]<='Z'&&str[b][i]>='A'&&str[b][i]!='I'){       /*改大写为小写*/
                    str1[a]=str[b][i]-'A'+'a';
                    a++;
                    x=1;
                }
                else{
                    if(str[b][i]=='?'){                     /*改变问号为叹号*/
                        str1[a]='!';
                        a++;
                        x=1;
                    }
                    else{                               /*其他字母正常存入*/
                        str1[a]=str[b][i];
                        a++;
                        x=1;
                    }
                }
            }
        }
        i++;                      /*下一个字母*/
    }
    
    str1[a]='\0';                 /*添加字符串结束标记*/
    if(str1[a-1]==' '){           /*去掉字符串最后的空格*/
        str1[a-1]='\0';
    }
    
    i=0;
    while(str1[i]!='\0'){
        /*判断是否为can you*/
        if(str1[i]=='c'&&str1[i+1]=='a'&&str1[i+2]=='n'&&str1[i+3]==' '&&str1[i+4]=='y'&&str1[i+5]=='o'&&str1[i+6]=='u'){
            if(((str1[i-1]<'a'||str1[i-1]>'z')&&(str1[i-1]<'A'||str1[i-1]>'Z'))&&((str1[i+7]<'a'||str1[i+7]>'z')&&(str1[i+7]<'A'||str1[i+7]>'Z'))){
                str1[i]='I';                        /*判断can you是否独立（“独立”是指被空格或标点符号分隔开的单词）*/
                str1[i+1]=' ';
                str1[i+2]='c';
                str1[i+3]='a';
                str1[i+4]='n';
                str1[i+5]='8';
                str1[i+6]='8';
                i+=7;                             /*减少判断量，从can you后的字符继续判断*/
                continue;
            }
        }
        /*判断是否为could you*/
        if(str1[i]=='c'&&str1[i+1]=='o'&&str1[i+2]=='u'&&str1[i+3]=='l'&&str1[i+4]=='d'&&str1[i+5]==' '&&str1[i+6]=='y'&&str1[i+7]=='o'&&str1[i+8]=='u'){
            if(((str1[i-1]<'a'||str1[i-1]>'z')&&(str1[i-1]<'A'||str1[i-1]>'Z'))&&((str1[i+9]<'a'||str1[i+9]>'z')&&(str1[i+9]<'A'||str1[i+9]>'Z'))){
                str1[i]='I';                        /*判断could you是否独立（“独立”是指被空格或标点符号分隔开的单词）*/
                str1[i+1]=' ';
                str1[i+2]='c';
                str1[i+3]='o';
                str1[i+4]='u';
                str1[i+5]='l';
                str1[i+6]='d';
                str1[i+7]='8';
                str1[i+8]='8';
                i+=7;                             /*减少判断量，从could you后的字符继续判断*/
                continue;
            }
        }
         /*判断I是否独立（“独立”是指被空格或标点符号分隔开的单词）*/
        if(str1[i]=='I'&&((str1[i-1]<'a'||str1[i-1]>'z')&&(str1[i-1]<'A'||str1[i-1]>'Z'))&&((str1[i+1]<'a'||str1[i+1]>'z')&&(str1[i+1]<'A'||str1[i+1]>'Z'))){
            str1[i]='7';
        }
         /*判断me是否独立（“独立”是指被空格或标点符号分隔开的单词）*/
        if((str1[i]=='m'&&str1[i+1]=='e')&&((str1[i-1]<'a'||str1[i-1]>'z')&&(str1[i-1]<'A'||str1[i-1]>'Z'))&&((str1[i+2]<'a'||str1[i+2]>'z')&&(str1[i+2]<'A'||str1[i+2]>'Z'))){
            str1[i]='5';
            str1[i+1]='6';
            i++;
        }
        i++;
    }
    /*输出改变后的字符串,'8'转义为空，（'5''6'）转义为you，'7'转义为you*/
    printf("%s\nAI: ",str[b]);
    y=(int)strlen(str1);
    for(i=0;i<y;i++){
        if(str1[i]=='8')
            continue;
        else if(str1[i]=='5'&&str1[i+1]=='6'){
            printf("you");
            i++;
            continue;
        }
        else if(str1[i]=='7'){
            printf("you");
        }
        else
            printf("%c",str1[i]);
    }
    printf("\n");
    }
    return 0;
}
