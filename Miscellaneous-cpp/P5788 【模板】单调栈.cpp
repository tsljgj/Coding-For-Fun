#include<bits/stdc++.h>
using namespace std;
const int INF=1000000001;
int n;
int s[3000020], p=0;
int f[3000020];
int pos[3000020];
int main(){
	cin>>n;
	s[0]=INF;
	for(int i=1;i<=n;i++){
		int x; cin>>x;
		if(x<=s[p]){
			s[++p]=x;
			pos[p]=i;
		}
		else{
			while(s[p]<x){
				if(f[pos[p]]==0) f[pos[p]]=i;
				p--;
			}
			s[++p]=x;
			pos[p]=i;
		}
	}
	for(int i=1;i<=n;i++){
		cout<<f[i]<<" ";
	}
}
