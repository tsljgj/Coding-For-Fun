#include<bits/stdc++.h>
#define lowbit(x) x&(-x)
using namespace std;
const int MAXN=100020;
int n,m;
long long a[MAXN], sum[MAXN], c[MAXN], cc[MAXN];
void add(long long x,long long val,long long tree[]){
	for(;x<=n;x+=lowbit(x)) tree[x]+=val;
}

long long query(long long x,long long tree[]){
	long long re=0;
	for(;x;x-=lowbit(x)) re+=tree[x];
	return re;
}

int main(){
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		sum[i]=sum[i-1]+a[i];
	}
	
	for(int i=1;i<=m;i++){
		char o;
		cin>>o;
		if(o=='C'){
			long long l,r,val;
			cin>>l>>r>>val;
			add(l,val,c);
			add(r+1,-val,c);
			add(l,l*val,cc);
			add(r+1,-(r+1)*val,cc);
		}
		else {
			long long l,r;
			cin>>l>>r;
			cout<<(sum[r]+query(r,c)*(r+1)-query(r,cc))-(sum[l-1]+query(l-1,c)*l-query(l-1,cc))<<endl;
		}
	}
}
