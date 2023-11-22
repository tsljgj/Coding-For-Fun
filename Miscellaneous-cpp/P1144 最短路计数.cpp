#include<bits/stdc++.h>//n<=1000000, m<=2000000
using namespace std;
const int MAXN=1000020, MAXM=2000020, MOD=100003;
int n,m;
vector<int> a[MAXN];
bool vis[MAXN];
int minn[MAXN],ans[MAXN];
void bfs(int s){
	queue<int> q;
	q.push(s); vis[s]=1, ans[s]=1;
	while(!q.empty()){
		int u=q.front();
		q.pop();
		for(int i=0;i<a[u].size();i++){
			int v=a[u][i];
			if(!vis[v]){
				vis[v]=1;
				q.push(v);
				minn[v]=minn[u]+1;
				ans[v]+=ans[u];
			}
			else if(minn[v]==minn[u]+1){
				ans[v]=(ans[u]+ans[v])%MOD;
			}
		}
	}
}

int main(){
	cin>>n>>m;
	for(int i=1;i<=m;i++){
		int u,v;
		cin>>u>>v;
		a[u].push_back(v);
		a[v].push_back(u);
	}
	
	int s=1;
	bfs(s);
	
	for(int i=1;i<=n;i++) cout<<ans[i]<<endl;
	return 0;
}
