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
	cout<<*(++a.lower_bound(4))<<endl;          //若回第一个 >= key_value 的元素，若没有元素则返回0 
	if(a.upper_bound(5)==a.end()) cout<<"0"<<endl;
	cout<<*(a.upper_bound(90));                //返回第一个 > key_value 的元素 
}
