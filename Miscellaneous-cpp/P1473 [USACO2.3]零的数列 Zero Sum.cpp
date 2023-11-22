#include<bits/stdc++.h>
using namespace std;
int n,a[20],b[20];
void dfs(int h){
	if(h==n+1){
//		for(int i=1;i<=n;i++) cout<<b[i];
//		cout<<endl;
		int sum=0,o=1;
		vector<int> c;
		c.push_back(1);
		
		for(int i=2;i<=n+1;i++){
			if(b[i]!=0){
				for(int j=0;j<c.size();j++){
					sum+=o*pow(10,c.size()-j-1)*c[j];
				}
				o=b[i];
				c.clear();
			}
			c.push_back(i);

		}
		
		if(sum==0) {
			cout<<a[1]; 
			for(int i=2;i<=n;i++){
				if(b[i]==1) cout<<"+";
				if(b[i]==0) cout<<" ";
				if(b[i]==-1) cout<<"-";
				cout<<a[i];
			}
			cout<<endl;
		}
		return;
	}
	
	for(int i=1;i>=-1;i--){
		if(i==1) b[h]=0;
		if(i==0) b[h]=1;
		if(i==-1) b[h]=-1;
		
		dfs(h+1);
	}
	return;
}
int main(){
	cin>>n;
	for(int i=1;i<=n;i++) a[i]=i;
	b[1]=1;
	b[n+1]=1;
	
	dfs(2);
	
} 
