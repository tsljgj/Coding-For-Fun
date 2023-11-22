#include<bits/stdc++.h>
#define LL long long
using namespace std;
const int MAXN=20;
int n;
LL mul=1;
LL m[MAXN], a[MAXN], Mi[MAXN];
LL x,y;
LL ans=0;
void exgcd(LL aa,LL bb){
	if(!bb){
		x=1, y=0;
		return;
	}
	exgcd(bb,aa%bb);
	LL tt=x;
	x=y;
	y=tt-aa/bb*y;
}
int main(){
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>m[i]>>a[i];
		mul*=m[i];
	}
	
	for(int i=1;i<=n;i++){
		Mi[i]=mul/m[i];
		exgcd(Mi[i],m[i]);
		ans+=a[i]*Mi[i]*x;
	}
	
	cout<<(ans%mul+mul)%mul<<endl;
}
