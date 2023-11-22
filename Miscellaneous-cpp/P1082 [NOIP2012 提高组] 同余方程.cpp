#include<bits/stdc++.h>
// ax=1(mod b)
//ax+by=gcd(a,b)
using namespace std;
long long x,y;
void exgcd(long long a,long long b){
	if(b==0){
		x=1;
		y=0;
		return;
	}
	
	exgcd(b,a%b);
	
	long long tx=x;
	x=y;
	y=tx-(a/b)*y;
}
int main(){
	long long a,b;
	cin>>a>>b;
	exgcd(a,b);
	x=(x%b+b)%b;
	cout<<x<<endl;
} 
