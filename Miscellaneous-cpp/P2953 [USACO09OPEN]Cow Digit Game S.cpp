#include<bits/stdc++.h>
using namespace std;
int n;
int f[1000020];
int maxd,mind;
void check(int x){
	while(x!=0){
		int d=x%10;
		x/=10;
		if(d!=0){
			maxd=max(maxd,d);
			mind=min(mind,d);
		}
	}	
}

void prepare(){
	for(int i=1;i<=9;i++) f[i]=1;
	for(int i=10;i<=1000000;i++){
		maxd=0, mind=9;
		check(i);
		if(f[i-mind]==0||f[i-maxd]==0) f[i]=1;
		else f[i]=0;
	}
}

int main(){
	prepare();
	cin>>n;
	for(int i=1;i<=n;i++){
		int m;
		cin>>m;
		if(f[m]) cout<<"YES"<<endl;
		else cout<<"NO"<<endl;
	}
	
} 
