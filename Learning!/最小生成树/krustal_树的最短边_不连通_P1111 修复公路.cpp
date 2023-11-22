#include<bits/stdc++.h>
using namespace std;
int f[1010];
int r(int num){
	if(f[num]==num) return num;
	else{
		f[num]=r(f[num]);
		return f[num];
	}
}
int main(){
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		f[i]=i;
	} 
	int cnt=n-1;
	int x,y;
	pair<int,pair<int,int> > a[100010];
	for(int i=0;i<m;i++){
		cin>>a[i].second.first>>a[i].second.second>>a[i].first;
	}
	
	sort(a,a+m);
	
	for(int i=0;i<m;i++){
		x=r(a[i].second.first);
		y=r(a[i].second.second);
		if(x!=y){
			f[x]=y;          //±ðÂ©ÁË 
			cnt--;
			if(cnt==0) {
				cout<<a[i].first<<endl;
				return 0;
			}
		}
	}
	
	cout<<-1<<endl;
	return 0;
}
