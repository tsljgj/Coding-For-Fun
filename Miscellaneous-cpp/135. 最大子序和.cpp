#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[300020];
int q[300020];
int maxn=-1e9;
int main(){
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		int x; cin>>x;
		a[i]=a[i-1]+x;
	}
	
	int l=1, r=1;
	for(int i=1;i<=n;i++) {
		while(l<=r&&q[l]<i-m) l++;
		maxn=max(maxn,a[i]-a[q[l]]);
		while(l<=r&&a[q[r]]>=a[i]) r--;
		q[++r]=i;
	}
	cout<<maxn<<endl;
}
