#include<bits/stdc++.h>
#define mp make_pair
#define fi first
#define se second
using namespace std;
const int MAXN=200020, MAXM=200020;
vector<pair<int,int> > a[MAXM], b[MAXM];
set<pair<int,int> > q;
bool vis[MAXN];
int dis[MAXN];
int n,m,s,t,k;
int cnt=0;

void dijk(){
	q.insert(mp(0,t));
	while(q.size()){
		pair<int,int> u=*q.begin();
		q.erase(q.begin());
		if(vis[u.se]) continue;
		vis[u.se]=1, dis[u.se]=u.fi;
		for(int i=0;i<a[u.se].size();i++){
			pair<int,int> e=a[u.se][i];
			if(vis[e.fi]) continue;
			q.insert(mp(e.se+u.fi,e.fi));
		}
	}
}

int Astar(){
	q.insert(mp(dis[s],s));
	while(q.size()){
		pair<int,int> u=*q.begin();
		q.erase(q.begin());
		if(u.se==t) cnt++;
		if(cnt==k) return u.fi-dis[u.se];         //dist=u.se-dis[u.se]
		for(int i=0;i<b[u.se].size();i++){
			pair<int,int> e=b[u.se][i];
			if(dis[e.fi]!=-1)q.insert(mp(u.se-dis[u.se]+e.se+dis[e.fi],e.fi));
		}
	}
	return -1;
}

int main(){
	cin>>n>>m;
	for(int i=1;i<=m;i++){
		int u,v,w;
		cin>>u>>v>>w;
		a[v].push_back(mp(u,w));
		b[u].push_back(mp(v,w)); 
	} 
	cin>>s>>t>>k;
	if(s==t) k++;
	
	memset(dis,-1,sizeof(dis));
	dijk();
	
	cout<<Astar()<<endl;
}
