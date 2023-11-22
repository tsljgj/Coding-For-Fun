#include<bits/stdc++.h>
using namespace std;
int n,s;
long long c[10020],y[10020],minn[10020];
long long sum=0;
int main(){
	cin>>n>>s;
	for(int i=1;i<=n;i++){
		cin>>c[i]>>y[i];
		minn[i]=1e30;
	}	
	
	for(int i=1;i<=n;i++){
		for(int j=i;j<=n;j++){
			minn[j]=min(minn[j],c[i]+(j-i)*s);
		}
	}
	for(int i=1;i<=n;i++) sum+=minn[i]*y[i];
	cout<<sum<<endl;
}
