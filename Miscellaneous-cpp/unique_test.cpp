#include<bits/stdc++.h>
using namespace std;
int main(){
	int a[10];
	a[1]=2;
	a[2]=2;
	a[3]=3;
	a[4]=3;
	for(int i=5;i<=9;i++) a[i]=i;
	cout<<unique(a+1,a+10)-a-1<<endl;
}
