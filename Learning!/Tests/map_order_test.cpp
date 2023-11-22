#include<bits/stdc++.h>
using namespace std;
int main(){
	map<int,int> s;
	s[1]=2;
	s[3]=3;
	s[2]=4;
	for(map<int,int>::iterator ti=s.begin();ti!=s.end();ti++) cout<<"("<<ti->first<<","<<ti->second<<") ";
	//map排序的是first这个位置 
	
	multimap<int,int> g;     //multimap不让用g[1]=2
	g.insert(pair<int,int>(1,2));
	g.insert(pair<int,int>(1,1));  //multimap比较时也只比较第一个数，就算第一个数相等第二个数也不比 
	for(map<int,int>::iterator ti=g.begin();ti!=g.end();ti++) cout<<"("<<ti->first<<","<<ti->second<<") ";

}
