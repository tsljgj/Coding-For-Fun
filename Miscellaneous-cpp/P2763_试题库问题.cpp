#include<bits/stdc++.h>
using namespace std;
const int N=1000,M=100000;
const int INF=1<<29;
int nxt[M],to[M],c[M],first[N];
int d[N],cur[N];
int cnt=1;
int n,s,t;
int maxflow;

void add(int u,int v,int w){
	c[++cnt]=w;  to[cnt]=v; nxt[cnt]=first[u]; first[u]=cnt;
	c[++cnt]=0;  to[cnt]=u; nxt[cnt]=first[v]; first[v]=cnt;
} 

bool bfs(){
	memset(d,-1,sizeof(d));
	queue<int> q;
	q.push(s); d[s]=0, cur[s]=first[s];
	
	while(q.size()){
		int u=q.front(); q.pop();
		for(int i=first[u];i;i=nxt[i]){
			int v=to[i];
			if(c[i]&&d[v]==-1){
				cur[v]=first[v];
				d[v]=d[u]+1;
				q.push(v);
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
		int v=to[i];
		cur[u]=i;
		int f=dfs(v,min(limit-flow,c[i]));
		if(!f) d[v]=-1;
		c[i]-=f, c[i^1]+=f, flow+=f;
	}
	
	return flow;
}

void dinic(){
	int flow=0;
	while(bfs())
		while(flow=dfs(s,INF)){
			maxflow+=flow;
		}
}


int main(){
	int n0,k;
	cin>>k>>n0;
	n=n0+k,s=0,t=n+1;
	
	for(int i=1;i<=k;i++){
		int k0;
		cin>>k0;
		add(n0+i,t,k0);
	}

	for(int i=1;i<=n0;i++){
		int num;
		cin>>num;
		for(int j=1;j<=num;j++){
			int cat;
			cin>>cat;
			add(i,n0+cat,1);
		}
	}
	
	for(int i=1;i<=n0;i++) add(s,i,1);

	
	dinic();
	
	for(int i=2;i<=cnt;i++){
		if(c[i]!=0&&to[i]==t) {
			cout<<"No Solution!"<<endl;
			return 0;
		}
	}
	
	for(int j=1;j<=k;j++){
		cout<<j<<": ";
		for(int i=2;i<=cnt;i++){
			if(c[i]==0&&to[i]==j+n0&&to[i^1]!=t) cout<<to[i^1]<<" ";
		}
		cout<<endl;
	}
	
}
		
