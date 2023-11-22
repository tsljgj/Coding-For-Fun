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
		int mid=(l+r+1)>>1;                    //����ʱ��lӦ������mid, ����(l+r+1)/2, ������l=mid����ִ�У�������ֵ���1ʱ�� 
		if(valid(mid)) l=mid; else r=mid-1;
	}
	cout<<l<<endl;
	return 0;
}
