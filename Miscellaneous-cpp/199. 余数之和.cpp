#include<bits/stdc++.h>
#define LL long long 
using namespace std;
LL ans=0;
LL n,k;
LL l,r;
int main(){
	cin>>n>>k;
	ans=n*k;
	
	for(l=1;l<=n;l=r+1){
		if(k/l==0) break;
		r=min(n,(k/(k/l)));
		ans-=(k/l)*(l+r)*(r-l+1)/2;
	}
	
	cout<<ans<<endl;
}
