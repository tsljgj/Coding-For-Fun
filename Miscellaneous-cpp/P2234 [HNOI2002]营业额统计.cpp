#include<bits/stdc++.h>
using namespace std;
set<int> m; 
int n; 
int ans;
int main(){
	cin>>n;
	m.insert(2000000);
	m.insert(-2000000);
	
	int x;
	cin>>x;
	m.insert(x);
	ans=x;
	
//	cout<<"从2开始:"<<endl;
	for(int i=2;i<=n;i++){
		
		cin>>x;
		
		set<int>::iterator it=m.lower_bound(x);   //lower大于等于 
//		set<int>::iterator ti=m.upper_bound(x);  //upper大于 
		set<int>::iterator ti=it;
		ti--;
		
//		cout<<*it<<" "<<*ti<<endl;
		
		ans+=min(abs(*it-x),abs(*ti-x));
		
		m.insert(x);
//		cout<<"m:"<<endl;
//		for(set<int>::iterator t=m.begin();t!=m.end();t++) cout<<*t<<" ";
//		cout<<endl;
		
	}
	
	cout<<ans<<endl;
	return 0;
} 
