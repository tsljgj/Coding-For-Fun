#include<bits/stdc++.h>
#define LL long long
using namespace std;
const int N=10010, E=200010;
int n,m,s,t;
LL ans=0;
LL cnt=1,to[E],nxt[E],val[E],first[N];

inline void addE(int u,int v,LL w){
	to[++cnt]=v;
	val[cnt]=w;
	nxt[u]=first[u];
	first[u]=cnt;	
}

LL dep[N],q[N],l,r;
LL bfs(int u,LL in){
	if(u==t) return in;
	LL out=0;
	for(p=first[u];;p=nxt[p]){
		int v=to[p];
		if(!val[p]&&dep[v]==dep[u]+1){
			LL res=min(v,min(in,val[p]));
			val[p]-=res;
			val[p^1]-=res;
			in-=res;
			out+=res;
		}
	}
	
	if(!out) dep[u]=0;
	return out;
} 

int main(){
	cin>>n>>m>>s>>t;
	for(int i=1;i<=m;i++){
		int u,v;
		LL w;
		cin>>u>>v>>w;
		addE(u,v,w);
		addE(v,u,0);
	}
	
	while(bfs()){
		ans+=bfs(s,1e18);
	}
	cout<<ans<<endl;
	return 0;
} 
