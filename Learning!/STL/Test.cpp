#include<bits/stdc++.h>
using namespace std;
int main(){
	map<string,string> m;
//	m.insert(pair<string,string>("kkk","2"));
	m.insert(pair<string,string>("1","2"));
	m.insert(pair<string,string>("2","8"));
	map<string,string>::iterator it=m.begin();
	map<string,string>::iterator ti;
	ti=m.find(it->second); //map������
	cout<<ti->second<<endl;
//	for (map<string,string>::iterator it=m.begin();it!=m.end();it++)
//	{
//		cout <<it->first << ' ' <<it->second << endl;
//	 } 
//	ti=m.insert(pair<string,string>("kkk","2")).first;  //insert����1.������2.bool(�Ƿ����ɹ�) ,.first rep. an iterator
////	cout<<m.insert(pair<string,string>("kkk","2")).second/*.second����0/1(succeed or not)*/<<" "<<ti->first;
//	if(m.insert(pair<string,string>("kkk1","2")).second==1) cout<<m["kkk1"];  //if���������insertҲִ�в����� 

//	ti=m.find(it->second); //find �ҵ���iterator,��������  //it->second ����������ɶ�� ���Ƕ�������� 
//	cout<<ti->second<<endl;//it->first/it->second �Կ���� 
//	cout<<ti->second;
//	cout<<it->first<<it->second<<endl;
//	it++; //it=++m.begin()/+1 ������ 
//	cout<<it->first<<it->second<<endl;

	return 0;
}
