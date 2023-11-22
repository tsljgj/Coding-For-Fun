#include<bits/stdc++.h>
using namespace std;
int n;
int a[100020];
int b[100020];
int height[100020];

void add(int i,int val){
	for(;i<=n;i+=i&(-i)) b[i]+=val;
}

//int query(int i){
//	int re=0; 
//	for(;i;i-=i&(-i)) re+=b[i];
//	return re;
//}

int multi(int x){
	int ans=0, sum=0;
	for(int i=log2(n);i>=0;i--){
		if(ans+(1<<i)<=n&&sum+b[ans+(1<<i)]<=x) {
			sum+=b[ans+(1<<i)];
			ans+=(1<<i);
		}
	}
	return ans+1;
}
int main(){
	cin>>n;
	
	add(1,1);
	for(int i=2;i<=n;i++) cin>>a[i], add(i,1);
	
	for(int i=n;i>=1;i--){
		int h=multi(a[i]);
		add(h,-1);
		height[i]=h;
	}
	
	for(int i=1;i<=n;i++) cout<<height[i]<<endl;
}
