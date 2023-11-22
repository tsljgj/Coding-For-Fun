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
		
		for(int i=first[u];i;i=nxt[i]){    //nxt[i]���Ϊ0 
			if(val[i]){
				int v=to[i];           //���u,�յ�v 
				if(vis[v]) continue;   //�˱��յ��ѷ��� 
				incf[v]=min(incf[u],val[i]);  //û�з��ʹ�����ô�Ƚ�Ŀǰ��ͨ�е���������ʹ˱ߵ����� 
				pre[v]=i;         //��¼����v��ıߵı�ţ�������   
				q.push(v);    
				vis[v]=1;        //������qwq     
				if(v==t) return 1; 
			}
		}
	}
	
	return 0;
}

void update(){
	int u=t;   //����
	while(u!=s){
		int i=pre[u];
		val[i]-=incf[t];    //incf[t]��Ĳ�������ͨ��������������incf[i] 
		val[i^1]+=incf[t]; 
		u=to[i^1]; //u=i�űߵ���� 
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
