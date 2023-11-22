#include<bits/stdc++.h>

#define mp make_pair
#define fi first
#define se second

using namespace std;

const int MAXN=1020, MAXM=100020;

int n,m,s,t,k;

int head1[MAXN], nxt1[MAXM], to1[MAXM], val1[MAXM], tot1=0;
int head2[MAXN], nxt2[MAXM], to2[MAXM], val2[MAXM], tot2=0;

int dis[MAXN], vis[MAXN];

void add1(int u,int v,int w){
    to1[++tot1]=v, nxt1[tot1]=head1[u], val1[tot1]=w, head1[u]=tot1;
}
void add2(int u,int v,int w){
    to2[++tot2]=v, nxt2[tot2]=head2[u], val2[tot2]=w, head2[u]=tot2;
}

void dijk(int start){
    memset(dis,0x3f,sizeof(dis));
    set<pair<int,int> > q;

    dis[t]=0;
    q.insert(mp(0,start));
    
    while(q.size()){
        pair<int,int> u=*q.begin();
        q.erase(q.begin());
        
        if(vis[u.se]) continue;
        vis[u.se]=1;
        
        for(int i=head1[u.se];i;i=nxt1[i]){
            if(dis[to1[i]]>dis[u.se]+val1[i]){
                dis[to1[i]]=dis[u.se]+val1[i];
                q.insert(mp(dis[to1[i]],to1[i]));
            }
        }
    }
}

int Astar(){
    if(dis[s]==0x3f3f3f3f) return -1;
    
    if(s==t) k++;

    set<pair<int,int> > q;
    q.insert(mp(dis[s],s));
    memset(vis,0,sizeof(vis));
    
    while(q.size()){
        pair<int,int> u=*q.begin();
        q.erase(q.begin());
        vis[u.se]++;
        int actual_dis=u.fi-dis[u.se];
        
        if(u.se==t) cout<<actual_dis<<endl;

        if(vis[t]==k) return actual_dis;
        
        for(int i=head2[u.se];i;i=nxt2[i]){
            if(vis[to2[i]]<=k) q.insert(mp(actual_dis+val2[i]+dis[to2[i]],to2[i]));
        }
    }
    
    return -1;
}

int main(){
    cin>>n>>m;
    for(int i=1;i<=m;i++) {
        int u,v,w;
        cin>>u>>v>>w;
        add1(v,u,w);
        add2(u,v,w);
    }
    
    cin>>s>>t>>k;
    
    dijk(t);
    
    cout<<Astar()<<endl;

    return 0;
}
