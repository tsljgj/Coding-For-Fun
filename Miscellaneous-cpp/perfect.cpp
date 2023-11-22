#include<bits/stdc++.h>
#define mp make_pair
#define fi first
#define se second
using namespace std;
int a,b;
pair<int,int> f[10020];
void dfs(int x,int val,int cut){
	if(x>1000) return;
	if(x!=0&&val>=f[x]) return;
	
	f[x]=val;
	for(int i=0;i<=3;i++){            //0:(copy,6) 1:(paste,2) 2:(+1,1) 3:(-1,1)
		int x0=x, val0=val, cut0=cut;
		if(i==0&&x!=0) x0+=x, val0+=6;
		else if(i==1&&cut!=0) x0+=cut, val0+=2;
		else if(i==2) x0+=1, val0+=1;
		else if(i==3&&x0>1) x0-=1, val0+=1;
		else 
		dfs(x0,val0,cut0);
	}
}
int main(){
//	cin>>a>>b;

	for(int i=1;i<=1000;i++) f[i]=mp(10000,0);
	
	dfs(0,0,0);	
	
	for(int i=0;i<=1000;i++) cout<<i<<" "<<f[i]<<endl;
}
