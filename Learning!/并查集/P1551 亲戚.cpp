#include<bits/stdc++.h>
using namespace std;
int n,m,p;
int a[5001],rank[5001];
int root(int x){
	if(a[x]==x) return x;
	else{
		a[x]=root(a[x]);  //更新爸爸 
		return a[x];
	}
}
int main(){
	cin>>n>>m>>p;
	for(int i=1;i<=n;i++){
		a[i]=i;
		rank[i]=1;
	}
	for(int i=1;i<=m;i++){
		int mi,mj;
		cin>>mi>>mj;
		int e=root(mi),f=root(mj);
		if(rank[e]<=rank[f]){
			a[e]=f; //小树并大树 ,e小f大 
		}
		else{
			a[f]=e;
		}
		if(rank[e]==rank[f]&&e!=f)
			rank[f]++; 
//		a[root(mi)]=root(mj);
	}
	for(int i=1;i<=p;i++){
		int pi,pj;
		cin>>pi>>pj;
		if(root(pi)==root(pj)) cout<<"Yes"<<endl;
		else cout<<"No"<<endl;
	}
} 
