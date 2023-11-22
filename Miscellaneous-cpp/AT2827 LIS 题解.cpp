#include<bits/stdc++.h>
using namespace std;
int a[100020];
long long dp[100020];
long long ans=0;
int main(){
	int n;
	cin>>n;
	for(int i=1;i<=n;i++) cin>>a[i];
	
	for(int i=1;i<=n;i++){
		for(int j=1;j<i;j++){
			if(a[i]>a[j]) dp[i]=max(dp[i],dp[j]);
		}
		dp[i]++;
		ans=max(ans,dp[i]);
	}
	
	cout<<ans<<endl;
	return 0;
}
