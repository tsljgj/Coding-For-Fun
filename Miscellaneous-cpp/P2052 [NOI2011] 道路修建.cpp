#include<bits/stdc++.h>
using namespace std;
const int MAXN=1000020, MAXM=2000040;
int n;
int to[MAXM], nxt[MAXM], val[MAXM], first[MAXN];
int tot=0;
//int size[MAXN];
long long ans=0;
void add(int u,int v,int c){
	to[++tot]=v, nxt[tot]=first[u], val[tot]=c, first[u]=tot;
}

int dfs(int u,int fa){
//	size[u]=1;
	int sz=1;
	for(int i=first[u];i;i=nxt[i]){
		int v=to[i];
		if(v!=fa){
			int t=dfs(v,u);
			sz+=t;
			ans+=(long long)val[i]*abs(n-2*t);
		}
	}
	
	return sz;
}
int main(){
	cin>>n;
	for(int i=1;i<n;i++){
		int u,v,c;
		cin>>u>>v>>c;
		add(u,v,c);
		add(v,u,c);
	}
	
	dfs(1,0);
	
	cout<<ans<<endl;
	return 0;
	
} 
