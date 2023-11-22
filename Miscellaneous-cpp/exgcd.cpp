#include<bits/stdc++.h>
using namespace std;
int x,y;
void exgcd(int a,int b){
	if(b==0){
		x=1, y=0;
		return;
	}
	exgcd(b,a%b);
	int t=x;
	x=y;
	y=t-a/b*y;
}
int main(){
	int n,p;
	cin>>n>>p;
	for(int i=1;i<=n;i++){
		exgcd(i,p);
		cout<<(x%p+p)%p<<endl;
	}
}
