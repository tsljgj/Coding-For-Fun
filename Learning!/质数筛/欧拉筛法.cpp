#include<bits/stdc++.h> //埃氏筛是枚举质数用比它大的数相乘,欧拉筛是枚举合数用已知的质数相乘 
using namespace std;   //欧拉筛的精髓在于若枚举到的合数是某已知质数的倍数(即它的最小质因数),那么就停止继续已知的质数相乘 
int n,t=0;            //why correct? 如果一个枚举到的合数的最小质因子已知,那么该合数=p*a(p为最小质因子)一定会在合数枚举到a时与p相乘得到，故不需要再运算 
int prime[10000];    //同理,最小质因子之后的质因子也不需要运算了,所以直接break 
int num[10000]; 
int main(){
	cin>>n;
	for(int i=2;i<=n;i++) num[i]=1;
	for(int i=2;i<=n;i++){
		if(num[i]) {
			prime[++t]=i;      //加完回传值  t++:回传后加 	
		}
		
		for(int j=1;j<=t&&i*prime[j]<=n;j++){
			num[i*prime[j]]=0;
			if(i%prime[j]==0) break;      //见程序开头 
		}
		
	}
	
	for(int i=2;i<=n;i++) {
		if(num[i]) cout<<i<<endl;
	}
		
}
