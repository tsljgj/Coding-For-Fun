#include<bits/stdc++.h>
using namespace std;
int dp[300][300];
int n;
int a[300];
int ans=0;
int main(){
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		dp[i][i]=a[i];
	}
	
	for(int l=1;l<n;l++){   //����dp����ö��i֮��֮��l 
		for(int i=1;i+l<=n;i++){
			int j=i+l;
			
			for(int k=i;k<j;k++){
//				cout<<dp[i][k]<<" "<<dp[k+1][j]<<endl;
//				dp[i][j]=max(dp[i][j],max(dp[i][k],dp[k+1][j]));
				if(dp[i][k]==dp[k+1][j]&&dp[i][k]!=0&&dp[k+1][j]!=0){  //dp�ǵ�����ʼ�����ֹ��,��ö�ٲ�ö����ֹ��,ö�ٳ��� 
					dp[i][j]=max(dp[i][k]+1,dp[i][j]);
					ans=max(ans,dp[i][j]);
					
				}
					
				
			}
			
//			cout<<i<<"->"<<j<<"������dp:"<<endl;
//			for(int p=i;p<=j;p++){
//				cout<<dp[i][p]<<" ";
//			}
//			cout<<endl;
		}
	}
	
//	cout<<dp[1][n]<<endl;
	cout<<ans<<endl;
}
