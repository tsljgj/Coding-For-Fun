#include<bits/stdc++.h>
#define ll long long
#define mp make_pair
using namespace std;
int n,m;
ll dis[1520];
ll r[5020][5020][2];
vector<pair<ll,ll> > a[5020],b[5020];
set<pair<ll,ll> > q;
int main(){
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		dis[i]=1e30;
	}
	
	for(int i=1;i<=m;i++){
		int x,y,z;
		cin>>x>>y>>z;
		a[x].push_back(mp(y,z));
	}
	
	dis[1]=0;
	q.insert(mp(dis[1],1));
	
	while(!q.empty()){
		pair<ll,ll> u=*q.begin();
		q.erase(q.begin());
		
		if(u.first>dis[u.second]) continue;
		
		for(int i=0;i<a[u.second].size();i++){
			pair<ll,ll> e=a[u.second][i];
			
			if(dis[e.first]==e.second+u.first){
				r[u.second][e.first][0]++;
			}
			
			if(dis[e.first]>e.second+u.first){
				q.erase(mp(dis[e.first],e.first));
				dis[e.first]=e.second+u.first;
				q.insert(mp(dis[e.first],e.first));
				
				r[u.second][e.first][0]=1;
			}
			
		} 
	}
}
