#include<bits/stdc++.h>
using namespace std;
int n,k;
int a[100020];
bool valid(int mid){
	int num=0;
	for(int i=1;i<=n;i++){
		num+=a[i]/mid;
	}
	return num>=k;
}
int main(){
	cin>>n>>k;
	for(int i=1;i<=n;i++) cin>>a[i];
	int l=0, r=1e9;
	while(l<r){
		int mid=(l+r+1)>>1;                    //求后继时，l应当保持mid, 所以(l+r+1)/2, 不能让l=mid反复执行（当两个值相差1时） 
		if(valid(mid)) l=mid; else r=mid-1;
	}
	cout<<l<<endl;
	return 0;
}
