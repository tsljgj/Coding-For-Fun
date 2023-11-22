#include<bits/stdc++.h>
using namespace std;
int n,c;
int a[100020];
//int maxn=0;
bool valid(int mid){
	int num=1, left=1;
	for(int i=2;i<=n;i++){
		if(a[i]-a[left]>=mid){
			left=i;
			num++;
		}
	}
	return num>=c;
}
int main(){
	cin>>n>>c;
	for(int i=1;i<=n;i++) {
		cin>>a[i];
//		maxn=max(a[i],maxn); 
	}
	sort(a+1,a+n+1);
	int l=1, r=1e9;
	while(l<r){
		int mid=(l+r+1)>>1;
		if(valid(mid)) l=mid; else r=mid-1;
	}
	cout<<l<<endl;
	return 0;
}
