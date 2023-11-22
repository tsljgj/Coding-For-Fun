#include<bits/stdc++.h>
using namespace std;
int main()
{
	int n;
	cin>>n;
	priority_queue<int> a;
	for(int i=1;i<=n;i++){
		int x;
		cin>>x;
		a.push(x);
		
	}
	
	for(int i=1;i<=n;i++){
		cout<<a.top()<<" ";
		a.pop();
	}
	
}
