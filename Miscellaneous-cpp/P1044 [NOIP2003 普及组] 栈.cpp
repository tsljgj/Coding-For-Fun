#include<bits/stdc++.h>
using namespace std;
int n;
int f[20];
int main(){
	cin>>n;
	f[0]=1;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=i;j++){
			f[i]+=f[j-1]*f[i-j];
		}
	}
	cout<<f[n]<<endl;
	return 0;
}
