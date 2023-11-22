//#include<bits/stdc++.h>
#include <iostream>
#include <string.h>
#include <stdio.h>
#include <vector>
#include <map>
#include <queue>
#include <algorithm>
#include <math.h>
#include <cstdio>
#define fi first
#define se second
#define mp make_pair
using namespace std;
const int N=1020, M=100020;
int n,m,Q;
int from[M], nxt[M], to[M], head[N], val[M];
int cnt=0; 
bool vis[N];
int cost[N], vex[N];
int dp[N][N];

void add(int x,int y,int c){
	from[++cnt]=x,	to[cnt]=y, nxt[cnt]=head[x], val[cnt]=c, head[x]=cnt;
	from[++cnt]=y,  to[cnt]=x, nxt[cnt]=head[y], val[cnt]=c, head[y]=cnt;
}

priority_queue<pair<int,int>, vector<pair<int,int> >, greater<pair<int,int> > > q;

void prim(){
	for(int i=head[1];i;i=nxt[i]){
		q.push(mp(val[i],i));
	}

	vis[1]=1;
	
	while(q.size()){
		int v=to[q.top().se], u=from[q.top().se], c=val[q.top().se];
//		cout<<q.top().se<<" "<<v<<" "<<u<<" "<<c<<" "<<vis[v]<<endl;

		q.pop();
		if(vis[v]) continue;
		
		vis[v]=1;
		vex[v]=u;
		cost[v]=c;
		
		for(int i=head[v];i;i=nxt[i]){
			if(vis[to[i]]) continue;
			q.push(mp(val[i],i));
		}
	}
}

void dp1(){
	for(int i=2;i<=n;i++){
		for(int j=i;j;j=vex[j]){
			dp[i][vex[j]]=max(dp[i][j],cost[j]);
			
//			cout<<i<<"-"<<vex[j]<<" "<<dp[i][vex[j]]<<endl;
			dp[vex[j]][i]=dp[i][vex[j]];
		}
	}
	
//	for(int i=1;i<=n;i++)
//		for(int j=1;j<=n;j++) 
//			cout<<i<<"-"<<j<<" "<<dp[i][j]<<endl;
}

int main(){
	cin>>n>>m>>Q;
	for(int i=1;i<=m;i++) {
		int x,y,c;
		cin>>x>>y>>c;
		add(x,y,c);
	}
	
	prim();
//	for(int i=1;i<=n;i++) cout<<i<<" "<<"vex: "<<vex[i]<<" cost:"<<cost[i]<<endl;
	
	dp1();
	
	for(int i=1;i<=Q;i++){
		int x,c;
		cin>>x>>c;
		x=2*x;
//		cout<<from[x]<<" "<<to[x]<<endl;
		if(dp[from[x]][to[x]]>=c) cout<<"YES"<<endl;
		else cout<<"NO"<<endl;
	}
} 
