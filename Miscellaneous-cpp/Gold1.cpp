#include<bits/stdc++.h>
using namespace std;
int n;
int c[200020], l[200020];
long long ans=0;

void C(int x,int y){
	for(;x<=n;x+=x&(-x)) c[x]+=y;
}

int S(int x){
	int sum=0;
	for(;x;x-=x&(-x)) sum+=c[x];
	return sum;
}

int main(){
	cin>>n;
	for(int i=1;i<=n;i++){
		int x; cin>>x;
		ans+=S(i)-S(l[x]);
		
		if(l[x]>0) C(l[x],-1);
		C(i,1);
		l[x]=i;
	}
	cout<<ans<<endl;
	return 0;
}
