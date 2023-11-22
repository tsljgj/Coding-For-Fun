#include<bits/stdc++.h>
using namespace std;
int b[3000020];
stack<int> a;
int main(){
	int n;
	cin>>n;
	for(int i=1;i<=n;i++) cin>>b[i];
	
	for(int i=1;i<=n;i++){
		while(!a.empty()&&b[i]>a.top()){
			cout<<i<<endl;
			a.pop();
		}
		a.push(b[i]);
	}
	return 0;
}
