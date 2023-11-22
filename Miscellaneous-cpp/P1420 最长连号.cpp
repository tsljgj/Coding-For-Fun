#include<bits/stdc++.h>
using namespace std;
int n;
int a[2];
int ans=0;
int main(){
	cin>>n;
	int maxn=1,f=0;
	cin>>a[0];
	for(int i=2;i<=n;i++){
		cin>>a[f^=1];
		if(a[f]==a[f^1]+1) maxn++;
		else {
			ans=max(maxn,ans);
			maxn=1;
		}		
	}
	cout<<ans<<endl;
} 
