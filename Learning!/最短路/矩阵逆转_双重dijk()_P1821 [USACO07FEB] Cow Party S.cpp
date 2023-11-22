#include<bits/stdc++.h>
#define mp make_pair
using namespace std;
int n,m,x;
int dis1[1020],dis2[1020];
vector<pair<int,int> > a[100020],b[100020];
set<pair<int,int> > q;
int maxn=0;
int main(){
	cin>>n>>m>>x;
	for(int i=1;i<=n;i++){
		dis1[i]=1e30;
		dis2[i]=1e30;
	}
	
	for(int i=1;i<=m;i++){
		int x,y,z;
		cin>>x>>y>>z;
		a[x].push_back(mp(y,z));
		b[y].push_back(mp(x,z));
	}
	
	dis1[x]=0;
	q.insert(mp(dis1[x],x));
	
	while(!q.empty()){
		pair<int,int> u=*q.begin();
		q.erase(q.begin());
		if(u.first>dis1[u.second]) continue;
		
		for(int i=0;i<a[u.second].size();i++){
			pair<int,int> e=a[u.second][i];
			if(dis1[e.first]>e.second+u.first){
				q.erase(mp(dis1[e.first],e.first));
				dis1[e.first]=e.second+u.first;
				q.insert(mp(dis1[e.first],e.first));	
			}
		}
	}
	
	
	dis2[x]=0;
	q.insert(mp(dis2[x],x));
	while(!q.empty()){
		pair<int,int> u=*q.begin();
		q.erase(q.begin());
		if(u.first>dis2[u.second]) continue;
		
		for(int i=0;i<b[u.second].size();i++){
			pair<int,int> e=b[u.second][i];
			if(dis2[e.first]>e.second+u.first){
				q.erase(mp(dis2[e.first],e.first));
				dis2[e.first]=e.second+u.first;
				q.insert(mp(dis2[e.first],e.first));	
			}
		}
	}
	
	for(int i=1;i<=n;i++){
		maxn=max(maxn,dis1[i]+dis2[i]);
	}
	
	cout<<maxn;
	return 0;
	
}
