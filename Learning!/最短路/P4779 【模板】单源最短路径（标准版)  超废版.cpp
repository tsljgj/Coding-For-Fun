#include<bits/stdc++.h>
#define MAX 5010              //#...   结尾不用加 ";"    # 的东西放在using..之前** 
using namespace std;
const int INF=1<<30-1;
int n,m,s;
int dis[MAX],edge[MAX][MAX]; //起点到点距离，点任意到点距离 
bool done[MAX];           //是否变白 
priority_queue<pair<int,int>,vector<pair<int,int> >,greater<pair<int,int> > > a;        //pair也是一种类型 
int main(){
	cin>>n>>m>>s;
	
	memset(done,0,sizeof(done));          //初始化 done 
	
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++)
			i==j ? edge[i][j]=0 : edge[i][j]=INF;              //初始化 edge 
	
	for(int i=1;i<=n;i++)
		dis[i]=edge[s][i];                    //初始化 dis 
		
	for(int i=1;i<=m;i++){
		int x,y,z;
		cin>>x>>y>>z;
		edge[x][y]=z;
		edge[y][x]=z;
	}
	
	a.push(make_pair(dis[s],s));
	
	while(!a.empty()){
		pair<int,int> u=a.top();
		a.pop();
		int k=u.second;
		if(done[k]) continue;
		done[k]=true;
		
		for(int i=1;i<=n;i++){
			if(!done[i]&&edge[k][i]<INF/*防爆*/&&edge[k][i]+dis[k]<dis[i]){
				dis[i]=edge[k][i]+dis[k];
				a.push(make_pair(dis[i],i));
			}
		}
		
	}
	
	for(int i=1;i<=n;i++){
		cout<<dis[i]<<" ";
	}
	
//	for(int i=1;i<=n;i++){
//		cout<<"dis[i]="<<dis[i]<<endl;
//		for(int j=1;j<=n;j++){
//			cout<<"i到j:"<<edge[i][j]<<" ";
//		}
//		cout<<endl;
//	}	
	
	return 0;
}
