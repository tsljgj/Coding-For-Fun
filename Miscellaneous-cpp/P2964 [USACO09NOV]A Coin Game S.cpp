//#include<bits/stdc++.h>
//using namespace std;
//int n;
//int f[2020][2020];
//int a[2020],sum[2020];
//int main(){
//	cin>>n;
//	for(int i=1;i<=n;i++){
//		cin>>a[i];
//		sum[i]=sum[i-1]+a[i];
//	}
//	for(int i=1;i<=n;i++){
//		for(int j=1;j<=n;j++){
//			f[i][j]=f[i][j-1];
//			int k=2*j-1;
//			if(k+i<=n) f[i][j]=max(f[i][j],sum[n]-sum[i-1]-f[i+k][k]);
//			k++;
//			if(k+i<=n) f[i][j]=max(f[i][j],sum[n]-sum[i-1]-f[i+k][k]);
//		}
//	}
//	cout<<f[1][n]<<endl;
//	return 0;
//}

#include<bits/stdc++.h>
using namespace std;
int n;
int f[2020][2020];
int a[2020],sum[2020];
int main(){
	cin>>n;
	for(int i=n;i>=1;i--) cin>>a[i];
	for(int i=1;i<=n;i++) sum[i]=sum[i-1]+a[i];
	
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			f[i][j]=f[i][j-1];
			int k=2*j;
			if(k<=i) f[i][j]=max(f[i][j],sum[i]-f[i-k][k]);
			k--;
			if(k<=i) f[i][j]=max(f[i][j],sum[i]-f[i-k][k]);
		}
	}
	cout<<f[n][1]<<endl;
	return 0;
}
