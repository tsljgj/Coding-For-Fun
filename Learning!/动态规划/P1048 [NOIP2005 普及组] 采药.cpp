#include<bits/stdc++.h>
using namespace std;
int w[120],v[120];
int dp[1020];
int main(){
	int t,m;
	cin>>t>>m;
	for(int i=1;i<=m;i++){
		cin>>w[i]>>v[i];
	}
	
	memset(dp,0,sizeof(dp));
	
	for(int i=1;i<=m;i++){
		for(int j=t;j>=0;j--){
			if(j>=w[i]){
				cout<<"����ѡ"<<i<<"��dp["<<j-w[i]<<"]="<<dp[j-w[i]]<<" v["<<i<<"]="<<v[i]<<" dp[j]="<<dp[j]<<endl; 
				dp[j]=max(dp[j-w[i]]+v[i],dp[j]);
				cout<<"�ı��"<<dp[j]<<endl;

			}
			else{
				cout<<"��������������ѡ"<<i<<endl; 
			}
		}
		cout<<endl;
		for(int p=1;p<=t;p++){
			cout<<"dp["<<p<<"] ";
		}
		cout<<endl;
		for(int p=1;p<=t;p++){
			cout<<"  "<<dp[p]<<"   ";
		}
		cout<<endl;
		cout<<endl;
	}
	
//	cout<<dp[t]<<endl;
} 
