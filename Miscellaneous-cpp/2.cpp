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
int ans[300][300];

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
//			cout<<"maxflow="<<maxflow<<endl;
		}
	}
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
	
	int w;
	for(int i=1;i<=m0;i++){
		cin>>w;
		add(s,i,w);
	}
	
	for(int i=m0+1;i<=n;i++){
		cin>>w;
		add(i,t,w);
	}
	
	dinic();
	
	int cnt2=0,k=0;
	for(int i=1;i<=m0;i++){
		for(int j=1;j<=n0;j++){
			cnt2+=2;
			if(c[cnt2]==0){
				k=1;
				ans[i][j]=to[cnt2]-m0;
			}
		}
	}
	
	cout<<k<<endl;
	for(int i=1;i<=m0;i++){
		for(int j=1;j<=n0;j++){
			if(ans[i][j])
				cout<<ans[i][j]<<" ";
		}
		cout<<endl;
	}
	
	return 0;	
}
