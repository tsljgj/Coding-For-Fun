#include<bits/stdc++.h>
using namespace std;
int n,k;
long long dis[7520];
bool done[7520];
vector<long long> a;
long long dist(long long i,long long j){
	long long x,y;
	x=min(i,j);
	y=max(i,j);
	return (2019201913*x+2019201949*y)%2019201997;
}
int main(){
	cin>>n>>k;
	for(int i=2;i<=n;i++){
		dis[i]=1e30;
	}
	
	for(int i=1;i<=n;i++){
		int minn=1e30;
		int minum=-1;
		for(int j=1;j<=n;j++){
			if(!done[j])
				if(minn>dis[j]){
					minn=dis[j];
					minum=j;
				}
		}
		done[minum]=1;
		a.push_back(minn);
		for(int j=1;j<=n;j++){
			if(!done[j]){
				dis[j]=min(dis[j],dist(j,minum));
			}
		}
		
	}
	
	sort(a.begin(),a.end(),greater<long long>());
	cout<<a[k-2]<<endl;
	return 0;
}
