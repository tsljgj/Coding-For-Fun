#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[2000200],q[2000200],head=1,tail=0;
int main(){
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];	
	cout<<0<<endl;
	for(int i=1;i<n;i++){
		while(head<=tail&&i-q[head]+1>m) head++;
		while(head<=tail&&a[q[tail]]>a[i]) tail--;
		q[++tail]=i;
		cout<<a[q[head]]<<endl;
	}
	return 0;
}
