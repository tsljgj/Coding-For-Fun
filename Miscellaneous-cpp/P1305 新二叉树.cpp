#include<bits/stdc++.h>
using namespace std;
string s,ss;
int main(){
	int n;
	cin>>n;
	cin>>s;
	for(int i=2;i<=n;i++){
		cin>>ss;
		int x=s.find(ss[0]);
		s.erase(x,1);
		s.insert(x,ss);
	}
	
	for(int i=0;i<s.size();i++) {
		if(s[i]!='*') cout<<s[i];
	}
	return 0;
}
