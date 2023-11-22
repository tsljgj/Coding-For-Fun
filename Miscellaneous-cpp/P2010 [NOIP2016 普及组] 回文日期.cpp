#include<bits/stdc++.h>
using namespace std;
long long ans=0;
int main(){
	int l,r;
	cin>>l>>r;
	int s[12]={31,29,31,30,31,30,31,31,30,31,30,31};
	for(int i=1;i<=12;i++){
		for(int j=1;j<=s[i-1];j++){
			int c=j%10*1000+j/10*100+i%10*10+i/10;
			int d=c*10000+i*100+j;
			if(d>=l&&d<=r){
				ans++;
			}
		}
	}
	cout<<ans<<endl;
}
