#include<bits/stdc++.h>
using namespace std;
int n,m;
int f[50020][21];
int main(){
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>f[i][0];
	}
	
	cin>>m;
	for(int j=1;j<=log2(n);j++){
		for(int i=1;i+(1<<j)-1<=n;i++){
			f[i][j]=max(f[i][j-1],f[i+(1<<(j-1))][j-1]);
		}
	}
	
	while(m--){
		int l,r;
		cin>>l>>r;
		
		int len=log2(r-l+1);
		cout<<max(f[l][len],f[r-(1<<len)][len]);
	}
	return 0;
}
