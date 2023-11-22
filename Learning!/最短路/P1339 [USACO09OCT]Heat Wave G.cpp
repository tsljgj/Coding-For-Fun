#include<bits/stdc++.h>
#define mp make_pair
#define pi pair<int,int>
using namespace std;
int n,m,s,t;
int dis[5020];
vector<pi > a[100020];
set<pi > q;
int main(){
	cin>>n>>m>>s>>t;
	memset(dis,0x3f,sizeof(dis));

	for(int i=1;i<=m;i++){
		int x,y,z;
		cin>>x>>y>>z;
		a[x].push_back(mp(y,z));
		a[y].push_back(mp(x,z));
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
	
	cout<<dis[t]<<endl;
}
