//priority queue
#include<bits/stdc++.h>
using namespace std;
int main(){
	priority_queue<int,vector<int>,greater<int> > a;   //greater 小顶堆 ,大顶堆top最大，反之亦然 
	a.push(1);
	a.push(2);
	a.push(3);
	a.push(0);
	cout<<a.top();
	
	

//	priority_queue<string,vector<string>,less<string> > a;   //string 比的是ascall码 ,字典序 
//	a.push("abc");
//	a.push("bbc");
//	a.push("bba");
//	cout<<a.top();
	
} 
