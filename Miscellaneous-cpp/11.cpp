#include<cstdio>
#include<queue>
#include<cstring>
using namespace std;
priority_queue<pair<int,int>,vector<pair<int,int> >,greater<pair<int,int> > >q;
struct node{
    int to,val;
}add;
vector<node>v[101];
struct Node{
    int from,to,val;
}d[101];
bool f[101];
inline void ADD(int x,int y,int z){
    add.to=y;
    add.val=z;
    v[x].push_back(add);
}
int m,n,x,y,z,h,ans,change1,change2,dd[101],Road_Recorder[101],last=1;
inline void Return(int xx){
    if(d[xx].from==0)return;
    Return(d[xx].from);
    Road_Recorder[++h]=xx;
}
int main(){
	freopen("P2176_10.in","r",stdin);
    scanf("%d%d",&n,&m);
    for(register int i=1;i<=m;i++){
        scanf("%d%d%d",&x,&y,&z);
        ADD(x,y,z);
        ADD(y,x,z);
        //建图
    }
    /* 首先跑一边Dij，算出原始最短路 ↓*/
    memset(d,0x7f,sizeof(d));
    d[1].val=d[1].from=0;
    q.push(make_pair(0,1));
    while(!q.empty()){
        x=q.top().second;
        q.pop();
        if(f[x])continue;
        f[x]=1;
        for(register int i=0;i<v[x].size();i++){
            if(d[v[x][i].to].val>d[x].val+v[x][i].val){
                d[v[x][i].to].val=d[x].val+v[x][i].val;
                d[v[x][i].to].from=x;
                q.push(make_pair(d[v[x][i].to].val,v[x][i].to));
            }
        }
    }
    Return(n);//提取记录的路径
    for(register int i=1;i<=h;i++){//枚举改变的路径
        for(register int j=0;j<v[last].size();j++){//更改长度
            if(v[last][j].to==Road_Recorder[i]){
                v[last][j].val<<=1;
                change1=j;
                break;
            }
        }
        for(register int j=0;j<v[Road_Recorder[i]].size();j++){
            if(v[Road_Recorder[i]][j].to==last){
                v[Road_Recorder[i]][j].val<<=1;
                change2=j;
                break;
            }
        }
        /*算出新的最短路↓*/
        memset(dd,0x7f,sizeof(dd));
        memset(f,0,sizeof(f));
        dd[1]=0;
        q.push(make_pair(0,1));
        while(!q.empty()){
            x=q.top().second;
            q.pop();
            if(f[x])continue;
            f[x]=1;
            for(register int j=0;j<v[x].size();j++){
                if(dd[v[x][j].to]>dd[x]+v[x][j].val){
                    dd[v[x][j].to]=dd[x]+v[x][j].val;
                    q.push(make_pair(dd[v[x][j].to],v[x][j].to));
                }
            }
        }
        if(dd[n]-d[n].val>ans)ans=dd[n]-d[n].val;//比较答案
        v[last][change1].val>>=1;
        v[Road_Recorder[i]][change2].val>>=1;//路径还原
        last=Road_Recorder[i];//本次的目标点会成为下次的起点
        //last初值为1
    }
    printf("%d",ans);
}
