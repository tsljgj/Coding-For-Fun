#include<bits/stdc++.h>
using namespace std;
set<int> a;
int main(){
	for(int i=10;i>=1;i--){
		a.insert(i);
	}
	for(set<int>::iterator it=a.begin();it!=a.end();){
		cout<<*it<<endl;
		set<int>::iterator ti=it;
		it++;
		a.erase(ti);
	}
}
