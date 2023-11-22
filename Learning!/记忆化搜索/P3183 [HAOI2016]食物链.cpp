#include<bits/stdc++.h>
using namespace std;
int c[100020];
int /*b1[100020],*/b2[100020];
bool b[100020];
int v[100020];
vector<int> a[100020];
int n,m,be,en;
int f(int i){
	if(b[i]){
		return v[i];
	}
	b[i]=1;
	v[i]=a[i].size();
	
	
	
}
int main(){
	cin>>n>>m;
	for(int i=1;i<=m;i++){
		int x,y;
		cin>>x>>y;
		a[x].push_back(y);
//		b1[x]++;   //出度 
		b2[y]++;   //入度 
	}
	
	for(int i=1;i<=n;i++) {
//		if(b1[i]==0&&b2[i]!=0) en=i;
//		if(b2[i]==0&&b1[i]!=0) be=i;
		if(b2[i]==0&&a[i].size()>0){
			ans+=f(i);
		}	
	}
		
//	cout<<be<<" "<<en<<endl;
	
}
