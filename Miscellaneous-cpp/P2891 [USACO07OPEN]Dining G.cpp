#include<bits/stdc++.h>
using namespace std;
const int N=1000,M=30000;
const int INF=1<<29;
int C,F,D,n;
int s,t;
int to[M],nxt[M],c[M],first[N];
int d[N],cur[N];
int cnt=1;
int ans=0;

void add(int u,int v,int w){
	c[++cnt]=w; to[cnt]=v; nxt[cnt]=first[u]; first[u]=cnt;
	c[++cnt]=0; to[cnt]=u; nxt[cnt]=first[v]; first[v]=cnt;
}

bool bfs(){
	memset(d,-1,sizeof(d));
	queue<int> q;
	q.push(s), d[s]=0, cur[s]=first[s];
	
	while(q.size()){
		int u=q.front(); q.pop();
		for(int i=first[u];i;i=nxt[i]){
			int v=to[i];
			if(c[i]!=0&&d[v]==-1) {   //c[v]*1
				q.push(v);
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
		cur[u]=i;        //*
		int v=to[i];
		if(d[v]==d[u]+1&&c[i]!=0){
			int f=dfs(v,min(limit-flow,c[i]));
			if(!f) d[v]=-1;
			c[i]-=f, c[i^1]+=f, flow+=f;
		}
	}
	
	return flow;
}

void dinic(){
	while(bfs())
		while(dfs(s,INF)){}
	return;
}
int main(){
	cin>>C>>F>>D;
	n=F+2*C+D,s=0,t=n+1;
	
	for(int i=1;i<=C;i++) add(F+i,F+C+i,1);
	for(int i=1;i<=F;i++) add(s,i,1);
	for(int i=1;i<=D;i++) add(F+2*C+i,t,1);
	for(int i=1;i<=C;i++){
		int fo,dr;
		cin>>fo>>dr;
		for(int j=1;j<=fo;j++){
			int ch;
			cin>>ch;
			add(ch,F+i,1);
		}
		for(int j=1;j<=dr;j++){
			int ch;
			cin>>ch;
			add(F+C+i,F+2*C+ch,1);
		}
	}
		
	dinic();
	
	for(int i=2;i<=cnt;i+=2){
		if(c[i]==0&&to[i]>F+C&&to[i]<=F+2*C){
			ans++;
		}
	}
	
	cout<<ans<<endl;
	return 0;
}
