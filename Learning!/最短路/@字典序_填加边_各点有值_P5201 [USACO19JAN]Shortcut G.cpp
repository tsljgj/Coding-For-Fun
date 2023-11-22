#include<bits/stdc++.h>
#define pointtot 10020
#define mp make_pair
using namespace std;
int n,m,t;
int cownum[pointtot],cowpass[pointtot],cows;
int dis[pointtot];
int yl[pointtot];
vector<pair<int,int> > a[1000040];
set<pair<int,int> > q;
long long maxn=0,k;
void calcow(int o){
	if(o==1){
		return;
	}
	cowpass[yl[o]]+=cows;
	calcow(yl[o]);
}
void track(int px,int py){
	
	if(px==1&&py==1) return;
	
	if(px<py) {
		k=1;
		return;
	}
	
	if(px>py) {
		k=0;
		return;
	}
	
	track(yl[px],yl[py]);
	return;
}
void compare(int px,int py){
	
	if(yl[py]==n+1){
		k=1;
		return;
	}

	track(px,py);	
}
int i,x,y,z;
int main(){
	cin>>n>>m>>t;
	for(i=1;i<=n;i++){
		dis[i]=1e30;
		cin>>cownum[i];   //每片草地的奶牛数量 
		cowpass[i]=cownum[i];
		yl[i]=n+1;
	}
	yl[1]=1;

	
	for(i=1;i<=m;i++){
		cin>>x>>y>>z;
		a[x].push_back(mp(y,z)); 
		a[y].push_back(mp(x,z)); 

	}
	
	dis[1]=0;
	q.insert(mp(dis[1],1));
	
	while(!q.empty()){
		pair<int,int> u=*q.begin();
		q.erase(q.begin());
//		cout<<u.second<<endl;
		
		if(u.first>dis[u.second]) continue;
		
		for(i=0;i<a[u.second].size();i++){
			pair<int,int> e=a[u.second][i];      //e是从点u.second出发连通的第i条边的两个数据：通向的点和花费的距离 
			
			if(dis[e.first]==e.second+u.first){
				compare(u.second,yl[e.first]);
				
				if(k){
					yl[e.first]=u.second;
					
				}
				
			}
			
			if(dis[e.first]>e.second+u.first){
				q.erase(mp(dis[e.first],e.first));
				dis[e.first]=e.second+u.first;
				q.insert(mp(dis[e.first],e.first));
				
				yl[e.first]=u.second;
//				cowpass[e.first]=cownum[e.first]+cowpass[u.second];
//				cout<<e.second<<endl;
			}
			

		}
	}
	for(i=1;i<=n;i++){
		cows=cownum[i];
		calcow(i);
	}
	
	for(i=1;i<=n;i++){
		if(dis[i]>t){
			maxn=max(maxn,(dis[i]-t)*cowpass[i]);
		}
//		cout<<cowpass[i]<<endl;
	}
//	for(i=1;i<=n;i++){
//		cout<<i<<"前往:"; 
//		cout<<yl[i];
//		cout<<endl;
//	}
//	for(int i=2;i<=n;i++){
//		if(t<dis[i]){
//			maxn=max(maxn,(dis[i]-t)*cowpass[i]);
//		}
//	}
//	
	cout<<maxn<<endl;
	return 0;
}
