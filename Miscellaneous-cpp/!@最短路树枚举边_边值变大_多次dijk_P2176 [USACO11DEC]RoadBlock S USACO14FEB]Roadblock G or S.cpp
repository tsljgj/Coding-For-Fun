#include<bits/stdc++.h>
#define mp make_pair
#define pi pair<long long,long long>
using namespace std;
int n,m;
long long maxn=0;
long long yuan;
bool b[120][120];
long long dis[120];
set<pi > q;
vector<pair<pair<int,int>,int> > a[5020];
int dijk(){
	for(int i=1;i<=n;i++) dis[i]=1e30;
					
	dis[1]=0;
	q.insert(mp(dis[1],1));
	
	while(!q.empty()){
		pi u=*q.begin();
		q.erase(q.begin());
		
		for(int i=0;i<a[u.second].size();i++){
			pi e=a[u.second][i].first;
			
			if(dis[e.first]>e.second+u.first){
				q.erase(mp(dis[e.first],e.first));
				dis[e.first]=e.second+u.first;
				q.insert(mp(dis[e.first],e.first));
			}
			
		}
		
		
	}
	
	return dis[n];
}
int main(){
	freopen("P2176_10.in","r",stdin);
	cin>>n>>m;
	
	memset(b,0,sizeof(b));
	
	for(int i=1;i<=m;i++){
		int x,y,z;
		cin>>x>>y>>z;
		a[x].push_back(mp(mp(y,z),a[y].size()+1));
		a[y].push_back(mp(mp(x,z),a[x].size()));
	}
	
	yuan=dijk();
	for(int i=1;i<=n;i++){
		
		for(int j=0;j<a[i].size();j++){               //be careful with "break" !!! 
			if(b[i][j]!=1) {
				
				a[i][j].first.second*=2;
				a[a[i][j].first.first][a[i][j].second-1].first.second*=2;
				b[i][j]=1;
				b[a[i][j].first.first][a[i][j].second-1]=1;
				
				
				maxn=max(maxn,dijk()-yuan);
				
				a[i][j].first.second/=2;
				a[a[i][j].first.first][a[i][j].second-1].first.second/=2;
			}
		}
		
		
	}

	cout<<maxn<<endl;
	return 0;
	
	
//	for(int i=1;i<=n;i++){
//		cout<<dis[i]<<endl;
//	}
	
} 
