#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[10020];
int f[120][120];
int main(){
	cin>>n>>m;
	
	for(int i=1;i<=m;i++){
		cin>>a[i];
	}
	
//	for(int i=1;i<=n;i++){
//			for(int j=1;j<=n;j++){
//				f[i][j]=1e30;
//			}
//		}
		
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			cin>>f[i][j];
		}
	}
	
	for(int k=1;k<=n;k++)
		for(int i=1;i<=n;i++)
			for(int j=1;j<=n;j++){
				f[i][j]=min(f[i][k]+f[k][j],f[i][j]); 
			}
	int sum=0;
	for(int i=2;i<=m;i++){
		sum+=f[a[i-1]][a[i]];
	} 
	
	cout<<sum<<endl;
	
}
