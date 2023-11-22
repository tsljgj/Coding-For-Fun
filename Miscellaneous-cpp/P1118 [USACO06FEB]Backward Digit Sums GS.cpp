#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[20];
int y[13][20];
int main(){
	cin>>n>>m;
	if(n==1){
		if(m==1) cout<<1<<endl;
		else return 0;
	}
	y[1][1]=1;
	y[1][2]=1;
	for(int i=2;i<=n-1;i++){
		y[i][1]=1;
		y[i][i+1]=1;
		for(int j=2;j<=i;j++){
			y[i][j]=y[i-1][j-1]+y[i-1][j];
		}
	}
	
//	for(int i=1;i<=n;i++) cout<<y[n-1][i]<<" ";
	
	for(int i=1;i<=n;i++){
		a[i]=i;
	}
	
	int sum;
	
	do{
		sum=0;
//		t=0;
//		for(int i=1;i<=n;i++) cout<<a[i]<<" ";
//		cout<<endl;
		for(int i=1;i<=n;i++){
			sum+=a[i]*y[n-1][i];
//			cout<<a[i]*y[n-1][i]<<" ";
			if(sum>m) {
				sort(a+i+1,a+n+1,greater<int>());
//				t=1;
				break;
			}
		}
		
//		if(t==1) continue;
//		cout<<endl;
		
		if(sum==m) {
			for(int i=1;i<=n;i++) cout<<a[i]<<" ";
			return 0;
		}
		
	}while(next_permutation(a+1,a+n+1));
	return 0;
}
