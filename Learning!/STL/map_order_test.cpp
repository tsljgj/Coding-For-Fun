#include<bits/stdc++.h>
using namespace std;
int main(){
	map<int,int> s;
	s[1]=2;
	s[3]=3;
	s[2]=4;
	for(map<int,int>::iterator ti=s.begin();ti!=s.end();ti++) cout<<"("<<ti->first<<","<<ti->second<<") ";
	//map�������first���λ�� 
	
	multimap<int,int> g;     //multimap������g[1]=2
	g.insert(pair<int,int>(1,2));
	g.insert(pair<int,int>(1,1));  //multimap�Ƚ�ʱҲֻ�Ƚϵ�һ�����������һ������ȵڶ�����Ҳ���� 
	for(map<int,int>::iterator ti=g.begin();ti!=g.end();ti++) cout<<"("<<ti->first<<","<<ti->second<<") ";

}
