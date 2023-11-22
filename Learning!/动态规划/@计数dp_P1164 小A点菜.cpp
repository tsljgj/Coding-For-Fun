#include<bits/stdc++.h>
using namespace std;
int p[10020];
int dp[10020];
int main(){
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>p[i];
	}
	
	memset(dp,0,sizeof(0));
	
	for(int i=1;i<=n;i++)
		for(int j=m;j>=1;j--){
			if(j>=p[i]){
				if(dp[j-p[i]]>0) dp[j]+=dp[j-p[i]];
				if(j==p[i]) dp[j]++;
			}
		}
	
	cout<<dp[m]<<endl;
}
