#include<bits/stdc++.h>
using namespace std;
string s;
stack<char> st,pos;
string b;
int main(){
	cin>>s;
	int l=s.size();
	for(int i=0;i<l;i++){
		if(s[i]=='('||s[i]=='[') {
			st.push(s[i]);
			pos.push(i);
			b[i]=(s[i]=='(' ? ')' : ']');
		}
		else{
			if(!st.empty()&&((s[i]==')'&&st.top()=='(')||(s[i]==']'&&st.top()=='['))){
				b[pos.top()]=' ';
				b[i]=' ';
				st.pop();
				pos.pop();
			}
		}
	} 
	
	for(int i=0;i<l;i++){
		if(s[i]=='('||s[i]=='[') {
			cout<<s[i];
			if(b[i]!=' ') cout<<b[i];
		}
		else{
			if(b[i]==' '){
				cout<<s[i];
			}
			else{
				cout<<(s[i]==')' ? '(' : '[')<<s[i];
			}
		}
	}
	return 0;
}
