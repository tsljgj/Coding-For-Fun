#include<bits/stdc++.h>
using namespace std;
int n,m,s,t;
double dis[120];
set<pair<double,double> > q;
vector<pair<double,double> > a[2020];//
double x[120],y[120];
double ans=0;
double dist(int i,int j){
	return hypot(x[i]-x[j],y[i]-y[j]);
}
int main(){
	cin>>n;
	for(int i=1;i<=n;i++){
		dis[i]=1e30;
		cin>>x[i]>>y[i];
	}
	
	cin>>m;
	for(int i=1;i<=m;i++){
		int s1,s2;
		cin>>s1>>s2;
		a[s1].push_back(make_pair(s2,dist(s1,s2)));
		a[s2].push_back(make_pair(s1,dist(s1,s2)));
	}
	cin>>s>>t;
	
	dis[s]=0;
	q.insert(make_pair(dis[s],s));
	
	while(!q.empty()){
		pair<double,int> u=*q.begin();
		q.erase(q.begin());
		
		if(u.first>dis[u.second]) continue;
		
		for(int i=0;i<a[u.second].size();i++){
			pair<int,double> e=a[u.second][i];
			if(dis[e.first]>u.first+e.second){
				q.erase(make_pair(dis[e.first],e.first));
				dis[e.first]=u.first+e.second;
				q.insert(make_pair(dis[e.first],e.first));
			}
		}
		
		
	}
	cout<<fixed<<setprecision(2)<<dis[t]<<endl;
	
}
