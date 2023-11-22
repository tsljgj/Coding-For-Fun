#include<bits/stdc++.h>
#define LL long long
using namespace std;
const int N=10000,M=100000;
const int INF=1<<29;
int n,s,t;
int to[M],nxt[M],first[N];
LL val[M];
int cnt=1;
int d[N],cur[N];
int ans[3000][3000];

void add(int u,int v,int w){
	to[++cnt]=v; val[cnt]=w; nxt[cnt]=first[u]; first[u]=cnt;
	to[++cnt]=u; val[cnt]=0; nxt[cnt]=first[v]; first[v]=cnt;
}

bool bfs(){
	memset(d,-1,sizeof(d));
	queue<int> q;
	cur[s]=first[s], d[s]=0, q.push(s);
	
	while(q.size()){
		int u=q.front(); q.pop();
		for(int i=first[u];i;i=nxt[i]){
			int v=to[i];
			if(d[v]==-1&&val[i]){
				q.push(v);  //别忘了存新的 
				d[v]=d[u]+1;
				cur[v]=first[v];
				if(v==t) return 1;
			}
		}
	}
	
	return 0;
}

LL dfs(int u,LL limit){
	if(u==t) return limit;
	
	LL flow=0;
	for(int i=cur[u];i&&flow<limit;i=nxt[i]){
		cur[u]=i;
		int v=to[i];
		
		if(val[i]!=0&&d[v]==d[u]+1){
			LL f=dfs(v,min(limit-flow,val[i]));  //更当前边的容量比 
			if(!f) d[v]=-1;
			
			val[i]-=f;
			val[i^1]+=f;
			flow+=f;
		}
	}
	
	return flow;
}

void dinic(){
	int flow=0;
	while(bfs())
		while(flow=dfs(s,INF)){} 
		//括号必须要加，不然return会写入 
	return;
}

int main(){
	int m0,n0;
	cin>>m0>>n0;
	n=m0+n0,s=0,t=n+1;
	
	for(int i=1;i<=m0;i++){
		for(int j=m0+1;j<=n;j++){
			add(i,j,1);
		}
	}
	
	int w[3000];
	for(int i=1;i<=m0;i++){
		cin>>w[i];
		add(s,i,w[i]);
	}
	
	for(int i=m0+1;i<=n;i++){
		int x;
		cin>>x;
		add(i,t,x);
	}
	
	dinic();
	
	int cnt2=0,k=0;
	for(int i=1;i<=m0;i++){
		for(int j=1;j<=n0;j++){
			cnt2+=2;
			if(val[cnt2]==0){
				w[i]--;
				ans[i][j]=to[cnt2]-m0;
			}	
		}
		if(w[i]!=0){
			cout<<0<<endl;
			return 0;
		}
	}
	
	cout<<1<<endl;

	for(int i=1;i<=m0;i++){
		for(int j=1;j<=n0;j++){
			if(ans[i][j])
				cout<<ans[i][j]<<" ";
		}
		cout<<endl;
	}
	
	return 0;	
} 
