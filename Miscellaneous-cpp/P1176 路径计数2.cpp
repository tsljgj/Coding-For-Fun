#include<bits/stdc++.h>
using namespace std;
int a[1020][1020];
long long f[1020][1020];
int main(){
	int n,m;
	cin>>n>>m;
	while(m--){
		int x,y;
		cin>>x>>y;
		a[x][y]=1;
	}
	f[0][1]=1;
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++){
//			cout<<(a[i-1][j]^1)<<" "<<(a[i][j-1]^1)<<endl;
//			f[i][j]=(a[i-1][j]^1*f[i-1][j])+(a[i][j-1]^1*f[i][j-1]);
//			cout<<f[i][j]<<endl;
			if(!a[i][j]){
				if(!a[i-1][j]) f[i][j]+=f[i-1][j];
				if(!a[i][j-1]) f[i][j]+=f[i][j-1];	
			}
			
		}
	cout<<f[n][n]%100003<<endl;
} 
