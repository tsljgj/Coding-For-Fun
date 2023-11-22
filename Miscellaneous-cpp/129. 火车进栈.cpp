#include<bits/stdc++.h>
using namespace std;
int n;
int a[100],b[100];
stack<int> s;
int cnt=0;
int ans=20;
void dfs(int x){
	if(cnt==n) {
		ans--;
		for(int i=1;i<=n;i++) cout<<a[i];
		if(ans==0) {
			exit(0);
		}
		cout<<endl;
		return;
	}
	if(!s.empty()){
		a[++cnt]=s.top();
		s.pop();
		dfs(x);
		s.push(a[cnt]);
		cnt--;
	}
	if(x<=n){
		s.push(x);
    	dfs(x+1);
    	s.pop();
	}
    
}
int main(){
    cin>>n;
    dfs(1);
}
