#include<bits/stdc++.h>
using namespace std;
int main(){
	map<int,int> mapTest;
	mapTest.insert(pair<int,int>(10,11));  //pair����������Ҫ��map�б���һ�� 
	mapTest.insert(pair<int,int>(9,11));
	mapTest.insert(pair<int,int>(8,11));
	mapTest.insert(pair<int,int>(7,11));
	mapTest.insert(pair<int,int>(6,11));
	for(map<int,int>::iterator iter=mapTest.begin();iter!=mapTest.end();)  //!=��<Ҳ���� 
	{
		cout<<iter->first<<":"<<iter->second<<endl;
		mapTest.erase(iter++);
	}
	 
//	for(map<int,int>::iterator iter=mapTest.begin();iter!=mapTest.end();)
//	{
//		cout<<iter->first<<":"<<iter->second<<endl;
//		iter=mapTest.erase(iter);  //erase ���ص��Ǻ�һ��
//	}
//�����ⲻ�У� 
 
	for(map<int,int>::iterator iter=mapTest.begin();iter!=mapTest.end();iter++){
		cout<<iter->first<<iter->second<<endl;
	}
	
}
