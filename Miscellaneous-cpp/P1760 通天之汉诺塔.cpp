#include<bits/stdc++.h>
using namespace std;
int main(){
	int n;
	cin>>n;
	int a[20000];
	a[1]=1;
	for(int i=2;i<=n;i++){
		a[i]=2*a[i-1]+1;
	}
	cout<<a[n]<<endl;
	return 0;
}
