#include<bits/stdc++.h>
#define mp make_pair
#define pi pair<int,int>
using namespace std;
int n,m,s,t,k;
int dis[200020];
vector<pi > a[200020];
set<pi > q;
int main(){
	cin>>n>>m>>k>>s>>t;
	
	memset(dis,0x3f,sizeof(dis));
	
	for(int i=0;i<m;i++) {
		int x,y,z;
		cin>>x>>y>>z;
		for(int j=0;j<=k;j++){
			a[x+j*n].push_back(mp(y+j*n,z));
			a[y+j*n].push_back(mp(x+j*n,z));
			
			if(j==0) continue;
			
//			a[x+j*n].push_back(mp(y+(j-1)*n,0));        //不能从下往上走 
			a[y+(j-1)*n].push_back(mp(x+j*n,0));
			
//			a[y+j*n].push_back(mp(x+(j-1)*n,0));
			a[x+(j-1)*n].push_back(mp(y+j*n,0));
		}
	}
	
	dis[s]=0;
	q.insert(mp(0,s));
	
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
	for(int i=0;i<=k;i++) minn=min(minn,dis[t+n*i]);       //预防奇葩数据(k个免费机会没用完) 
		cout<<minn<<endl;
	return 0;
	
}
