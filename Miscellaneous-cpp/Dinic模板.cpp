//dinic
#include<bits/stdc++.h>
#define LL long long
using namespace std;
const int N=1020,M=100020;
const LL INF=1<<29;        //INF���ܿ�̫�� ??
int n,m,s,t;
int cnt=1;
int to[M],nxt[M],first[N];
int d[N],cur[N];   //cur:���Ż� 
LL c[M];
LL maxflow=0;

void add(int u,int v,int w){
	c[++cnt]=w; to[cnt]=v; nxt[cnt]=first[u]; first[u]=cnt;
	c[++cnt]=0; to[cnt]=u; nxt[cnt]=first[v]; first[v]=cnt;
}

bool bfs(){      //ֻ�ֲ�������Ż��ĳ�ʼ�� 
	memset(d,-1,sizeof(d));   //���е���δ�ֲ� 
	queue<int> q;
	q.push(s), cur[s]=first[s], d[s]=0;   //s�ǵ�0�� 
	while(q.size()){
		int u=q.front(); q.pop();
		for(int i=first[u];i;i=nxt[i]){
//			if(vis[i])   dinic���õ����ظ�����->�ֲ�ͼ
			int v=to[i];
			if(d[v]==-1&&c[i]){   //û�ֹ��㣨��ȻҲû��visit�����һ����������� 
				q.push(v);
				d[v]=d[u]+1;     //�ֲ� 
				cur[v]=first[v];
				if(v==t) return 1;    //�Ѿ����յ���˵�����е��Ѿ��ֲ���ϣ����� 
			} 
		} 
	}
	return 0;   //��ʼ��û�е����յ���˵���������粻�ܵ���t,����ֱ��ֹͣbfs 
}

int dfs(int u,LL limit){
	if(u==t) return limit;
	
	LL flow=0;
	for(int i=cur[u];i&&flow<limit/*u�������������ͼ���*/;i=nxt[i]){
		cur[u]=i;     //����һ��DFS���ԣ���ȷ���Ĳ��ͼ��ÿ�������Ѿ��������ˣ�
					//��ô���Ͳ������ٴ������㣬��һ�ξ�ֱ�Ӵ��������û����ı��߾Ϳ�����
		int v=to[i];
		
		if(c[i]!=0&&d[v]==d[u]+1){
			int f=dfs(v,min(c[i],limit-flow));   //��v����,�Ƚ��ǵ�ǰ���ܹ��ṩ�������ٻ���ͨ���ܳ��ܵ������� 
			
			if(!f) d[v]=-1;   //�߲�ͨ�����ص� 
			
			c[i]-=f;
			c[i^1]+=f;
			flow+=f;   //֮ǰ�������ƣ����ᱬlimit
		}
		
	}
	
	return flow;
}
void dinic(){
	int flow=0;    //����һ��dfs���õ������� 
	while(bfs()){     //���Ϸֲ� 
		while(flow=dfs(s,INF)){   //������ʼ���ѣ���s��ʼ���������޵����� 
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
