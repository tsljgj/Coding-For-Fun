#include<bits/stdc++.h>
using namespace std;
int n, s=0;
int main(){
	for(cin>>n;n!=0;n/=10) s=s*10+n%10;
	cout<<s<<endl;
} 
