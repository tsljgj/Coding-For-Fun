#include<bits/stdc++.h>
#define fi first
#define se second
using namespace std;
pair<int,pair<int,int> > a[400020];
int f[400020];
int r(int i){
	if(f[i]==i) return i;
	f[i]=r(f[i]);
	return f[i];
}
int main(){
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++) f[i]=i;
	for(int i=1;i<=m;i++){
		cin>>a[i].se.fi>>a[i].se.se>>a[i].fi;
	}
	
	sort(a+1,a+m+1);
	
	int cnt=n-1;
	for(int i=1;i<=m;i++){
		int x=r(a[i].se.fi);
		int y=r(a[i].se.se);
		if(x!=y){
			f[x]=y;
			cnt--;
			if(cnt==0) {
				cout<<a[i].fi<<endl;
				return 0;
			} 
		} 
		
		
	}
	
} 
