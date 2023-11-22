#include<bits/stdc++.h>
using namespace std;
const int MAXN=1020;
int n,m;
int a[MAXN][MAXN];
int b[MAXN][MAXN], c[MAXN][MAXN];
int f[MAXN*MAXN];
int cnt=0;

void dfs(int x,int y){
	c[x][y]=cnt;
	b[x][y]=1;
	f[cnt]++;
	if(x+1<=n&&a[x][y]*a[x+1][y]==0&&b[x+1][y]==0) dfs(x+1,y);
	if(x-1>0&&a[x][y]*a[x-1][y]==0&&b[x-1][y]==0) dfs(x-1,y);
	if(y+1<=n&&a[x][y]*a[x][y+1]==0&&b[x][y+1]==0) dfs(x,y+1);
	if(y-1>0&&a[x][y]*a[x][y-1]==0&&b[x][y-1]==0) dfs(x,y-1);
	return;
}
int main(){
	cin>>n>>m;
//	memset(a,0,sizeof(a));
	for(int i=1;i<=n;i++) {
		string s;
		cin>>s;
		for(int j=0;j<n;j++){
			a[i][j+1]=s[j]-'0';
		}
	}
	
//	for(int i=0;i<n;i++){
//		for(int j=0;j<n;j++) cout<<a[i][j]<<" ";
//		cout<<endl;
//	}
		
		
	for(int i=1;i<=n;i++) {
		for(int j=1;j<=n;j++){
			if(b[i][j]==0){
				cnt++;
				dfs(i,j);
			}
		}
	}
	
	for(int i=1;i<=m;i++){
		int x,y;
		cin>>x>>y;
		cout<<f[c[x][y]]<<endl;
	}
}
