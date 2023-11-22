#include<bits/stdc++.h>  //可以多个点一起做dijk~!!! 妙啊~ (一组点到一个点的最短路) 
#define mp make_pair
using namespace std;
int n,m,h;
//int dis[50020][50020]/*起点为i,终点为j的最短路*/; 会爆 
int d1[50020],d2[50020];    //dis记出发点,dis2记终点 
vector<pair<int,int> > a[50020];
//vector<pair<int,int> > hay;
set<pair<int,int> > q;

void dijk(int *dis){	

//	for(int i=1;i<=n;i++) dis[i]=1e30;

 	for(int i=1;i<=n;i++) q.insert(mp(dis[i],i));
 	//一次性入队在正常的dijk中是多此一举，增加运算量
	//但如果要以  多个点形成的点组来做dijk(一组点到各个点的最短路)  就需要将点组中的每一个点提前赋值并一起入队 
	
	while(!q.empty()){
		pair<int,int> u=*q.begin();
		q.erase(q.begin());
		
		for(int j=0;j<a[u.second].size();j++){
			pair<int,int> e=a[u.second][j];
			if(dis[e.first]>e.second+u.first){
				q.erase(mp(dis[e.first],e.first));
				dis[e.first]=e.second+u.first;				
				q.insert(mp(dis[e.first],e.first));
			}
		}
	}
}

int main(){
	cin>>n>>m>>h;
		
	for(int i=1;i<=m;i++){
		int x,y;
		int z;
		cin>>x>>y>>z;
		a[x].push_back(mp(y,z));
		a[y].push_back(mp(x,z));
	}
	
	memset(d1,0x3f,sizeof(d1));
	d1[n]=0;	
	dijk(d1);         //点n到每个点的最短路 
	
	memset(d2,0x3f,sizeof(d1));
	for(int i=1;i<=h;i++){
		int x;
		int y;
		cin>>x>>y;
		d2[x]=d1[x]-y;  //记录点n到x点在有了干草垛的减免下的最短距离 
//		hay.push_back(mp(x,y));
	}
	dijk(d2); //将所有干草垛看作出发点做dijk,得到的是 (点n -> 干草垛组 -> 某一点) 的距离 
				//最后只要比较  d2数组(n->i经过干草垛的最短路)  和  d1数组(原先n->i的最短路) 
	
	for(int i=1;i<n;i++) cout<<(d1[i]>=d2[i])<<endl;
	
	return 0;
	
	
	
//	int c;
//	cin>>c;
//	int x;
//	for(int i=1;i<=c;i++){
//		cin>>x;
//		cout<<disn[x]<<endl;
//	}
} 
