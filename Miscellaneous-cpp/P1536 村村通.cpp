#include<bits/stdc++.h>
using namespace std;
int f[1200],v[1200];
int cnt=0;
int find(int x){
	if(f[x]==x) return x;
	return f[x]=find(f[x]);
}
void unit(int x,int y){
	int fax=find(x),fay=find(y);
	f[fax]=fay;
//	if(!v[fay]){
//		if(!v[fax]) v[fay]=++cnt;
//		else v[fay]=v[fax];
//	}
//	else if(v[fax]){
//		cnt--;
//	}
}
int main(){
	int n,m;
	while(cin>>n,n){
		cnt=0;
		cin>>m;
		memset(v,0,sizeof(v));
		for(int i=1;i<=n;i++){
			f[i]=i;
		}
		for(int i=1;i<=m;i++){
			int x,y;
			cin>>x>>y;
			unit(x,y);
		}
		
		for(int i=1;i<=n;i++){
			if(!v[find(i)]) v[find(i)]=++cnt;
		}
		cout<<(cnt==0?0:cnt-1)<<endl;
	}
	return 0;
	
}
