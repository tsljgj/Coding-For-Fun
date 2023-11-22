#include<bits/stdc++.h>
#define mp make_pair
#define pi pair<int,int>
using namespace std;
int n,m,s;
set<pi > q;
vector<pi > a[500020];
int dis[10010];
int main(){
	cin>>n>>m>>s;
	for(int i=1;i<=n;i++) dis[i]=(1<<31)-1;
	for(int i=1;i<=m;i++){
		int x,y,z;
		cin>>x>>y>>z;
		a[x].push_back(mp(y,z));
	}
	
	dis[s]=0;
	q.insert(mp(dis[s],s));
	
	while(!q.empty()){
		pi u=*q.begin();
		q.erase(q.begin());
		
		for(int i=0;i<a[u.second].size();i++){
			pi e=a[u.second][i];
			
			if(dis[e.first]>e.second+u.first){
				q.erase(mp(dis[e.first],e.first));
				dis[e.first]=e.second+u.first;
				q.insert(mp(dis[e.first],e.first));
			}
		}
	}
	
	for(int i=1;i<=n;i++)
		cout<<dis[i]<<" ";
	return 0;
}
