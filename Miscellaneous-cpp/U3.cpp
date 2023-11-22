#include<bits/stdc++.h>
#define mp make_pair
#define LL long long
using namespace std;
const int N=10010,E=200020;
int n,m,s,t;
vector<pair<int,int> > a[E];
bool done[220];
inline LL bfs(int u,LL in){
	if(u==t) return in;
	done[u]=true;
	vector<pair<int,int> >::iterator it;
	for(it=a[u].begin();it!=a[u].end();it++){
		int to=*it.first,space=*it.second;
		
		if(space!=0&&done[u]==0) continue;
		
		LL res=dfs(to,min(in,space));
		if(res>0){
			*it.second-=res;
			a[*it.first].second+=res;
		}
	} 
		
		
		
		
	}
}
int main(){
	cin>>n>>m>>s>>t;
	for(int i=1;i<=m;i++){
		int u,v,w;
		cin>>u>>v>>w;
		a[u].push_back(mp(v,w));
		a[v].push_back(mp(u,w));
	}
	
	LL out=0;
	while((out=bfs(s,1e18))!=0){
		memset(done,0,sizeof(done));
		ans+=out;
	}
	
	cout<<ans<<endl;
	return 0;
}
