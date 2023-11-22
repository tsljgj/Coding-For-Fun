#include<bits/stdc++.h>
using namespace std;
int n,m,k;
bool check(int x){
	int t=k, r=n;
	int y,a;
	while(t&&r>0){
		y=r/x;
		if(y>m){ a=min(r/y-x+1,t),r-=a*y, t-=a;	}
		else r-=t*m,t=0;
	}
	return r<=0;
}
int main(){
	cin>>n>>k>>m;
	int l=1, r=n;
	while(l<=r){          //l<=r, /2, mid-1, mid+1, l-1
		int mid=(l+r)>>1;
		if(check(mid)){
			l=mid+1;
		}else{
			r=mid-1;
		}
	}
	
	cout<<l-1<<endl;
	return 0;
}
