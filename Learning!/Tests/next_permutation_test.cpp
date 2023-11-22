#include<bits/stdc++.h>
using namespace std;
int main(){
	int n,m;
	cin>>n>>m;
	int b[n];
	memset(b,0,sizeof(b));

	
//	for(int i=n-1;i>n-m-1;i--){               
//		b[i]=1;
//	}

	for(int i=0;i<m;i++) b[i]=1;                //next_permutation若已是字典序则不排了
	
	
	
	do{
		for(int i=0;i<n;i++){
			cout<<b[i]<<" ";
		}
		cout<<endl;
		
	}while(next_permutation(b,b+n));
}
