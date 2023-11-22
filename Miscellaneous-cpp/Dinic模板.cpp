//dinic
#include<bits/stdc++.h>
#define LL long long
using namespace std;
const int N=1020,M=100020;
const LL INF=1<<29;        //INF不能开太大 ??
int n,m,s,t;
int cnt=1;
int to[M],nxt[M],first[N];
int d[N],cur[N];   //cur:弧优化 
LL c[M];
LL maxflow=0;

void add(int u,int v,int w){
	c[++cnt]=w; to[cnt]=v; nxt[cnt]=first[u]; first[u]=cnt;
	c[++cnt]=0; to[cnt]=u; nxt[cnt]=first[v]; first[v]=cnt;
}

bool bfs(){      //只分层和做弧优化的初始化 
	memset(d,-1,sizeof(d));   //所有点尚未分层 
	queue<int> q;
	q.push(s), cur[s]=first[s], d[s]=0;   //s是第0层 
	while(q.size()){
		int u=q.front(); q.pop();
		for(int i=first[u];i;i=nxt[i]){
//			if(vis[i])   dinic不用担心重复访问->分层图
			int v=to[i];
			if(d[v]==-1&&c[i]){   //没分过层（自然也没有visit过）且还可以流流量 
				q.push(v);
				d[v]=d[u]+1;     //分层 
				cur[v]=first[v];
				if(v==t) return 1;    //已经到终点了说明所有点已经分层完毕，结束 
			} 
		} 
	}
	return 0;   //若始终没有到达终点则说明残余网络不能到达t,所以直接停止bfs 
}

int dfs(int u,LL limit){
	if(u==t) return limit;
	
	LL flow=0;
	for(int i=cur[u];i&&flow<limit/*u点若还有流量就继续*/;i=nxt[i]){
		cur[u]=i;     //对于一次DFS而言，它确定的层次图中每条边若已经被走完了，
					//那么它就不可能再带来增广，下一次就直接从这条最后没走完的边走就可以了
		int v=to[i];
		
		if(c[i]!=0&&d[v]==d[u]+1){
			int f=dfs(v,min(c[i],limit-flow));   //从v点起,比较是当前点能够提供的流量少还是通道能承受的流量少 
			
			if(!f) d[v]=-1;   //走不通啦，关掉 
			
			c[i]-=f;
			c[i^1]+=f;
			flow+=f;   //之前就有限制，不会爆limit
		}
		
	}
	
	return flow;
}
void dinic(){
	int flow=0;    //及记一次dfs后获得的总流量 
	while(bfs()){     //不断分层 
		while(flow=dfs(s,INF)){   //分完层后开始深搜，从s开始，给与无限的流量 
			maxflow+=flow;
//			cout<<"maxflow="<<maxflow<<endl;
		}
	}
}
int main(){
	cin>>n>>m>>s>>t;
	while(m--){
		int u,v,w;
		cin>>u>>v>>w;
		add(u,v,w);
	}
	
	dinic();
	cout<<maxflow<<endl;
	
	return 0;
}
