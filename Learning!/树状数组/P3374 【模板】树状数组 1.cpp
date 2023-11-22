#include<bits/stdc++.h>
using namespace std;
int n,m;
int c[50001];
int lowbit(int x){
	return x&(-x);
}
void add(int a,int b){
	while(a<=n){
		c[a]+=b;
		a+=lowbit(a);
	}
}

int sum(int a){
	int ans=0;
	while(a!=0){
		ans+=c[a];
		a-=lowbit(a);
	}
	return ans;
}
int main(){
	cin>>n>>m;
	memset(c,0,sizeof(c));
	for(int i=1;i<=n;i++){
		int num;
		cin>>num;
		add(i,num);
	}
	
	for(int i=1;i<=m;i++){
		int k,p,q;
		cin>>k>>p>>q;
		if(k==1){
			add(p,q);
		}
		else{
			cout<<sum(q)-sum(p-1)<<endl;
		}
	} 
	return 0;
} 
