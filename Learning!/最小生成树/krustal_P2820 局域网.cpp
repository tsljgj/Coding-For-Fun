#include<bits/stdc++.h>
using namespace std;
int n,m;
pair<int,pair<int,int> > a[10010];
int f[110],sum=0;
int r(int num){
	if(f[num]==num) return num;
	else{
		f[num]=r(f[num]);
		return f[num];
	}
}
int main(){
	cin>>n>>m;
	for(int i=1;i<=n;i++) f[i]=i;               //±ðÂ©ÁË£¡£¡£¡ 
	for(int i=0;i<m;i++){
		cin>>a[i].second.first>>a[i].second.second>>a[i].first;	
		sum+=a[i].first;
	}
	sort(a,a+m);
	for(int i=0;i<m;i++){
		int x=r(a[i].second.first);
		int y=r(a[i].second.second);
		if(x!=y){
			f[x]=y;
			sum-=a[i].first;
		}
	}
	
	cout<<sum<<endl;
} 
