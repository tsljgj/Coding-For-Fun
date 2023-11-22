//EK
#include<bits/stdc++.h>
#define LL long long 
using namespace std;
const int N=1020,M=10020;
const LL INF=1e18;
int n,m,s,t;
int to[M],nxt[M],first[N];
int cnt=1;
LL val[M];
LL maxflow=0;

void add(int u,int v,int w){
	val[++cnt]=w;
	to[cnt]=v;
	nxt[cnt]=first[u];
	first[u]=cnt;
}

bool vis[N];
LL incf[N];
int pre[N];

bool bfs(){
	memset(vis,0,sizeof(vis));
	queue<int> q;
	q.push(s);
	vis[s]=1;
	incf[s]=INF;
	
	while(q.size()){
		int u=q.front();
		q.pop();
		
		for(int i=first[u];i;i=nxt[i]){    //nxt[i]最后为0 
			if(val[i]){
				int v=to[i];           //起点u,终点v 
				if(vis[v]) continue;   //此边终点已访问 
				incf[v]=min(incf[u],val[i]);  //没有访问过，那么比较目前可通行的最大流量和此边的容量 
				pre[v]=i;         //记录到达v点的边的编号，回溯用   
				q.push(v);    
				vis[v]=1;        //别忘了qwq     
				if(v==t) return 1; 
			}
		}
	}
	
	return 0;
}

void update(){
	int u=t;   //回溯
	while(u!=s){
		int i=pre[u];
		val[i]-=incf[t];    //incf[t]存的才是最大可通过的流量，不是incf[i] 
		val[i^1]+=incf[t]; 
		u=to[i^1]; //u=i号边的起点 
	} 
	maxflow+=incf[t];
} 
int main(){
	cin>>n>>m>>s>>t;
	while(m--){
		int u,v,w;
		cin>>u>>v>>w;
		add(u,v,w);
		add(v,u,0);
	}
	
	while(bfs()){
		update();
	}
	
	cout<<maxflow<<endl;
	return 0;
}
