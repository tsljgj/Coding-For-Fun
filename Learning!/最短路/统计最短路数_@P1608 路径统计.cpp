//1.Ҫ��ֹ����֮�䷴���ߣ���Ϊ����֮������ж����ߣ����Ҫ�Ǳ�����ͬһ��·��һ��· W[] 
//2.���е����̵���·����Ҫά������Ϊ���ܳ���һ�����յ�ĵ��ж����̵��﷽ʽ  f[] 
// 
#include<bits/stdc++.h>
#define MAXN 100010
using namespace std;
const int INF=(1<<30)-1;
//priority_queue<pair<int,int>, vector<pair<int,int> >,greater<pair<int,int> > > q;
set<pair<int,int> > q;
vector<pair<int,int> > a[MAXN];
int w[2020][2020];
int n,m,dis[MAXN],f[MAXN],sum=0;
int main(){
	cin>>n>>m;
//	memset(dis,0x3f,sizeof(dis));

	for(int i=1;i<=n;i++) dis[i]=INF;
	
	for(int i=1;i<=m;i++){
		int x,y,z;
		cin>>x>>y>>z;
		if (w[x][y] == 0 || w[x][y] > z ) {//��ֹ����֮�䷴����
			a[x].push_back(make_pair(y, z));           
			w[x][y] = z;
		}

	}
	
	dis[1]=0;      
	f[1] = 1;                      //��ʼ��������Ҫ© 
	q.insert(make_pair(dis[1],1));
	
	while(!q.empty()){
		pair<int,int> u=*q.begin();          //u������pair<>,e��q.begin()��ָ�� 
		q.erase(q.begin());
		if(u.first>dis[u.second]) continue;
		
		for(int i=0;i<a[u.second].size();i++){
			
			if(dis[a[u.second][i].first]==a[u.second][i].second+dis[u.second]){
				
				f[a[u.second][i].first]+=f[u.second];   //���->ǰ����ܵ��﷽ʽ����� 
				
			}
			
			else if(dis[a[u.second][i].first]>a[u.second][i].second+dis[u.second]){
				
				q.erase(make_pair(dis[a[u.second][i].first],a[u.second][i].first));
				
				dis[a[u.second][i].first]=a[u.second][i].second+dis[u.second];
				
				q.insert(make_pair(dis[a[u.second][i].first],a[u.second][i].first));
				
				f[a[u.second][i].first]=f[u.second];  //����->���̳�ǰ�㵽�﷽ʽ��
				
			}
			
		}
	}
	if(dis[n]==INF) cout<<"No answer"<<endl;
	else cout<<dis[n]<<" "<<f[n]<<endl;

} 
