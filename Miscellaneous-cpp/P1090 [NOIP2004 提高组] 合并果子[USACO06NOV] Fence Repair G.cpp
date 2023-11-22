#include<bits/stdc++.h>
using namespace std;
priority_queue<int,vector<int>,greater<int> > a; //greater从小到大 
int main(){
	int n;
	cin>>n;
	for(int i=1;i<=n;i++){
		int x;
		cin>>x;
		a.push(x);
		
	}
	
	int ans=0;
	
	while(a.size()>1){
		int x=a.top();
		a.pop();
		int y=a.top();
		a.pop();
		ans+=x+y;
		a.push(x+y);
	}
	
	cout<<ans<<endl;
}
