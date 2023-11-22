#include<bits/stdc++.h>
using namespace std;
int a[4]={2,3,5,7}, b[4]={1,3,7,9};
int c[10];
int n;
bool check(int x){
	int num=0;
	for(int i=1;i<=x;i++){
		num+=c[i]*pow(10,x-i);
	}
	for(int i=3;i*i<=num;i+=2){
		if(num%i==0) return 0;
	}
	return 1;
}
void dfs(int x){
	if(x==n+1){
		for(int i=1;i<=n;i++) cout<<c[i];
		cout<<endl;
		return;
	}
	if(x==1){
		for(int i=0;i<4;i++){
			c[x]=a[i];
			dfs(x+1);		
		}
	}
	else{
		for(int i=0;i<4;i++){
			c[x]=b[i];
			if(check(x)){
				dfs(x+1);
			}
		}
	}
	return;
}
int main(){
	cin>>n;
	dfs(1);
	return 0;
}
//
//#include<bits/stdc++.h>
//using namespace std;
//const int MAXN=100000000;
//int n;
//int a[100000000];
//void prepare(){
//	a[1]=1;
//	for(int i=2;i<=MAXN;i++){
//		if(a[i]==0){
//			for(int j=i+i;j<=MAXN;j+=i){
//				a[j]=1;
//			}
//		}  
//	}
//	return;
//}
//int main(){
//	cin>>n;
//	prepare();
//	for(int i=pow(10,n-1);i<pow(10,n);i++){
//		int t=i;
//		while(t!=0){
//			if(a[t]) break;
//			t/=10;
//		}
//		if(!t) cout<<i<<endl;
//	}
//	return 0;
//}
