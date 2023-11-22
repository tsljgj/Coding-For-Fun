#include<bits/stdc++.h>
using namespace std; 
const int INF=(1<<30);
int q;
stack<int> s1, s2;
int sum[1000000], f[1000000];
int main(){
	cin>>q;
	f[0]=-INF;
	while(q--){
		char ch;
		cin>>ch;
		if(ch=='I'){
			int x; cin>>x;
			s1.push(x);
			sum[s1.size()]=sum[s1.size()-1]+x;
			f[s1.size()]=max(f[s1.size()-1],sum[s1.size()]);
		}
		else if(ch=='D'){
			if(!s1.empty()){
				s1.pop();
			}
		}
		else if(ch=='L'){
			if(!s1.empty()){
				s2.push(s1.top());
				s1.pop();
			}
		}
		else if(ch=='R'){
			if(!s2.empty()){
				s1.push(s2.top());
				s2.pop();
				int pos=s1.size();
				sum[pos]=sum[pos-1]+s1.top();
				f[pos]=max(f[pos-1],sum[pos]);
			}
		}
		else if(ch=='Q'){
			int k;
			cin>>k;
			cout<<f[k]<<endl;
		}
	}
} 
