//5 9 2 3
//2 3 8
//2 4 7
//4 3 1
//0 4 2
//0 1 2
//1 2 1
//2 1 1
//1 3 7
//3 0 3
#include<bits/stdc++.h>
#define MAXN 50010
#define pi pair<int,int>
#define mp make_pair
using namespace std;
const int INF=0x3f;
int n,m,k,s,t;
int dis[MAXN];
vector<pi > a[MAXN];
set<pi > q;
void dijk(){
	
	dis[s]=0;
	
	for(int i=0;i<n;i++){
		q.insert(mp(dis[i],i));
	}
	
//	dis[s]=0;
//	q.insert(mp(dis[s],s));
	
	while(!q.empty()){
		pi u=*q.begin();
		q.erase(q.begin());
		if(u.first>dis[u.second]) continue;
		
		for(int i=0;i<a[u.second].size();i++){
			pi e=a[u.second][i];
			if(dis[e.first]>dis[u.second]+e.second) {
				
				q.erase(mp(dis[e.first],e.first));
				dis[e.first]=dis[u.second]+e.second;
				q.insert(mp(dis[e.first],e.first));
				 
			}
		}
	}
	
}
int main(){
	cin>>n>>m>>k>>s>>t;
	memset(dis,INF,sizeof(dis));
	
	for(int i=1;i<=m;i++){
		int x,y,z;
		cin>>x>>y>>z;
		a[x].push_back(mp(y,z));
		a[y].push_back(mp(x,z));
	}
	
	dijk();
	
	for(int i=1;i<=k;i++){
		
		for(int j=0;j<n;j++){
			for(int p=0;p<a[j].size;p++){
				dis[a[j][p].first]=min(dis[j])
			}
		}
		
		dijk();
	}
	
	for(int i=0;i<n;i++){
		cout<<dis[i]<<" ";
	}
} 
