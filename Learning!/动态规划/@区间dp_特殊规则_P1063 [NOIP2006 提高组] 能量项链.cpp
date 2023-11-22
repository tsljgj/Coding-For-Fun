#include<bits/stdc++.h>
using namespace std;
int n,a[120],dp[220][220];
int main(){
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		a[i+n]=a[i];
	}
	
	
//	for(int i=1;i<=2*n;i++) cout<<a[i]<<" ";
//	cout<<endl;
	
	
	
	for(int l=1;l<n+n;l++){
		for(int i=1;i+l<=n+n;i++){
			int j=i+l;
			for(int k=i;k<j;k++){
				dp[i][j]=max(dp[i][k]+dp[k+1][j]+a[i]*a[k+1]*a[j+1],dp[i][j]);
			}
		}
	}
	
	int maxn=0;
	for(int i=1;i<=n;i++){
		maxn=max(maxn,dp[i][i+n-1]);
	}
	
	cout<<maxn<<endl;
	return 0;
} 
