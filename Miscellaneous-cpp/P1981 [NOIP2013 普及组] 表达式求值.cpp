#include<bits/stdc++.h>
using namespace std;
const int p=10000;
int x;
char c;
int s,t;
int main(){
	cin>>x;
	do{
		if(c=='*'){
			t=t%p*x%p;
		}
		else{
			s=(t+s)%p;
			t=x%p;
		}
	}while(cin>>c>>x);
	cout<<(s+t)%p<<endl;
	return 0;
}
