#include<bits/stdc++.h>
#define sec second         //#define A B       A=B 
#define fir first
#define mp make_pair 
using namespace std;
int n,m,s,p;
vector<pair<int,int> > a[20010];
int dis[10010];
bool done[10010];
int maxn=0;
int main(){
	cin>>n>>m>>s>>p;
	memset(done,0,sizeof(done));
	done[s]=1;
	
	for(int i=1;i<=n;i++){
		dis[i]=1e30;
	}
	
	for(int i=1;i<=m;i++){
		int x,y,z;
		cin>>x>>y>>z;
		a[x].push_back(mp(z,y));
		a[y].push_back(mp(z,x));
		
	}
	
	int t=s;
	
	while(t!=p){
		
		for(int i=0;i<a[t].size();i++){          //更新大组到各个散点的最短距离 
			dis[a[t][i].sec]=min(a[t][i].fir,dis[a[t][i].sec]);
		}
		
		int minn=1e30; 			
						
		for(int i=1;i<=n;i++){              //选择到大组最短的点 
			if(dis[i]<minn&&done[i]==0) {
				minn=dis[i];
				t=i;                 //t是选择的点 
			}
		}
		
		done[t]=1;
		maxn=max(maxn,dis[t]);
		
	}
	
	cout<<maxn<<endl;
	
	
}
