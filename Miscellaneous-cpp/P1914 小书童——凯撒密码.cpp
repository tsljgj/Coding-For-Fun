#include<bits/stdc++.h>
using namespace std;
int main(){
	int n;
	cin>>n;
	string s;
	cin>>s;
	for(int i=0;i<s.size();i++){
		int d=(s[i]-'a'+n)%26;
		s[i]='a'+d;
	}
	cout<<s<<endl;
}
