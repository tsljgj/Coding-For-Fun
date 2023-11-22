#include<bits/stdc++.h>
//6 9
//1 2 3
//2 5 2
//2 4 2
//4 5 1
//5 6 6
//3 6 4
//1 3 4
//1 5 5
//2 6 7
#define mp make_pair
#define pi pair<int,int>
using namespace std;
int n,m;
int dis[5020],dis2[5020];
vector<pi > a[100020];
set<pi > q;
int main(){
	cin>>n>>m;
	memset(dis,0x3f,sizeof(dis));
	memset(dis2,0x3f,sizeof(dis2));

	for(int i=1;i<=m;i++){
		int x,y,z;
		cin>>x>>y>>z;
		a[x].push_back(mp(y,z));
		a[y].push_back(mp(x,z));
	}
	
	dis[1]=0;
	q.insert(mp(dis[1],1));

	for(int j=0;j<a[1].size();j++){
		dis2[1]=min(dis2[1],2*a[1][j].second);
	}
	
//	cout<<dis[1]<<" "<<dis2[1]<<endl; 
	
	while(!q.empty()){
		pi u=*q.begin();
//		cout<<endl;
//		cout<<"pop"<<u.second<<endl;
//		cout<<endl;
		q.erase(q.begin());
		
		for(int i=0;i<a[u.second].size();i++){
			
			pi e=a[u.second][i];
//			cout<<endl;
//			cout<<dis[e.first]<<" "<<e.second+u.first<<endl;
			if(dis[e.first]>e.second+u.first){
				
				dis2[e.first]=dis[e.first];
				
				q.erase(mp(dis[e.first],e.first));
				dis[e.first]=e.second+u.first;
				q.insert(mp(dis[e.first],e.first));
				
			}
			
			if(dis[e.first]<e.second+u.first)
				dis2[e.first]=min(dis2[e.first],e.second+u.first);
			
			dis2[e.first]=min(dis2[e.first],dis2[u.second]+e.second);
			
			for(int j=0;j<a[e.first].size();j++){
				dis2[e.first]=min(dis2[e.first],dis[e.first]+2*a[e.first][j].second);
			}
			
//			cout<<e.first<<": "<<dis[e.first]<<" "<<dis2[e.first]<<endl; 

			
		}
	}
	
	cout<<dis2[n]<<endl;
}
