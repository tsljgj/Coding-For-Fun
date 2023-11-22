#include<bits/stdc++.h>
#define fi first
#define se second
#define mp make_pair
using namespace std;
int T;
pair<int,int> f[30020];
pair<int,int> find(int x){
	if(f[x].fi==x) return f[x];
	pair<int,int> xx=find(f[x].fi);
	return mp(xx.fi,xx.se+1);
}

void U(int x,int y){
	pair<int,int> xx=find(x);
	pair<int,int> yy=find(y);
	f[xx.fi].fi=yy.fi;
}

int main(){
	cin>>T;
	
	for(int i=1;i<=30000;i++) f[i]=mp(i,0);
	
	while(T--){
		string op;
		int i,j;
		cin>>op>>i>>j;
		if(op=="M"){
			U(i,j);
		}else{
			pair<int,int> x=find(i), y=find(j);
			if(x.fi==y.fi){
				cout<<abs(x.se-y.se)-1<<endl;
			}else{
				cout<<-1<<endl;
			}
		}
	}
}
