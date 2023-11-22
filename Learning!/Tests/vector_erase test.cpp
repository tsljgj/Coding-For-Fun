//vector 可以边删元素边遍历 
#include<bits/stdc++.h>
using namespace std;
int main(){
//	vector<int> a;
//	for(int i=0;i<=5;i++){
//		a.push_back(i);
//	}
//	vector<int>::iterator it;
//	for(it=a.begin();it!=a.end();){
//		
//		for(int i=0;i<a.size();i++){
//			cout<<a[i]<<" ";
//		}
//		cout<<endl;
//		
////		vector<int>::iterator ti=it;
//
//		a.erase(it);
//		
////		it=ti;

		vector<pair<int,int> > a[100];
		for(int i=1;i<=2;i++){
			for(int j=3;j<=4;j++){
				a[i].push_back(make_pair(j,j+1));
			}
		}
		vector<pair<int,int> >::iterator ti;
		for(int i=1;i<=4;i++){
			for(ti=a[i].begin();ti!=a[i].end();ti++){
				cout<<ti->first<<" "<<ti->second<<endl;
			}
		}
		
		for(int i=1;i<=2;i++){
			vector<pair<int,int> >::iterator it;
			for(it=a[i].begin();it!=a[i].end();){
				a[it->first].push_back(make_pair(i,it->second));
				a[i].erase(it);
			}
		}
		
		for(int i=1;i<=4;i++){
			for(ti=a[i].begin();ti!=a[i].end();ti++){
				cout<<ti->first<<" "<<ti->second<<endl;
			}
		}
		
	
}
