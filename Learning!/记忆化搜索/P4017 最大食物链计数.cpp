#include<bits/stdc++.h>
using namespace std;
int n,m;
bool v[500020];
vector<int> a[500020];
int in[500020];
int f[500020];
int F(int i){
	if(v[i]) return f[i];
	v[i]=1;
	f[i]=a[i].size()==0;
	for(int j=0;j<a[i].size();j++){
		f[i]=(f[i]+F(a[i][j]))%80112002;
	}
	return f[i];
}
int main(){
	cin>>n>>m;
	for(int i=1;i<=m;i++){
		int y,x;
		cin>>y>>x;
		a[x].push_back(y); 
		in[y]++;
	}
	int ans=0;
	for(int i=1;i<=n;i++){
		if(in[i]==0&&a[i].size()>0){
			ans=(ans+F(i))%80112002;
		}
	}
	cout<<ans<<endl;
	return 0;
}
