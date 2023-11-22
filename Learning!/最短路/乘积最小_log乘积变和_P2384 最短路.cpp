#include<bits/stdc++.h>
#define MAXN 100010
using namespace std;
//const int INF=0x3f;
//priority_queue<pair<int,int>, vector<pair<int,int> >,greater<pair<int,int> > > q;
set<pair<double,int> > q;
vector<pair<int,int> > a[MAXN];
int n,m,s=1;
int ans[MAXN];  //用log找最短路，用ans存乘积，因为用log不能边做边%(会爆) 
double dis[MAXN];
int main(){
	
//	memset(dis,INF,sizeof(dis));        //int 不和 其他double一起运算 
	
	cin>>n>>m;
	for(int i=1;i<=n;i++) {
		dis[i]=1e30;
		ans[i]=1;
	}
	for(int i=1;i<=m;i++){
		int x,y;
		long double z;
		cin>>x>>y>>z;
//		cout<<log10(z)<<endl;
		a[x].push_back(make_pair(y,z));
	}
	
	dis[1]=0;                             //初始化两步不要漏 
	q.insert(make_pair(dis[1],1));
	
	while(!q.empty()){
		pair<long double,int> u=*q.begin();          //u必须是pair<>,e而q.begin()是指针 
		q.erase(q.begin());
        //		if(u.first>dis[u.second]) continue;
		
		for(int i=0;i<a[u.second].size();i++){
			if(dis[a[u.second][i].first]>log(a[u.second][i].second)+dis[u.second]){
				
				q.erase(make_pair(dis[a[u.second][i].first],a[u.second][i].first));
				
				dis[a[u.second][i].first]=log(a[u.second][i].second)+dis[u.second];
				
				ans[a[u.second][i].first]=ans[u.second]*a[u.second][i].second%9987;
				
				q.insert(make_pair(dis[a[u.second][i].first],a[u.second][i].first));
				
			}
		}
	}
//	cout<<dis[n];
	cout<<ans[n]<<endl;
	return 0;
} 
