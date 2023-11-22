#include<bits/stdc++.h>
using namespace std;
typedef unsigned long long ull;
const ull prime=1375693, MODE=2005011120050111;
ull base=131;
int n;
ull a[10020];
ull hash(string s){
	ull ans=0;
	for(int i=0;i<s.size();i++){
		ans=(ans*base+ull(s[i]))%MODE+prime;
	}
	return ans;
}
int main(){
	cin>>n;
	for(int i=1;i<=n;i++){
		string s;
		cin>>s;
		a[i]=hash(s);
	}
	
	sort(a+1,a+n+1);
	cout<<unique(a+1,a+n+1)-a-1<<endl;
	return 0;
} 
