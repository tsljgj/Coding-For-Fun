#include<bits/stdc++.h>
//10 10
//3 8
//2 3
//2 5
//5 9
//5 9
//2 3
//3 9
//4 8
//2 10
//4 9
using namespace std;
const int MAXN=30020;
int n,m;
int nxt[MAXN], to[MAXN], first[MAXN], in[MAXN];                //next不能写，改成nxt 
int tot=0, cnt=0;
int a[MAXN];
bitset<MAXN> f[MAXN];

void add(int u,int v){
	to[++tot]=v, nxt[tot]=first[u], first[u]=tot;
	in[v]++;
}

queue<int> q;
void toposort(){
	for(int i=1;i<=n;i++) if(in[i]==0) q.push(i);
	while(!q.empty()){
		int u=q.front(); a[++cnt]=u; q.pop();
		for(int i=first[u];i;i=nxt[i]){
			int v=to[i];
			in[v]--;
			if(in[v]==0) q.push(v);
		}
	}
}

int main(){
	cin>>n>>m;
	for(int i=1;i<=m;i++){
		int u,v;
		cin>>u>>v;
		add(u,v);
	}
	
	toposort();
	
	for(int i=cnt;i>=1;i--){
		int u=a[i];
		f[u].reset(), f[u][u]=1;
		for(int j=first[u];j;j=nxt[j]){                    //***倒拓扑序，算那个点能到哪些地方, 有点像dp 
			int v=to[j];
			f[u]|=f[v];
		}
	}
	
	for(int i=1;i<=n;i++) cout<<f[i].count()<<endl;
	return 0;
}
