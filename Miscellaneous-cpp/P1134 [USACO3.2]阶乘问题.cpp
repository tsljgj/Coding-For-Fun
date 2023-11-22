#include<bits/stdc++.h>
using namespace std;
int main(){
	int n;
	cin>>n;
	int num2=0,num5=0;
	int ans=1;
	for(int i=1;i<=n;i++){
		int ii=i;
		while(ii%2==0){
			num2++;
			ii/=2;
		}
		
		while(ii%5==0){
			num5++;
			ii/=5;
		}
		
		ans=ans*ii%10;
		
//		while(ans%10==0) ans/=10;  
//		ans%=100000000;
	}
	
	num2-=num5;
	int b[4]={6,2,4,8};  //±ØĞëÊÇ6,2^4=6  2^1=2  2^2=4  2^3=8 
	ans=ans*b[num2%4]%10;     //1
	
//	for(int i=1;i<=num2-num5;i++){ //2
//		ans=(ans*2)%10;
//	}
	cout<<ans<<endl;
}

//#include<cstdio>
//using namespace std;
//int a[10]={6,6,2,6,4,4,4,8,4,6},b[4]={6,8,4,2};
//int main()
//{
//	int ans=1,n;
//	scanf("%d",&n);
//	if (n==1)
//	{
//		printf("1");
//		return 0;
//	}
//	while(n)
//	{
//		ans*=a[n%10];
//		n=n/5;
//		ans=ans*b[n%4]%10;
//	}
//	printf("%d",ans);
//	return 0;
//}
