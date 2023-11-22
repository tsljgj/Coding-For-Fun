#include<bits/stdc++.h>
using namespace std;
int main(){
	set<int> s;
	int n,sum=0;
	cin>>n;
	for(int i=1;i<=n;i++){
		int x;
		cin>>x;
		s.insert(x);
	}
	set<int>::iterator it;
	set<int>::iterator ti=s.begin();
	int i=3;
	it=s.begin();
	it++++;
	for(;it!=s.end();it++,i++){
//		cout<<*it<<endl;  //*it是值（内容），it是指针不能输出 
		int j=1;
		ti=s.begin();
		while(j<i){
			if(/*s.count(*it-*ti)!=0*/ s.find(*it-*ti)!=s.end()&&s.find(*it-*ti)!=it) {
				sum++;
				break;
			}
			j++;
			ti++;
		}

	}
	cout<<sum<<endl;
	return 0;
} 
