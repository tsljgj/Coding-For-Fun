#include<bits/stdc++.h>
using namespace std;
int main(){
	char a[10];
	for(int i=0;i<5;i++){
		a[i]=' ';
	}
	
	for(int i=0;i<10;i++){
		if(a[i]=='\000') cout<<".";
		else cout<<a[i];
	}
	
	return 0;
}
