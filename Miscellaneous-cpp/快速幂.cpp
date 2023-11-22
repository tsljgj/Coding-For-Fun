#include<bits/stdc++.h>
using namespace std;
long long ans=1, base;
int main(){
	long long a,b,p;
	cin>>a>>b>>p;
	//a^b=?(mod p)
	long long b0=b;
	if(b==0) ans=1%p;
	base=a;
	while(b){
		if(b%2) ans=ans*base%p;
		base=base*base%p;		
		b>>=1;
	}
	
	cout<<a<<"^"<<b0<<" mod "<<p<<"="<<ans<<endl;
	return 0; 
}
