#include<bits/stdc++.h>
#define mp make_pair
#define pi pair<int,int>
using namespace std;
int n,m,k;
int dis[3000];            //数组别开小了！！ 
vector<pi > a[3000];
set<pi > q;
int main(){
	cin>>n>>m>>k;
	
	memset(dis,0x3f,sizeof(dis));
	
	for(int i=1;i<=m;i++){
		int x,y,z;
		cin>>x>>y>>z;
		
		for(int j=0;j<=k;j++) {
			a[x+j*n].push_back(mp(y+j*n,z));			
			a[y+j*n].push_back(mp(x+j*n,z));
			
			if(j==0) continue;
			
			a[x+(j-1)*n].push_back(mp(y+j*n,z/2));
			a[y+(j-1)*n].push_back(mp(x+j*n,z/2));
		}
	}
	
	dis[1]=0;
	q.insert(mp(0,1));
	
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
	
	int minn=1e30;
	for(int i=0;i<=k;i++){
		minn=min(minn,dis[n+n*i]);
	}
	
	cout<<minn<<endl;
}
