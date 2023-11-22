#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[100020];
int ans=0;
int main(){
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	int rest=m;
	for(int i=1;i<=n;){
		if(rest-a[i]>=0){
			rest-=a[i];
			i++;
		}
		else{
			ans++;
			rest=m;
		}
	}
	if(rest>=0&&rest!=m) ans++;
	cout<<ans<<endl;
	return 0;
}
