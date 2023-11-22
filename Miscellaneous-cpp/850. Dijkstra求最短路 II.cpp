#include<bits/stdc++.h>
#define mp make_pair
#define fi first
#define se second
using namespace std;
const int MAXN=200020, MAXM=200020*2;
int n,m;
vector<pair<int,int> > a[MAXM];
int dis[MAXN];
bool vis[MAXN];
int main(){
	cin>>n>>m;
	for(int i=1;i<=m;i++){
		int u,v,w;
		cin>>u>>v>>w;
		a[u].push_back(mp(v,w));
	}
	
	vis[1]=0;
	priority_queue<pair<int,int> > q;            //æ‡¿Î£¨±‡∫≈ 
	q.push(mp(0,1));
	memset(dis,-1,sizeof(dis));
	
	while(q.size()){
		pair<int,int> u=q.top();
		q.pop();
		if(vis[u.se]) continue;
		vis[u.se]=1;
		dis[u.se]=-u.fi;
		for(int i=0;i<a[u.se].size();i++){
			pair<int,int> e=a[u.se][i];
			if(vis[e.fi]) continue;
			q.push(mp(-e.se-dis[u.se],e.fi));
		}
	}
	
	cout<<dis[n]<<endl;
//	for(int i=1;i<=n;i++){
//		cout<<dis[i]<<" ";
//	} 
	
	
	
}
