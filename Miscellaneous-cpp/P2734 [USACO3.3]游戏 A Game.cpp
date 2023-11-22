#include<bits/stdc++.h>
using namespace std;
int a[300],sum[300];
int f[300][300];
int main(){
	int n;
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		f[i][i]=a[i];
		sum[i]=sum[i-1]+a[i];
	} 
	
	for(int l=2;l<=n;l++){
		for(int i=1;i+l<=n+1;i++){
			int j=i+l-1;
			f[i][j]=sum[j]-sum[i-1]-min(f[i+1][j],f[i][j-1]);
		}
	}
	
	cout<<f[1][n]<<" "<<min(f[1+1][n],f[1][n-1])<<endl;
	return 0;
} 
