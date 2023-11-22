#include<bits/stdc++.h>
using namespace std;
double eps=1e-8;
double s, a, b;
double ans=0;
bool valid(double mid){
	double t1=mid/b+(s-mid)/a;
	double t=(mid-a*mid/b)/(a+b);
	double t2=mid/b+t+(s-a*mid/b-t*a)/b;
	if(t1<=t2) return 1;
	else return 0;
}
int main(){
	cin>>s>>a>>b;
	double l=0, r=s;
	for(int i=1;i<(1<<10);i++){
		double mid=(r+l)/2;
		if(valid(mid)) r=mid; else l=mid;
	}
	cout<<fixed<<setprecision(6)<<l/b+(s-l)/a<<endl;
}

