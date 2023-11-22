#include<bits/stdc++.h>
using namespace std;
char add(string a,string b){
	string s;
	if(a[a.size()-1]+b[a.size()-1]-'0'>9){
		s[a.size()]='0';
//		string t='1';
	}
	else{
		s[a.size()]=a[a.size()-1]+b[a.size()-1]-'0';
	}
	return s[a.size()];
}
int main(){
	string s1,s2;
	cin>>s1>>s2;
	cout<<add(s1,s2)<<endl;
}
