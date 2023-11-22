#include<bits/stdc++.h>
using namespace std;
void add(int u,int v,int w){
	to[++tot]=v, nxt[cnt]=head[u], val[cnt]=w, head[u]=tot;
}
int main(){
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		int u,v,w;
		cin>>u>>v>>w;
		add(u,v,-w); 
	}
	cin>>s>>t;
}
