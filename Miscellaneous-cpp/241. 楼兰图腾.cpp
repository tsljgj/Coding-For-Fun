#include<bits/stdc++.h>
using namespace std;	
int n;
int y[200020];
long long rig[200020], lef[200020];
int t[200020];
long long ans1=0,ans2=0;
void add(int x,int k){
	for(;x<=n;x+=x&(-x)){
		t[x]+=k;
	}
}

long long query(int x){
	int re=0;
	for(;x;x-=x&(-x)){
		re+=t[x];
	}
	return re;
}

int main(){
	cin>>n;
	for(int i=1;i<=n;i++) {
		cin>>y[i];
	}
	
	memset(t,0,sizeof(t));
	
	for(int i=1;i<=n;i++){
		lef[i]=query(n)-query(y[i]);
//		cout<<query(n)<<"-"<<query(y[i])<<endl;
		add(y[i],1);
	}
	
	memset(t,0,sizeof(t));
	
	for(int i=n;i>=1;i--){
		rig[i]=query(n)-query(y[i]);
//		cout<<rig[i]<<endl;
//		cout<<query(n)<<"-"<<query(y[i])<<endl;

		add(y[i],1);
	}
	
	for(int i=1;i<=n;i++){
		ans1+=rig[i]*lef[i];
		ans2+=(i-1-lef[i])*(n-i-rig[i]);
	}
	
	cout<<ans1<<" "<<ans2<<endl;
	return 0;
	
}
