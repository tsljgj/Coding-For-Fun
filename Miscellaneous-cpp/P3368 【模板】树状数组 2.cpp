#include<bits/stdc++.h>
using namespace std;
int n,m; 
int c[500020];
int lowbit(int x){
	return x&(-x);
}

void add(int x,int k){
	while(x<=n){
		c[x]+=k;
		x+=lowbit(x);
	}
}

void query(int x){
	int ans=0;
	while(x!=0){
		ans+=c[x];
		x-=lowbit(x);
	}
	cout<<ans<<endl;
}
int main(){
	cin>>n>>m;
	int now,last;
	for(int i=1;i<=n;i++){
		cin>>now;
		add(i,now-last);
		last=now;
	}
	
	while(m--){
		char ch;
		cin>>ch;
		if(ch=='1'){
			int x,y,k;
			cin>>x>>y>>k;
			add(x,k), add(y+1,-k);
		}
		else{
			int x;
			cin>>x;
			query(x);
		}
	}
}
