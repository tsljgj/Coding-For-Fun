#include<bits/stdc++.h>//∫Ÿ∫Ÿ∫Ÿ vscode ≤‚ ‘ 
using namespace std;
bool prime(int x){
	for(int i=2;i<=sqrt(x);i++){
		if(x%i==0&&x!=i){
			return 0;
		}
	}
	return 1;
}
int main(){
	int n,m,ans=0;
	cin>>n>>m;
	int a[n],b[n];
	memset(b,0,sizeof(b));
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	
	for(int i=n-1;i>n-m-1;i--){
		b[i]=1;
	}
	
	do{
		int sum=0;
		for(int i=0;i<n;i++){
			if(b[i]==1) sum+=a[i];
		}
		if(prime(sum)) ans++;
				
	}while(next_permutation(b,b+n));
	
	cout<<ans<<endl;
}
