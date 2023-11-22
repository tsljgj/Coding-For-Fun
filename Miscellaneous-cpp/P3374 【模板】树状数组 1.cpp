#include<bits/stdc++.h>
using namespace std;
int n;
int c[500020];

int lowbit(int x){
	return x&(-x);
}

void change(int p,int x){
	for(int i=p;i<=n;i+=lowbit(i)){
		c[i]+=x;
	}
}

int query(int x){
	int re=0;
	for(int i=x;i>0;i-=lowbit(i)){
		re+=c[i];
	}
	return re;
}

int main(){
	int m;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		int x;
		cin>>x;
		change(i,x);
	}
	
	for(int i=1;i<=m;i++){
		char o;
		cin>>o;
		if(o=='1'){
			int x,k;
			cin>>x>>k;
			change(x,k);
		}
		else{
			int x,y;
			cin>>x>>y;
			cout<<query(y)-query(x-1)<<endl;
		}
	} 
	return 0;
}
