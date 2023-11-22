#include<bits/stdc++.h>
using namespace std;
int a,b;
int prime[100020];
void prepare(int y){
	for(int i=2;i<=y;i++){
		if(!prime[i])
			for(int j=i;i*j<=y;j++){
				prime[i*j]=1;   //·ÇÖÊÊý 
			}
	}
}
int main(){
	cin>>a>>b;
	memset(prime,0,sizeof(prime));
	prepare(b);
	
	for(int i=0;i<=9;i++){
		for(int j=0;j<=9;j++){
			for(int k=0;k<=9;k++){
				for(int m=0;m<=9;m++){
					for(int p=0;p<=9;p++){
						long long num=100000000*i+10000000*j+1000000*k+100000*m+10000*p+1000*m+100*k+10*j+i;
						while(num%10==0) num=num/10; 
						prime[num]--;
					}
				}
			}
		}
	}
	
	for(int i=a;i<=b;i++){
		if(prime[i]==-1) cout<<i<<endl;
	}
}
