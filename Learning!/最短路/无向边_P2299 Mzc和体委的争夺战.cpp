#include<bits/stdc++.h>
using namespace std;
int n,m;
set<pair<int,int> > q;
vector<pair<int,int> > a[2520];
int dis[2520];
int main(){
	
	
	cin>>n>>m;
	
	for(int i=1;i<=n;i++){
		dis[i]=1e30;
	}
	
	for(int i=1;i<=m;i++){
		int x,y,z;
		cin>>x>>y>>z;
		a[x].push_back(make_pair(y,z));
		a[y].push_back(make_pair(x,z));	
	
	}
	
	dis[1]=0;
	q.insert(make_pair(dis[1],1));
	
	while(!q.empty()){
		pair<int,int> u=*q.begin();
		q.erase(q.begin());
		
		for(int i=0;i<a[u.second].size();i++){
			if(dis[a[u.second][i].first]>a[u.second][i].second+u.first){
				q.erase(make_pair(dis[a[u.second][i].first],a[u.second][i].first));
				dis[a[u.second][i].first]=a[u.second][i].second+u.first;
				q.insert(make_pair(dis[a[u.second][i].first],a[u.second][i].first));
			}
		}
		
	}
	
	cout<<dis[n]<<endl;
	return 0;
}
