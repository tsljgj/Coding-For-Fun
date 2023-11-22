#include<bits/stdc++.h>
using namespace std;
int r,n;
int a[502000];       //仔细计算数组大小，RE大概率是数组没开够 
int dp[502000];
void print(){
	int h=1,cnt=0;
	for(int i=1;i<=n;i++){
		cout<<dp[i]<<" ";
		cnt++;
		if(cnt==h) {
			cnt=0;
			h++;
			cout<<endl;
		}
		
	}
}
int main(){
	cin>>r;
	n=(r+1)*r/2;
	
	for(int i=1;i<=n;i++){
		cin>>a[i];
		
	}
	
	dp[1]=a[1];
	int h=1,cnt=0;
	for(int i=1;i<=n-r;i++){
		dp[i+h]=max(dp[i+h],dp[i]+a[i+h]);
		dp[i+h+1]=max(dp[i+h+1],dp[i]+a[i+h+1]);
		cnt++;
		if(cnt==h) {
			cnt=0;
			h++;
		}
//		print();
	} 
	
	int maxn=0;
	for(int i=n;i>=n-r+1;i--) maxn=max(maxn,dp[i]);
	cout<<maxn<<endl;
	return 0;
	
}
