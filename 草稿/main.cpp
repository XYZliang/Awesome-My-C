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
