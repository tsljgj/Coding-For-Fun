#include<bits/stdc++.h>
using namespace std;
int n;
double k;
double a[100020];
bool valid(double mid){
	int num=0;
	for(int i=1;i<=n;i++){
		num+=int(a[i]/mid);
	}
	return num>=k;
}
int main(){
	cin>>n>>k;
	for(int i=1;i<=n;i++) cin>>a[i];
	double l=0, r=1e9;
	double eps=1e-4;
	for(int i=1;i<=10000;i++){                             //�ù̶�������ѭ����������  //ʵ����Χ�ڵĶ����� l=mid, r=mid, mid=(l+r)/2 
		double mid=(l+r)/2;
		if(valid(mid)) l=mid; else r=mid; 
	}
	cout<<fixed<<setprecision(2)<<double(int(l*100))/100<<endl;
	return 0;
}
