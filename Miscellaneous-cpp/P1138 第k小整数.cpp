#include<bits/stdc++.h>
using namespace std;
int n,k;
set<int> s;
int main(){
	cin>>n>>k;
	for(int i=1;i<=n;i++) {
		int x;
		cin>>x;
		s.insert(x);
	}
	
	set<int>::iterator it;
	int cnt=0;
	for(it=s.begin();it!=s.end();it++){
		cnt++;
		if(cnt==k) {
			cout<<*it<<endl;
			return 0;
		}
		
	}
	cout<<"NO RESULT"<<endl;
	
}
