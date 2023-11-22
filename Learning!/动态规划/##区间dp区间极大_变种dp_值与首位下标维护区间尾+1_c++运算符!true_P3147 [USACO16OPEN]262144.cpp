#include<bits/stdc++.h> 
using namespace std;
int dp[60][263000];   //数组别写反   i=能合出的数字，j=左端点 
int a[263000];
int n; 
int ans=0;
int main(){
	cin>>n;
	for(int i=1;i<=n;i++){
//		int in;
//		cin>>in;
		cin>>a[i];
	    dp[a[i]][i]=i+1;
	    
		  //+1?
		 //1 1 1 2 对于dp[3][3]而言，找不到从3起点合值为2的右端点(即dp[2][3]=0),返回的dp[i-1][j]=0
		//此时计算机还会去找dp[i-1][dp[i-1][j]+1],结果就还真找到了,所以错了
	   //总结下来就是不 +1 而去把 1 加在 dp[i-1][j]+1 会让计算机不管 第一个右端点 是否找到而用 0+1 去寻找最终右端点
	  //而+1后就可以巧妙地避开这个问题
	 //因为将右端点右移一位只是形式改变,内涵不变,为: 合成i,起点为j的终点的右边一位为dp[i][j]
	//但计算机在考虑dp[i-1][j]=0时,dp[i-1][dp[i-1][j]]一定为0了，所以更新后的dp[i][j]=0,没有任何问题
   //当然也可以用原来的方法,不过当dp[i-1][j]=0时要直接将dp[i][j]赋值为0,不要继续算了 
	  
//		cout<<"a[i]="<<a[i]<<" i="<<i<<" dp["<<a[i]<<"]["<<i<<"]="<<dp[a[i]][i]<<endl;

	}
	
	for(int i=1;i<=58;i++){         
		for(int j=1;j<=n;j++){
			
//			cout<<"i="<<i<<" j="<<j<<endl;
//			cout<<"dp[i][j]="<<dp[i][j]<<" so";

			if(!dp[i][j])  {      //防止一开始所有 附的值 变为0 ,非0即false 
			
//				cout<<"执行"<<endl;

//				if(dp[i-1][j]!=0) 
					dp[i][j]=dp[i-1][dp[i-1][j]/*+1*/]; 
//				else dp[i][j]=0;

			}                
			 //先找到以j为左端点，合成为i-1的右端点，再以这个右端点(dp[i-1][j])找为起点找到合成i-1的右端点，这个端点即是从j点起合成i的端点
			
			
//			else cout<<"不执行"<<endl;
			
//			cout<<"dp[i-1][j]="<<dp[i-1][j]<<" dp[i-1][dp[i-1][j]]="<<dp[i-1][dp[i-1][j]]<<endl;
//			cout<<"dp[i][j]="<<dp[i][j]<<endl;
				
			
			if(dp[i][j])
				ans=i;   //ans=max(ans,i) 由于i是单调递增的，所以不用max 
				
//			cout<<endl;
//			cout<<dp[i][j]<<"("<<ans<<") ";
		}
		
	}
	
	cout<<ans<<endl;
	return 0;
}
