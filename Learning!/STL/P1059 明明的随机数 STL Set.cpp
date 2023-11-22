#include<bits/stdc++.h>
using namespace std;

int main(){
	int n;
	set<int> a;
	set<int>::iterator it;
//	set<int>::iterator ti;
	cin>>n;
//	for(int i=1;i<=n;i++){
//		a.insert(rand()%1000+1);
//	}
	for(int i=1;i<=n;i++){
		int x;
		cin>>x;
		a.insert(x); //能直接用cin的相关函数来操作吗？ 
	}
	cout<<a.size()<<endl;
	for(it=a.begin();it!=a.end();++it){
		cout<<*it<<" ";
	}
} 
