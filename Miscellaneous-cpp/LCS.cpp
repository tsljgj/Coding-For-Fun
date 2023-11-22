#include<bits/stdc++.h>
using namespace std;
int n;
string s1,s2;
string f[4000][4000];
int main(){
	cin>>s1>>s2;
	
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			if(s1[i]==s2[j]) {
				memcpy(f[i][j],f[i-1][j-1],strlen(f[i-1][j-1].size()));
				f[i][j]+=s1[i];
			}
			else {
				if(f[i-1][j].size()>f[i][j-1]) memcpy(f[i][j],f[i-1][j],f[i-1][j].size()+1);
				else memcpy(f[i][j],f[i][j-1],f[i][j-1].size()+1);
			}
		}
	}
	
	cout<<f[n][n]<<endl;
	return 0;
}
