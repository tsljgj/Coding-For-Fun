#include<bits/stdc++.h>
#define MAXN 100010
using namespace std;
const int INF=0x3f;
//priority_queue<pair<int,int>, vector<pair<int,int> >,greater<pair<int,int> > > q;
set<pair<int,int> > q;
vector<pair<int,int> > a[MAXN];
int n,m,s,dis[MAXN];
int main(){
	
	memset(dis,INF,sizeof(dis));
	
	cin>>n>>m>>s;
	for(int i=1;i<=m;i++){
		int x,y,z;
		cin>>x>>y>>z;
		a[x].push_back(make_pair(y,z));
	}
	
	dis[s]=0;                             //初始化两步不要漏 
	q.insert(make_pair(dis[s],s));
	
	while(!q.empty()){
		pair<int,int> u=*q.begin();          //u必须是pair<>,e而q.begin()是指针 
		q.erase(q.begin());
        //		if(u.first>dis[u.second]) continue;
		
		for(int i=0;i<a[u.second].size();i++){
			if(dis[a[u.second][i].first]>a[u.second][i].second+dis[u.second]){
				
				q.erase(make_pair(dis[a[u.second][i].first],a[u.second][i].first));
				
				dis[a[u.second][i].first]=a[u.second][i].second+dis[u.second];
				
				q.insert(make_pair(dis[a[u.second][i].first],a[u.second][i].first));
				
			}
		}
	}
	
	for(int i=1;i<=n;i++){
		cout<<dis[i]<<" ";
	}
} 
