#include<bits/stdc++.h>  //����dp,i~j�����൱��ǰx��,ö�ٷָ��(�ϲ���)k�൱��ö������ 
using namespace std;   //1~n������ζ��1~n��ÿһ���䶼���ţ����Լ�����dp[i][j] 
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
 	
 	
	for(int l=1;l<n+n/*��+n*/;l++){         //l(length)��������j,�˴���i~j���������ֵ 
		for(int i=1;i+l/*j<2n,����i*/<=n*2;i++){
			int j=i+l;
			dps[i][j]=1e9;
			for(int k=i;k</*k+1<=j,����k<j*/j;k++){
				dp[i][j]=max(dp[i][k]+dp[k+1][j]+sum[j]-sum[i-1/*-1����*/],dp[i][j]);
				dps[i][j]=min(dps[i][k]+dps[k+1][j]+sum[j]-sum[i-1/*-1����*/],dps[i][j]);
			}
		}
	}
	
	for(int i=1;i<=n/*û��+n*/;i++){
		maxn=max(dp[i][i+n-1],maxn);
		minn=min(dps[i][i+n-1],minn);
	}
	
	cout<<minn<<endl;
	cout<<maxn<<endl;
}
