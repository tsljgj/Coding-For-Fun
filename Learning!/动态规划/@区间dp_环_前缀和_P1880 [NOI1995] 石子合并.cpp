#include<bits/stdc++.h>  //区间dp,i~j区间相当于前x项,枚举分割点(合并点)k相当于枚举容量 
using namespace std;   //1~n最优意味着1~n中每一区间都最优，所以记区间dp[i][j] 
int n,a[120],dp[220][220],sum[220],dps[220][220];
int maxn=0;
int minn=1e9;
int main(){
	cin>>n;
	for(int i=1;i<=n;i++) {
		cin>>a[i];
		a[i+n]=a[i];
	}
	
	for(int i=1;i<=n+n;i++){
		sum[i]=sum[i-1]+a[i];
	}
	
//	for(int i=1;i<=2*n;i++) {
//		cout<<a[i]<<" ";
//	}
//	cout<<endl;
//	
//	for(int i=1;i<=2*n;i++) {
//		cout<<sum[i]<<" ";
//	}
 	
 	
	for(int l=1;l<n+n/*有+n*/;l++){         //l(length)用来决定j,此处记i~j区间的最优值 
		for(int i=1;i+l/*j<2n,不是i*/<=n*2;i++){
			int j=i+l;
			dps[i][j]=1e9;
			for(int k=i;k</*k+1<=j,所以k<j*/j;k++){
				dp[i][j]=max(dp[i][k]+dp[k+1][j]+sum[j]-sum[i-1/*-1别忘*/],dp[i][j]);
				dps[i][j]=min(dps[i][k]+dps[k+1][j]+sum[j]-sum[i-1/*-1别忘*/],dps[i][j]);
			}
		}
	}
	
	for(int i=1;i<=n/*没有+n*/;i++){
		maxn=max(dp[i][i+n-1],maxn);
		minn=min(dps[i][i+n-1],minn);
	}
	
	cout<<minn<<endl;
	cout<<maxn<<endl;
}
