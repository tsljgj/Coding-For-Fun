#include<bits/stdc++.h>
#define LL long long
using namespace std;
const LL MOD=100003;

LL quickmi(LL x,LL y){
//	if(y==0) return 
	LL re=1, base=x;
	while(y){
		if(y%2==1) re=re*base%MOD;
		base=base*base%MOD;
		y>>=1; 
	}
	return re;
}
int main(){
	LL n,m;
	cin>>m>>n;
	cout<<((quickmi(m,n)-m*quickmi(m-1,n-1))%MOD+MOD)%MOD<<endl;
	return 0;
}
