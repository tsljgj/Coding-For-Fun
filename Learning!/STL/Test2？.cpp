#include<bits/stdc++.h>
using namespace std;
int main(){
	map<int,int> mapTest;
	mapTest.insert(pair<int,int>(10,11));  //pair中数据类型要与map中保持一致 
	mapTest.insert(pair<int,int>(9,11));
	mapTest.insert(pair<int,int>(8,11));
	mapTest.insert(pair<int,int>(7,11));
	mapTest.insert(pair<int,int>(6,11));
	for(map<int,int>::iterator iter=mapTest.begin();iter!=mapTest.end();)  //!=改<也不行 
	{
		cout<<iter->first<<":"<<iter->second<<endl;
		mapTest.erase(iter++);
	}
	 
//	for(map<int,int>::iterator iter=mapTest.begin();iter!=mapTest.end();)
//	{
//		cout<<iter->first<<":"<<iter->second<<endl;
//		iter=mapTest.erase(iter);  //erase 返回的是后一个
//	}
//这玩意不行？ 
 
	for(map<int,int>::iterator iter=mapTest.begin();iter!=mapTest.end();iter++){
		cout<<iter->first<<iter->second<<endl;
	}
	
}
