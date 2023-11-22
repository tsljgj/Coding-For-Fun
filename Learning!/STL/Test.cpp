#include<bits/stdc++.h>
using namespace std;
int main(){
	map<string,string> m;
//	m.insert(pair<string,string>("kkk","2"));
	m.insert(pair<string,string>("1","2"));
	m.insert(pair<string,string>("2","8"));
	map<string,string>::iterator it=m.begin();
	map<string,string>::iterator ti;
	ti=m.find(it->second); //map会排序
	cout<<ti->second<<endl;
//	for (map<string,string>::iterator it=m.begin();it!=m.end();it++)
//	{
//		cout <<it->first << ' ' <<it->second << endl;
//	 } 
//	ti=m.insert(pair<string,string>("kkk","2")).first;  //insert返回1.迭代器2.bool(是否插入成功) ,.first rep. an iterator
////	cout<<m.insert(pair<string,string>("kkk","2")).second/*.second返回0/1(succeed or not)*/<<" "<<ti->first;
//	if(m.insert(pair<string,string>("kkk1","2")).second==1) cout<<m["kkk1"];  //if语句里面用insert也执行插入了 

//	ti=m.find(it->second); //find 找的是iterator,不是内容  //it->second 数据类型是啥？ 就是定义的类型 
//	cout<<ti->second<<endl;//it->first/it->second 皆可输出 
//	cout<<ti->second;
//	cout<<it->first<<it->second<<endl;
//	it++; //it=++m.begin()/+1 都不行 
//	cout<<it->first<<it->second<<endl;

	return 0;
}
