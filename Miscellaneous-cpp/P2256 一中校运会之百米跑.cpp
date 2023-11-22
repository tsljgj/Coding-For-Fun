#include<bits/stdc++.h>
using namespace std;
int n,M;
int f[20020];
int find(int x){
	if(f[x]==x) return x;
	else return f[x]=find(f[x]);
}
map<string,int> m;
void U(int x,int y){
	int xx=find(x);
	int yy=find(y);
	f[xx]=yy;
}
int main(){
	cin>>n>>M;
	for(int i=1;i<=n;i++) f[i]=i;
	for(int i=1;i<=n;i++){
		string s;
		cin>>s;
		m[s]=i;
	}
	
	for(int i=1;i<=M;i++){
		string s,ss;
		cin>>s>>ss;
		U(m[s],m[ss]);
	}
	
	int k;
	cin>>k;
	for(int i=1;i<=k;i++){
		string s,ss;
		cin>>s>>ss;
		if(find(m[s])==find(m[ss])) cout<<"Yes."<<endl;
		else cout<<"No."<<endl;
	}
}
