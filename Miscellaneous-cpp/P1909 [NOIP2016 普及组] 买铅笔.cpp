#include<bits/stdc++.h>
using namespace std;
int ans=(1<<31)-1;
int main(){
	int n;
	cin>>n;
	for(int i=1;i<=3;i++) {
		int a,p;
		cin>>a>>p;
		ans=min(ans,(n%a==0?n/a*p:(n/a+1)*p));
	}
	
	cout<<ans<<endl;
	return 0;
}
