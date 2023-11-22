#include<bits/stdc++.h>
using namespace std;
bool a(int x,int y){
	return x>y;
}
bool b(int x,int y){
	cout<<1<<endl;
	return x<y;
}
int main(){
	if(b(1,2)&&a(1,2)) cout<<0<<endl;
	if(a(1,2)&&b(1,2)) cout<<0<<endl;
}

