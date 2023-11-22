#include<bits/stdc++.h>
using namespace std;
const int N=120,M=3000;
const int INF=120;
int m,n,s,t;
int to[M],nxt[M],c[M],first[N];
int cnt=1;
int d[N],cur[N];
int maxflow=0;

void add(int u,int v,int w){
	c[++cnt]=w; to[cnt]=v; nxt[cnt]=first[u]; first[u]=cnt;
	c[++cnt]=0; to[cnt]=u; nxt[cnt]=first[v]; first[v]=cnt;
}

bool bfs(){
	memset(d,-1,sizeof(d));	
	queue<int> q;
	cur[s]=first[s],q.push(s),d[s]=0;
	
	while(q.size()){
		int u=q.front(); q.pop();
		for(int i=first[u];i;i=nxt[i]){
			int v=to[i];
			if(d[v]==-1&&c[i]){
				q.push(v);           //易漏 
				d[v]=d[u]+1;
				cur[v]=first[v];
				if(v==t) return 1; 
			}
		}
	}
	
	return 0;
}

int dfs(int u,int limit){
	if(u==t) return limit;
	int flow=0;
	for(int i=cur[u];i&&limit>flow;i=nxt[i]){
		cur[u]=i;       //别忘了优化qwq 
		int v=to[i];
		if(c[i]&&d[v]==d[u]+1){
			int f=dfs(v,min(c[i],limit-flow));
			if(!f) d[v]=-1;
			c[i]-=f,c[i^1]+=f,flow+=f;
		}
		
	}
	return flow;
}

void dinic(){
	int flow=0;
	while(bfs()){
		while(flow=dfs(s,INF)){
			maxflow+=flow;
		}
	}
}

int main(){
	cin>>m>>n;
	s=0,t=n+1;
	for(int i=1;i<=n;i++){
		if(i>m) add(i,t,1);
		else add(s,i,1);
	}
	
	while(1){
		int a,b;
		cin>>a>>b;
		if(a!=-1) add(a,b,1);
		else break;
	}
	
	dinic();
	cout<<maxflow<<endl;
	for(int i=2;i<cnt;i+=2) {
		if(c[i]==0&&to[i]<=n&&to[i]>m) cout<<to[i^1]<<" "<<to[i]<<endl; 
	}
	return 0;	
}
