#include<bits/stdc++.h>
using namespace std;
int n,L;
double l=-1e6,r=1e6;
double eps=1e-5;
double a[100020], b[100020], s[100020];
int main(){
	cin>>n>>L;
	for(int i=1;i<=n;i++) cin>>a[i];
	while(r-l>eps){                 //�������ڵĻ�������ѭ����ע������һ��ʵ������ 
		double mid=(l+r)/2;    //double ����λ��>> 
// 		for(int i=1;i<=n;i++) b[i]=a[i]-mid;
		for(int i=1;i<=n;i++) s[i]=s[i-1]+a[i]-mid;
		double ans=-1e10, min_val=1e10;
		for(int i=L;i<=n;i++){           //��L��ʼ 
			min_val=min(min_val,s[i-L]);
			ans=max(ans,s[i]-min_val);
		}
		if(ans>=0) l=mid; else r=mid;
	}
	
	cout<<int(r*1000)<<endl;
	return 0;
}
