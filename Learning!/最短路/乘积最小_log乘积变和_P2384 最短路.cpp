#include<bits/stdc++.h>
#define MAXN 100010
using namespace std;
//const int INF=0x3f;
//priority_queue<pair<int,int>, vector<pair<int,int> >,greater<pair<int,int> > > q;
set<pair<double,int> > q;
vector<pair<int,int> > a[MAXN];
int n,m,s=1;
int ans[MAXN];  //��log�����·����ans��˻�����Ϊ��log���ܱ�����%(�ᱬ) 
double dis[MAXN];
int main(){
	
//	memset(dis,INF,sizeof(dis));        //int ���� ����doubleһ������ 
	
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
	
	dis[1]=0;                             //��ʼ��������Ҫ© 
	q.insert(make_pair(dis[1],1));
	
	while(!q.empty()){
		pair<long double,int> u=*q.begin();          //u������pair<>,e��q.begin()��ָ�� 
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
