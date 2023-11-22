#include<bits/stdc++.h>
using namespace std;
int main(){
	map<int,int> m;
	m.insert(pair<int,int>(1,2));
	m.insert(pair<int,int>(2,3));
	m.insert(pair<int,int>(5,2));
	m.insert(pair<int,int>(6,3));
	map<int,int>::iterator it;
//	m.erase(1);
	for(it=m.begin();it!=m.end();)
	{
		cout<<it->first<<endl;
		map<int,int>::iterator ti;
		ti=it;
		it++;
		m.erase(ti);
	}
	
	
}

