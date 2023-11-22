#include<bits/stdc++.h>
using namespace std;
long long mod=100003;      //小心数据范围... 
long long fastPower(long long b,long long e,long long d){
	if(e==0) return 1%d;
	
	long long base=b,ans=1;
	while(e!=0){
		if(e%2) ans=ans*base%d;
		base=base*base%d;
		e>>=1;
	}
	return ans;
}
int main(){
	long long n,m;
	cin>>m>>n;
	long long ans=(fastPower(m,n,mod)-m*fastPower(m-1,n-1,mod)%mod+mod)%mod;
	cout<<ans<<endl;

} 
