#include<bits/stdc++.h>
#define fi first
#define se second
#define mp make_pair
using namespace std;
const int M=100020, N=20020;
int n,m;
pair<int,pair<int,int> > a[M];
int f[N*2];
int find(int x){
	if(f[x]==x) return x;
	return f[x]=find(f[x]);
}

void U(int x,int y){
	int X=find(x);
	int Y=find(y);
	f[X]=Y;
}

int main(){
	cin>>n>>m;
	for(int i=1;i<=m;i++) cin>>a[i].se.fi>>a[i].se.se>>a[i].fi;
	for(int i=1;i<=2*n;i++) f[i]=i;
	
	sort(a+1,a+m+1);
	
	for(int i=m;i>=1;i--){
		U(a[i].se.fi,a[i].se.se+n);
		U(a[i].se.se,a[i].se.fi+n);
		if(find(a[i].se.fi)==find(a[i].se.fi+n)) {
			cout<<a[i].fi<<endl;
			return 0;
		}
	}
	
	cout<<0<<endl;
	return 0;
}
