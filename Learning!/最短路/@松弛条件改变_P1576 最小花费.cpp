#include<bits/stdc++.h>
#define pi pair<double,int>
#define mp make_pair
using namespace std;
set<pi > q;
vector<pair<int,double> > a[200020];
int n,m;
int A,B;
double dis[2020];
int main(){
	cin>>n>>m;
//	memset(dis,0x3f,sizeof(dis));     //别用memset了 
 	for(int i=1;i<=n;i++) dis[i]=1e9;
	for(int i=1;i<=m;i++) {   //m别写成n!!!! 
		int x,y;
		double z;
		cin>>x>>y>>z;
		a[x].push_back(mp(y,z));
		a[y].push_back(mp(x,z));
	}
	
	cin>>A>>B;
	
	dis[B]=100;
	q.insert(mp(dis[B],B));
	
	while(!q.empty()){
		pi u=*q.begin();
		q.erase(q.begin());
//		cout<<"从"<<u.second<<"点走到: "<<endl;
		for(int i=0;i<a[u.second].size();i++){
			pair<int,double> e=a[u.second][i];
//			cout<<e.first<<"点: "; 
//			cout<<"到达点的钱："<<dis[e.first]<<" 出发点的钱"<<u.first<<" 利息"<<e.second<<" 1-利息除100="<<(1-e.second/100)<<" 改后"<<u.first/(1-e.second/100);
//			cout<<e.first<<" "<<u.first<<" "<<e.second<<" "<<e.second/100<<" "<<1+e.second/100<<" "<<u.first*(1+e.second/100)<<" ";
			if(dis[e.first]>u.first/(1-e.second/100)){
				q.erase(mp(dis[e.first],e.first));
				dis[e.first]=u.first/(1-e.second/100);
//				cout<<dis[e.first]<<endl;
				q.insert(mp(dis[e.first],e.first));

			}
//			cout<<" 最终决定："<<dis[e.first]<<endl;
		}
	}
	
	cout<<fixed<<setprecision(8)<<dis[A]<<endl;
	return 0;
}
