#include<bits/stdc++.h>
using namespace std;
const int MOD=19260817;
int a0,b0;
int x,y;
int getint(){
	char ch=getchar();
	int re=0;
	while(ch<'0'||ch>'9'&&ch!=EOF) ch=getchar();
	while(ch>='0'&&ch<='9'){
		re=re*10+ch-'0';
		re%=MOD;
		ch=getchar();
	}
	return re;
}

void exgcd(int a,int b){
	if(b==0){
		x=1,y=0;
		return;
	}
	exgcd(b,a%b);
	int t=x;
	x=y;
	y=t-a/b*y;
}
int main(){
	int a0=getint();
	int b0=getint();
	if(b0==0) {
		cout<<"Angry!"<<endl;
		return 0;
	}
	exgcd(b0,MOD);
	x=(x%MOD+MOD)%MOD;	
	cout<<(a0*(long long)(x)%MOD+MOD)%MOD<<endl;
}
