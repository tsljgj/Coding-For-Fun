#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
bool prime(LL x){
	if(x==2) return 1;
	for(LL i=2;i<=x/2+1;i++){
		if(x%i==0) return 0;
	}
	return 1;
}
int main(){
	LL n;
	cin>>n;
	for(LL i=2;i<=n;i++){
		if(n%i==0&&prime(i)) {
			cout<<n/i<<endl;
			return 0;
		}
	}
}
