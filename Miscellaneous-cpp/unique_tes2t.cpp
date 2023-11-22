#include<bits/stdc++.h>
using namespace std;
int main(){
	int n;
	cin>>n;
	int a[100];
	for(int i=1;i<=n;i++) cin>>a[i];
	int tot=unique(a+1,a+n+1)-a-1;
	for(int i=1;i<=tot;i++) cout<<a[i]<<endl;
}
