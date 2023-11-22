#include<bits/stdc++.h>
using namespace std;
int main(){
//	map<int, int> a; //Òª¼Ó¶ººÅ°¡°¡°¡°¡°¡°¡°¡ 
//	int n;
//	cin>>n;
//	for(int i=1;i<=n;i++){
//		int x;
//		cin>>x;
//		a.insert(pair<int,int>(i,x));
//	}
//	
//	int q;
//	cin>>q;
//	
//	
//	vector<int> s;
//	for(int i=1;i<=q;i++){
//		int m;
//		cin>>m;
//		map<int,int>::iterator it;
//		for(it=a.begin();it!=a.end();++it){
//			if(*it==m){
//				s.insert(it);
//				break;
//			}
//		}
//		if(a.find(m)==a.end()) s.insert(0);
//	}
//	for(vector<int>::iterator ti=s.begin();ti!=s.end();ti++){
//		cout<<*it<<endl;
//	}
	map<int,int> a;
	int n;
	cin>>n;
	for(int i=1;i<=n;i++){
		int m;
		cin>>m;
		a[m]=i;
	}
	int q;
	cin>>q;
	int b[q];
	for(int j=0;j<=q-1;j++){
		cin>>b[j];
	}
	for(int j=0;j<q;j++)
		cout<<a[b[j]]<<endl;
} 
