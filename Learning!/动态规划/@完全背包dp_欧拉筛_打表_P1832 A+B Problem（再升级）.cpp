#include<bits/stdc++.h>
using namespace std;
int n;

//ŷ��ɸ���� 
int t; 
bool num[10000];
int prime[10000];

//dp����
vector<int> a; 
long long dp[1030];
int main(){
//	cin>>n;
	
//	if(n==1) {
//		cout<<0<<endl;
//		return 0;
//	}
	
	//ŷ��ɸ 
	memset(num,true,sizeof(num));       //ŷ��ɸ��true��false 
	for(int i=2;i<=1000;i++){
		if(num[i]){
			prime[++t]=i;
		}
		for(int j=1;j<=t&&i*prime[j]<=1000;j++){
			num[i*prime[j]]=false;
			if(i%prime[j]==0) break;
		}
	}
	
	//dp
	a.push_back(0);
	for(int i=2;i<=1000;i++)
		if(num[i]) a.push_back(i);
//		cout<<a.size()<<endl;
//	for(int i=0;i<a.size();i++) cout<<a[i]<<" ";
//	cout<<endl;
//	for(int i=0;i<a.size();i++)
//		dp[1][a[i]]=1;
//for(int k=2;k<=1000;k++){
	
	dp[0]=1;
	for(int i=1;i<a.size();i++){
		for(int j=a[i];j<=1000;j++){
//			if(j>=a[i])                  //�ɲ�Ҫ���Ƶ�ѭ���� 
				dp[j]+=dp[j-a[i]];
			
//				dp[i][j]+=dp[i-1][j-num[i]]+dp[i-1][j];
				
//			for(int p=1;p<=n;p++){
//					cout<<dp[p]<<" ";
//			}
//			cout<<endl;
//			cout<<endl;
				
		}
	}
//	for(int i=2;i<=1000;i++)
//		cout<<dp[i]<<endl;
	cin>>n;
	cout<<dp[n]<<endl;
	return 0;
}
	
	
	
	
	


