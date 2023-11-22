#include<bits/stdc++.h>
using namespace std;
const int MAXN=100020;
int n;
int a[MAXN];
int s[MAXN], ss[MAXN], ssm[MAXN];
int ans=0;
int main(){
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	
	for(int i=1;i<=n;i++){
		s[i]=s[i-1]+a[i];
	}
	
	for(int i=n;i>=1;i--){
		ss[i]=s[i+1]+a[i];
		ssm[i]=min(ssm[i+1],ss[i]);
	}
	
	for(int i=0;i<=n;i++){
		ans=max(ans,s[n]-s[i]-ssm[i+1]);
	}
	
	cout<<ans<<endl;
}
