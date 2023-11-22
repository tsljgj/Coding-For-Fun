#include<bits/stdc++.h>
using namespace std;
int main(){
	int k=0;
	int n;
	cin>>n;
	for(int i=10000;i<=30000;i++){
		int a[5];
		int t=i,cnt=0;
		while(t!=0){
			a[cnt]=t%10;
			t/=10;
			cnt++;
		}
		int x=a[0]+a[1]*10+a[2]*100, y=a[1]+a[2]*10+a[3]*100, z=a[2]+a[3]*10+a[4]*100;
		if(x%n==0&&y%n==0&&z%n==0) {
			cout<<i<<endl;
			k=1;
		}
	}
	if(k==0) cout<<"No"<<endl;
	return 0;
}
