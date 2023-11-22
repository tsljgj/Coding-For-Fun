#include<bits/stdc++.h>
using namespace std;
typedef unsigned long long ull;
const ull base=131, prime=14523, MODE=2005011120050111;
int n;
ull t[3020*3020];
string a,b;
int main(){
	cin>>n;
	cin>>a>>b;
	
	for(int i=0;i<n;i++){
		ull v=0;	int p=0;
		
		for(int j=i;j<n;j++){
			while(p<n&&a[p]!=b[j]) p++;
			if(p>=n) break;
			p++;
			v=(1LL*v*base+ull(b[j]))%MODE+prime;
			t[++t[0]] = v;
	
		}
		
	}
	
	sort(t+1,t+t[0]+1);
	cout<<unique(t+1,t+t[0]+1)-t-1<<endl;
	return 0;
}
