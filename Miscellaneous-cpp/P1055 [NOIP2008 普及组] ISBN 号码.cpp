#include<bits/stdc++.h>
using namespace std;
int main(){
	string s;
	cin>>s;
	int cnt=0;
	int sum=0;
	for(int i=0;i<s.size()-1;i++){
		if(s[i]<='9'&&s[i]>='0'){
			sum+=(s[i]-'0')*(++cnt);
		}
	}
	if(sum%11==10&&s[s.size()-1]=='X') cout<<"Right"<<endl;
	else{
		if(sum%11==s[s.size()-1]-'0') cout<<"Right"<<endl;
		else{
			for(int i=0;i<s.size()-1;i++) cout<<s[i];
//			cout<<(sum%11==10? "X": sum%11); 
			if(sum%11==10) cout<<"X";
			else cout<<sum%11<<endl;
		}
	}
}
