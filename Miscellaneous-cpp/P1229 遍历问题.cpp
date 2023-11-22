#include<bits/stdc++.h>
using namespace std;
int main(){
	string s,ss;
	int cnt=0;
	cin>>s>>ss;
	for(int i=0;i<s.size();i++)
		for(int j=0;j<ss.size();j++){
			if(s[i]==ss[j-1]&&s[i-1]==ss[j]) cnt++;
		}
	cout<<(1<<cnt)<<endl;
	return 0;
} 
