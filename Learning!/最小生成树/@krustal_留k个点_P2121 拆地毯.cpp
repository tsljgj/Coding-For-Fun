#include<bits/stdc++.h>
#define fi first
#define se second
using namespace std;
pair<int,pair<int,int> > a[200020];
int sum=0;
int f[100020];
int r(int i){
	if(f[i]==i) return i;
	f[i]=r(f[i]);
	return f[i];
}
int main(){
	int n,m,k;
	cin>>n>>m>>k;
	for(int i=1;i<=n;i++) f[i]=i;
	for(int i=1;i<=m;i++){
		cin>>a[i].se.fi>>a[i].se.se>>a[i].fi;
	}
	
	sort(a+1,a+m+1);
	
	int cnt=0;
	for(int i=m;i>=1;i--){
		int x=r(a[i].se.fi);
		int y=r(a[i].se.se);
		
		if(x!=y){
			f[x]=y;
			sum+=a[i].fi;
			cnt++;
			if(cnt==k) {
				cout<<sum<<endl;
				return 0;
			} 
		} 
		
	}
	return 0;
	
} 
