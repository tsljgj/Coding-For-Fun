#include<bits/stdc++.h>
using namespace std;
int n;
int col[20], d[40], dd[40];
int a[20];
int cnt=0;
void dfs(int x){
	if(x==n+1){
		cnt++;
		if(cnt<=3){
			for(int i=1;i<=n;i++) cout<<a[i]<<" ";
			cout<<endl;
		}
		
		return;
	}
	for(int j=1;j<=n;j++){
		if(!col[j]&&!d[x-j+20]&&!dd[x+j]){
			a[x]=j;
			col[j]=1;
			d[x-j+20]=1;
			dd[x+j]=1;
			dfs(x+1);
			col[j]=0;
			d[x-j+20]=0;
			dd[x+j]=0;
		}
	}
	
}
int main(){
	cin>>n;
	dfs(1);
	cout<<cnt<<endl;
}
