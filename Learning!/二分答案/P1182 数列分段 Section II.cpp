#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[100020];
bool valid(int mid){
	int rest=mid;
	int num=1;
	for(int i=1;i<=n;i++){
		if(rest>=a[i]){
			rest-=a[i];
		}
		else{
			num++;
			rest=mid-a[i];
		}
	}
	return num<=m;
}
int main(){
	cin>>n>>m;
	long long sum=0;              //为啥要那么严谨？？ 
	int maxn=0;
	for(int i=1;i<=n;i++) {
		cin>>a[i];
		sum+=a[i];
		maxn=max(maxn,a[i]);
	}
	
	int l=maxn, r=sum;
	while(l<r){
		int mid=(l+r)>>1;
		if(valid(mid)) r=mid; else l=mid+1;
	}
	
	cout<<l<<endl;
	return 0;
}
