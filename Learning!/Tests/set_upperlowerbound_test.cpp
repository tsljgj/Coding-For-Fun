#include<bits/stdc++.h>
using namespace std;
int main(){
	multiset<int> a;
	a.insert(1);
	a.insert(2);	
	a.insert(4);
	a.insert(4);
	a.insert(4);
	a.insert(6);
	a.insert(6);
	cout<<*(++a.lower_bound(4))<<endl;          //���ص�һ�� >= key_value ��Ԫ�أ���û��Ԫ���򷵻�0 
	if(a.upper_bound(5)==a.end()) cout<<"0"<<endl;
	cout<<*(a.upper_bound(90));                //���ص�һ�� > key_value ��Ԫ�� 
}
