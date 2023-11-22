#include<bits/stdc++.h>
using namespace std;
int main(){
	long long n;
	cin>>n;
	if(n%2==1){
		if((n/2+1)%2) cout<<1<<endl;
		else cout<<0<<endl;
	}
	else{
		if(((n-1)/2+1)%2) cout<<(1^n)<<endl;
		else cout<<n<<endl;
	}
}
