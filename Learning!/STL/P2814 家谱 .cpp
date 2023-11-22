#include<bits/stdc++.h>
using namespace std;
map<string,string> m;
//string a[10000],b[10000];
//int k=0;
int main(){
	char ch;
	cin>>ch;
	string s,s1;
	while(ch!='$'){
		cin>>s;
		if(ch=='#'){
//			if(m[s]=="")//m.find(s)==m.end()   //m[s]访问不存在的位置会新建 
//				m[s]="0";//m.insert(pair<string,string>(s,"0"))(为啥这和m[s]搭配就挂了？因为m[s]已存在） 
			s1=s; 
		}
		if(ch=='+'){
			m.insert(pair<string,string>(s,s1));
		}
		if(ch=='?'){
			string s2=s;
			while(m.find(s2)!=m.end()) { //m[s2]!="0"
				s2=m[s2];
			}
//			map<string,string>::iterator it=m.find(s);
//			map<string,string>::iterator ti; 
//			while(m.find(it->second)!=m.end()){
//				
//				ti=m.find(it->second);
//				it=ti;
//				
//			}
//			a[k]=s;
//			b[k]=it->first;
//			b[k]=s2;
//			k++;
			cout<<s<<" "<<s2<<endl;
		}
		cin>>ch;
	}
		
//	for(int i=0;i<k;i++){
//		cout<<a[i]<<" "<<b[i]<<endl;
//	}

} 
