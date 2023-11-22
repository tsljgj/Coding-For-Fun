#include<bits/stdc++.h>
#define fi first
#define se second
#define mp make_pair
using namespace std;
int n,m,k;
int sum=0;
pair<int,pair<int,int> > a[100020];
int f[100020];
int root(int i){
	if(f[i]==i) return i;
	
	f[i]=root(f[i]);
	
	return f[i];
}
int main(){
	cin>>n>>m>>k;
	
	for(int i=1;i<=n;i++) f[i]=i;
	
	for(int i=1;i<=m;i++){
		cin>>a[i].se.fi>>a[i].se.se>>a[i].fi;
	}
	
	sort(a+1,a+m+1);
	
	int cnt=1;
	
//	while(n>1+k-1)
	for(int i=1;i<=m;i++){
		int x=root(a[i].se.fi);
		int y=root(a[i].se.se);
		
		if(x!=y){
			f[x]=y;
			sum+=a[i].fi;
			n--;
			if(n==k) {
				cout<<sum<<endl;
				return 0;
			}
		}
		
	}
	
	cout<<"No Answer"<<endl;
	return 0;
}
