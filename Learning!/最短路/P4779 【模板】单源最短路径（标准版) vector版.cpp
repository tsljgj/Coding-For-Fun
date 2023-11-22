#include<bits/stdc++.h>
#define MAXN 100020
using namespace std;
int INF=0x3f;
int n,m,s;
int dis[MAXN];
priority_queue< pair<int,int>, vector<pair<int,int> >, greater< pair<int,int> > >q;
vector<pair<int,int> > a[MAXN];
int main(){
	memset(dis,INF,sizeof(dis));
	cin>>n>>m>>s;
	for(int i=1;i<=m;i++){
		int x,y,z;
		cin>>x>>y>>z;
		a[x].push_back(make_pair(y,z));
	}
	
	dis[s]=0; 
	q.push(make_pair(dis[s],s)); 
	
	while(q.size() > 0){
		pair<int,int> u=q.top();
		q.pop();
		int k=u.second;
		if(u.first>dis[u.second]) continue;   //两点间多路的处优化理 ，也可用done[] 
		for(int i=0;i<a[k].size();i++){
			
			int next=a[k][i].first,distance=a[k][i].second;
			
			if(dis[next]>dis[k]+distance){
				dis[next]=dis[k]+distance;
				q.push(make_pair(dis[next],next));
			}
			
//			pair<int, int> e = a[u.second][i];
//			if (dis[e.first] > dis[u.second] + e.second) {
//				dis[e.first] = dis[u.second] + e.second;
//				q.push(make_pair(dis[e.first], e.first));
//			}
		}
		
	}
	
	for(int i=1;i<=n;i++){
		cout<<dis[i]<<" ";
	}
}
