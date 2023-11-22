#include<bits/stdc++.h>
using namespace std;
int main(){
	int n;
	int a[200020];
	cin>>n;
	int ans=0,maxn=-(1<<30);
	for(int i=1;i<=n;i++) {
		cin>>a[i];
		ans+=a[i];
		maxn=max(maxn,ans);
		ans=max(ans,0); 
	}
	
	cout<<maxn<<endl;
	
	
	
}
