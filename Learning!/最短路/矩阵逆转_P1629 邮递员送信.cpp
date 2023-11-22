//¾ØÕó·­×ªËãÁ½±é 
#include<bits/stdc++.h>
#define MAXN 100010
using namespace std;
const int INF=0x3f;
int done[MAXN],dis[MAXN];
priority_queue< pair<int,int>, vector<pair<int,int> >, greater<pair<int,int> > > q;
vector<pair<int,int> > a[MAXN],b[MAXN];
//struct edge{
//	int now,next,dis;
//};
int n,m,sum=0;
void dijka(){
	
	memset(done,0,sizeof(done));
	memset(dis,INF,sizeof(dis));
	
	dis[1]=0;
	
	q.push(make_pair(dis[1],1));
	
	while(!q.empty()){
		pair<int,int> u=q.top();
		q.pop();
		int k=u.second;
		if(done[k]) continue;   //k is correct 
		done[k]=1;
		
		for(int j=0;j<a[k].size();j++){
			if(dis[a[k][j].first]>dis[k]+a[k][j].second){
				dis[a[k][j].first]=dis[k]+a[k][j].second;
				q.push(make_pair(dis[a[k][j].first],a[k][j].first));
			}
			
		}
	}
}

void dijkb(){
	
	memset(done,0,sizeof(done));
	memset(dis,INF,sizeof(dis));
	
	dis[1]=0;
	
	q.push(make_pair(dis[1],1));
	
	while(!q.empty()){
		pair<int,int> u=q.top();
		q.pop();
		int k=u.second;
		if(done[k]) continue;   //k is correct 
		done[k]=1;
		
		for(int j=0;j<b[k].size();j++){
			if(dis[b[k][j].first]>dis[k]+b[k][j].second){
				dis[b[k][j].first]=dis[k]+b[k][j].second;
				q.push(make_pair(dis[b[k][j].first],b[k][j].first));
			}
			
		}
	}
}
int main(){
	cin>>n>>m;
	
	for(int i=1;i<=m;i++){
		int x,y,z;
		cin>>x>>y>>z;
		a[x].push_back(make_pair(y,z));
		b[y].push_back(make_pair(x,z));
	}
	
	dijka();
	
	for(int i=1;i<=n;i++){
		sum+=dis[i];
	}
	
//	for(int i=1;i<=n;i++){
//		vector<pair<int,int> >::iterator it;
//		for(it=a[i].begin();it!=a[i].end();){
//			a[it->first].push_back(make_pair(i,it->second));
//			a[i].erase(it);
//		}
//	}
	
	dijkb();
	
	for(int i=1;i<=n;i++){
		sum+=dis[i];
	}
	
	cout<<sum<<endl;
	return 0;
}
