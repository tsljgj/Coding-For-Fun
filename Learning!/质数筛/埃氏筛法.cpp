#include<bits/stdc++.h>
using namespace std;
int n;
bool b[100000];
int main(){
	cin>>n;
	for(int i=2;i<=n;i++) b[i]=1;
	for(int i=2;i<=n;i++){
		
		if(b[i]){
			for(int j=i;j*i<=n;j++){  //j=i是因为: i之前的数(a),无论质数or合数,已经被化为质数在之前的枚举中算过了 
				b[j*i]=0;             //比如(5): 5*4 在2*10时算过, 5*3 在3*5时算过 
			}
		}
		
	}
	
	for(int i=2;i<=n;i++){
		if(b[i]) cout<<i<<endl;
	}
}
