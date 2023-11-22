#include<bits/stdc++.h>
using namespace std;
map<int,int> q;
int c;
int main(){
	
	cin>>c;
	while(c!=-1){
		if(c==1){
			int W,C;
			cin>>W>>C;
			if(q.find(C)==q.end()) {
//				cout<<"not found"<<endl;
//				cout<<q.find(C)->first<<endl;
				q.insert(pair<int,int>(C,W));
//				q[C]=W;
			}
		}
		else if(q.size()>0){
			if(c==2) q.erase(--q.end());
			if(c==3) q.erase(q.begin());
		}
		
//		for(map<int,int>::iterator ti=q.begin();ti!=q.end();ti++) cout<<"("<<ti->first<<","<<ti->second<<") ";
//		cout<<endl;
		cin>>c;
	}
	
	long long pr=0,fv=0;
	map<int,int>::iterator it;
	
	for(it=q.begin();it!=q.end();it++){
		pr+=(it->first);
		fv+=(it->second);
	}
	
	cout<<fv<<" "<<pr<<endl;
	
	return 0;
} 
