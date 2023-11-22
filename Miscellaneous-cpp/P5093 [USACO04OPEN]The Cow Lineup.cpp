#include<bits/stdc++.h>
using namespace std;
int n,k;
int a[10020];
int ans=1;
int main(){
	cin>>n>>k;
	int cnt=0;
	for(int i=1;i<=n;i++){
		int x;
		cin>>x;
		if(a[x]==0) {
			a[x]=1;
			cnt++;
		}
		if(cnt==k) {
			cnt=0;
			memset(a,0,sizeof(a));
			ans++;
		}	
	}
	cout<<ans<<endl;
}
