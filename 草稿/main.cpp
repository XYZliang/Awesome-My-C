#include<iostream>
#include<algorithm>
#include<cmath>
using namespace std;
const int N =31;
int n;
int x[N];
int y[N];
int r[N];
bool vis[N];
int ans;

void dfs(int step,int sum){
    if(step==n){
        ans=max(ans,sum);
        return;
    }
    for(int i=1;i<=n;i++){
        if(!vis[i]){
            int tmp=r[i];
            for(int j=1;j<=n;j++){
               if(vis[j] && j!=i && ((pow(x[i]-x[j],2)+pow(y[i]-y[j],2))<pow(r[i]+r[j],2)) )
                    r[i]=0;
            }
            vis[i]=true;
            dfs(step+1,sum+r[i]*r[i]);
            vis[i]=false;
            r[i]=tmp;
        }
    }

}
int main(){
    cin>>n;
    for(int i=1;i<=n;i++)
        cin>>x[i]>>y[i]>>r[i];
    dfs(0,0);
    cout<<ans<<endl;
}
