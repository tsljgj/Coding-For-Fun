#include<bits/stdc++.h>
using namespace std;
int main(){
	map<string,int> m;
	int n;
	cin>>n;
	for(int i=1;i<=n;i++){
		string s;
		int x,grade;
		map<string,int>::iterator it;
		cin>>x;
		if(x==1){
			cin>>s>>grade;

				cout<<"OK"<<endl;//×ĞÏ¸¿´Ìâ 
		
			m[s]=grade;
//				m[s]=grade;//m.insert(pair<string,int>(s,grade));	
//				cout<<"OK"<<endl;
//			}
//			else{
//				m[s]=grade;
//			}
		}
		if(x==2){
			cin>>s;
			it=m.find(s);
			if(it!=m.end())
				cout<<m[s]<<endl;
			else cout<<"Not found"<<endl;
		}
		if(x==3){
			cin>>s;
			it=m.find(s);
			if(it!=m.end()){
				m.erase(it);
				cout<<"Deleted successfully"<<endl;
			}
				
			else cout<<"Not found"<<endl;
		}
		if(x==4) {
			cout<<m.size()<<endl;
		}
	}
}
