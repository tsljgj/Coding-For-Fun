#include<bits/stdc++.h>
using namespace std;
int n;
int a[120];
int main(){
	cin>>n;
//	for(int i=1;i<=n;i++) a[i]=1;
	cout<<n<<endl;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			if(j!=i) {
				if(a[j]==1) a[j]=0;
				else a[j]=1;
			}
			cout<<a[j];
		}
		cout<<endl;
	}
	return 0;
}
