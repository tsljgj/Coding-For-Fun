#include<bits/stdc++.h>
using namespace std;
int a[10020];
int ans=0;
int i,j;
int k,x,y,z,n,m;

int main(){
	int n,m;
	cin>>n>>m;
	for(i=1;i<=n;i++){
		cin>>k;
		a[i]=k<<1;
	}
	
	for(i=1;i<=m;i++){
		cin>>x>>y>>z;
		a[x]+=z;
		a[y]+=z; 
	} 
	
	sort(a+1,a+n+1);
	for(j=1;j<=n;j+=2){       //j+=2¶ø²»ÊÇj-2 
		ans+=a[j+1]-a[j];
	}
	
	cout<<ans/2<<endl;
	return 0;
}
