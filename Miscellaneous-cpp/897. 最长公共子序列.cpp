#include<bits/stdc++.h>
using namespace std;
int n,m;
char s1[4000],s2[4000];
int f[4000][4000];
int main(){
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>s1[i];
	for(int j=1;j<=m;j++) cin>>s2[j];
	
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			if(s1[i]==s2[j]) f[i][j]=f[i-1][j-1]+1;
			else f[i][j]=max(f[i-1][j],f[i][j-1]);	
		}
	}
	
	cout<<f[n][m]<<endl;
	return 0;
}
