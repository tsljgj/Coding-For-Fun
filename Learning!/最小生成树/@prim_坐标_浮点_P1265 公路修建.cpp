#include<bits/stdc++.h>
using namespace std;
int n;
bool v[5010];
double ans,mind,d[5010];          //用double 
double x[5010],y[5010];
double dist(int p,int q){
	return hypot(x[p]-x[q],y[p]-y[q]);
}
int main(){
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>x[i]>>y[i];
	}
//	memset(d,0x3f,sizeof(d));        //为啥不行了     double的赋值不一样   
	for (int i = 1; i < n; i++) {
		d[i] = 1e30;
	}
	for(int i=0;i<n;i++){
		int mini;
		mind=1e30;
		for(int j=0;j<n;j++){
			if(v[j]==0){
				if(d[j]<mind){
					mind=d[j];
					mini=j;
				}
			}
		}
		v[mini]=1;
		ans+=mind;
		for(int j=0;j<n;j++){
			if(!v[j]){
				d[j]=min(d[j],dist(j,mini));
			}
		}
	}
	
	cout<<fixed<<setprecision(2)<<ans<<endl;
	return 0;
}
