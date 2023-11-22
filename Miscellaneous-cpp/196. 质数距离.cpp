#include<bits/stdc++.h>
using namespace std;
const int MAXN=1000020;
int l,r;
int prime[MAXN], tot=0;
int v[MAXN];
bool isprime[MAXN];
void find_prime(int n) {
	for(int i=2; i<=n; i++) {
		if(v[i]==0) {
			v[i]=i;
			prime[++tot]=i;
		}
		for(int j=1; j<=tot; j++) {
			if(prime[j]>v[i]||prime[j]*i>n) break;
			v[prime[j]*i]=prime[j];
		}
	}
}
int main() {
	cin>>l>>r;
	find_prime(int(sqrt(r)));
	
	for(int i=1;i<=tot;i++){
		for(int j=(l/prime[i]);j<=(r/prime[i]);j++){
			isprime[j*prime[i]]=1;
		}
	}
	
	int last=0;
	int maxx=0, minn=1e9;
	int maxnum1, maxnum2, minnum1, minnum2;
	
	for(int i=l;i<=r;i++){
		if(!isprime[i]){
			int x=i-last;
			if(last!=0){
				if(x>maxx){
					maxx=x;
					maxnum1=last, maxnum2=i;
				}
				if(x<minn){
					minn=x;
					minnum1=last, minnum2=i;
				}
			}
				
			last=i;
		}
	} 
	
	cout<<maxx<<" "<<minn<<endl;
}
