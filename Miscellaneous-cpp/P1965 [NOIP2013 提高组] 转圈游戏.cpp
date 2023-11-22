#include<bits/stdc++.h>
using namespace std;
int main()
{
	int n,m,k,x;
	cin>>n>>m>>k>>x;
	long long base=10,ans=1;
	while(k!=0){
		if(k%2!=0) ans=ans*base%n;
		base=base*base%n;
		k>>=1;
	}
	ans=ans*m%n;
	cout<<(ans+x)%n<<endl;
	
}
