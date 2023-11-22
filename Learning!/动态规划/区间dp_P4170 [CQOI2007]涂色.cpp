#include<bits/stdc++.h>
using namespace std;
int n;
string a;
int f[500][500];
int main(){
	memset(f,0x3f,sizeof(f));
	cin>>a;
	n=a.size();
	
	for(int i=1;i<=n;i++){
		f[i][i]=1;
	}
	
	for(int l=1;l<n;l++){
		for(int i=1;i+l<=n;i++){
			int j=i+l;
			if(a[i-1]==a[j-1]) f[i][j]=min(f[i][j-1],f[i+1][j]);
			else{
				for(int k=i;k<=j;k++){
					f[i][j]=min(f[i][j],f[i][k]+f[k+1][j]);
				}
			}
			
		}
		
	}
	
	cout<<f[1][n]<<endl;
	return 0;
} 
