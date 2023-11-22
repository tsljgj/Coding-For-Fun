#include<bits/stdc++.h>
#define fi first
#define se second
using namespace std;
const int INF=1e9;
int n;
pair<int,int> a[200020];
int ans=1;
int main(){
	cin>>n;
	for(int i=1;i<=n;i++) {
		cin>>a[i].fi;
		a[i].se=i;
	}
	sort(a+1,a+n+1);
	
	int tend=-1,i=1;
	while(a[i+1].fi==a[i].fi){
		i++;
	}
	i++;
	for(;i<=n;i++){
		int j=i;
		while(a[i+1].fi==a[i].fi){
			i++;
		}
				
		if(tend==-1){
			if(a[i].se>a[j-1].se){
				tend=1;
			}
		}
		else{
			if(a[j].se<a[j-1].se){
				tend=-1;
				ans++;
			}
		}
		
	}
	cout<<ans<<endl;
}
