#include<bits/stdc++.h>
using namespace std;
const int MAXN=1000020;
int n;
char a[MAXN];
int nxt[MAXN];
long long ans=0;
int main(){
	cin>>n;
	for(int i=1;i<=n;i++) cin>>a[i];
	
	nxt[1]=0;
	for(int i=2, j=0;i<=n;i++){
		while(a[i]!=a[j+1]&&j>0) j=nxt[j];
		if(a[i]==a[j+1]) j++;
		nxt[i]=j;
	}
	
	for(int i=2;i<=n;i++){
		if(nxt[i]==0) continue;
		else{
			int j=i;
			while(nxt[j]>0){
				j=nxt[j];
			}
			nxt[i]=j;
			ans+=i-j;
		}
	}
	
	cout<<ans<<endl;
}
