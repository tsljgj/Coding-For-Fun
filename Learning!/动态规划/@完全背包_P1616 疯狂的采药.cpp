#include<bits/stdc++.h>
using namespace std;
long long dp[10000020],w[10020],v[10020];
int t,m;
int main(){
	cin>>t>>m;
	memset(dp,0,sizeof(dp));
	for(int i=1;i<=m;i++) cin>>w[i]>>v[i];
	
	for(int i=1;i<=m;i++){
		for(int j=1;j<=t;j++){
			if(j>=w[i])
				dp[j]=max(dp[j],dp[j-w[i]]+v[i]);
		}
	}
	
	cout<<dp[t]<<endl;
	return 0;
}
