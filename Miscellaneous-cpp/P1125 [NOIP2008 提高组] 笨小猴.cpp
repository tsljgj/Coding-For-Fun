#include<bits/stdc++.h>
using namespace std;
int b[1000];
int a[1000];
int main(){
	string s;
	a[1]=1;
	a[0]=1;
	for(int i=2;i<=199;i++){
		if(a[i]==0) {
			int t=i;
			while(t<=199){
				t+=i;
				a[t]=1;
			}
		}		
	} 
	
	cin>>s;
	for(int i=0;i<s.size();i++){
		b[int(s[i])]++;
	}
	
	int maxn=0, minn=1e9;
	for(int i='a';i<='z';i++){
		maxn=max(maxn,b[i]);
		if(b[i]!=0)
			minn=min(minn,b[i]);
	}
	
	if(a[maxn-minn]) cout<<"No Answer"<<endl<<0<<endl;
	else cout<<"Lucky Word"<<endl<<maxn-minn<<endl;
}
