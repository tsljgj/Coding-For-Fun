//priority queue
#include<bits/stdc++.h>
using namespace std;
int main(){
	priority_queue<int,vector<int>,greater<int> > a;   //greater С���� ,�󶥶�top��󣬷�֮��Ȼ 
	a.push(1);
	a.push(2);
	a.push(3);
	a.push(0);
	cout<<a.top();
	
	

//	priority_queue<string,vector<string>,less<string> > a;   //string �ȵ���ascall�� ,�ֵ��� 
//	a.push("abc");
//	a.push("bbc");
//	a.push("bba");
//	cout<<a.top();
	
} 
