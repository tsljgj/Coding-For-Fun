#include<bits/stdc++.h>
using namespace std;
deque<int> s,ss;
int main(){
	int n,m;
	cin>>n>>m;
	cout<<0<<endl;
	for(int i=1;i<n;i++){
		int x;
		cin>>x;
		while(!s.empty()&&x<s.back()){             //×¢ÒâbackºÍfront 
			s.pop_back();
			ss.pop_back();
		}
		while(!s.empty()&&ss.front()<=i-m){
			s.pop_front();
			ss.pop_front();
		}
		
		s.push_back(x);
		ss.push_back(i);
//		deque<int>::iterator it;
//		for(it=s.begin();it!=s.end();it++) cout<<*it<<" ";
//		cout<<endl;
		
		cout<<s.front()<<endl;
		
	}

	
}
