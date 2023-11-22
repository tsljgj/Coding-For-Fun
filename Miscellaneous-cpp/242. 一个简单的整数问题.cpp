#include<bits/stdc++.h>
#define lowbit(x) x&(-x)
using namespace std;
int n,m;
int a[100020];
int c[100020];
void add(int x,int val){
	for(;x<=n;x+=lowbit(x)){
		c[x]+=val;
	}
}
int query(int x){
	int re=0;
	for(;x;x-=lowbit(x)){
		re+=c[x];
	}
	return re;
}
int main(){
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	for(int i=1;i<=n;i++) add(i,a[i]-a[i-1]);
	
	for(int i=1;i<=m;i++){
		char o;
		cin>>o;
		if(o=='Q') {
			int x;
			cin>>x;
			cout<<query(x)<<endl;
		}
		else {
			int l,r,val;
			cin>>l>>r>>val;
			add(l,val);
			add(r+1,-val);
		}
	}
	
}
