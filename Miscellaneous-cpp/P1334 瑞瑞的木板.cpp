#include<bits/stdc++.h>
using namespace std;
long long ans=0;
int main(){
	int n;
	cin>>n;
	priority_queue<int> q;
	for(int i=1;i<=n;i++){
		int x;
		cin>>x; q.push(-x);
	}
	for(int i=1;i<n;i++){
		int sum=0;
		sum-=q.top();
		q.pop();
		sum-=q.top();
		q.pop();
		q.push(-sum);
		ans+=sum;
	}
	cout<<ans<<endl;
}
