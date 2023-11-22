#include<bits/stdc++.h>
using namespace std;
int a[120][120];
int main(){
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			char x;
			cin>>x;
			if(x=='*') {
				a[i][j]=-100;
				a[i+1][j]++, a[i+1][j+1]++, a[i+1][j-1]++;
				a[i][j+1]++, a[i][j-1]++;
				a[i-1][j]++, a[i-1][j+1]++, a[i-1][j-1]++;
			}	
		} 
	}
	
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			if(a[i][j]<0) cout<<"*";
			else cout<<a[i][j];
		}
		cout<<endl;
	} 
}
