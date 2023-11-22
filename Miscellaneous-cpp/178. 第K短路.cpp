#include<bits/stdc++.h>
#define mp make_pair
using namespace std;
const int MAXN=1020, MAXM=100020;
vector<pair<int,int> > a[MAXM];
int dis[MAXN], vis[MAXN];
int dist[MAXN];
int vistime[MAXN];
int n,m;
int s,t,k;
int main(){
    cin>>n>>m;
    for(int i=1;i<=m;i++){
        int u,v,w;
        cin>>u>>v>>w;
        a[u].push_back(mp(w,v));
    }
    cin>>s>>t>>k;
    
    priority_queue<pair<int,int> > q;
    q.push(mp(0,t));
    memset(dis,0x3f,sizeof(dis));
    dis[t]=0;
    
    while(q.size()){
        int u=q.top().second;
        q.pop();
        if(vis[u]) continue;
        vis[u]=1;
        for(int i=0;i<a[u].size();i++){
            int v=a[u][i].second;
            if(dis[v]>dis[u]+a[u][i].first) {
                dis[v]=dis[u]+a[u][i].first;
                q.push(mp(-dis[v],v));
            }
        }
    }
    
    priority_queue<pair<int,int> > qq;
    qq.push(mp(-dis[s],s));
    if(s==t) k++;
    if(dis[s]==dis[0]) {
        cout<<"-1"<<endl;
        return 0;
    }
    while(qq.size()){
        int u=qq.top().second, d=-dis[u]-qq.top().first;
        qq.pop();
        vistime[u]++;
        if(vistime[t]==k) {
            cout<<d<<endl;
            return 0;
        }
        
        for(int i=0;i<a[u].size();i++){
            int v=a[u][i].second;
            if(vistime[v]!=k) qq.push(mp(-d-a[u][i].first-dis[v],v));
        }
    }
    
    cout<<"-1"<<endl;
}
