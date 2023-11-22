#include<bits/stdc++.h>
using namespace std;
const int N=100020, MOD=99991;
int head[N], nxt[N];
int snow[N][10];
int tot=0;

int H(int *a){
	int M=0,II=1;
	for(int i=0;i<6;i++) M=(M+a[i])%MOD;
	for(int i=0;i<6;i++) II=((long long)II*a[i])%MOD;
	return (M+II)%MOD;
}

bool equal(int *a,int *b){
	for(int j=0;j<6;j++){
		bool eq=1;
		for(int k=0;k<6;k++) if(a[(0+k)%6]!=b[(j+k)%6]) eq=0;
		if(eq) return 1;
		eq=1;
		for(int k=0;k<6;k++) if(a[(0+k)%6]!=b[(j-k+6)%6]) eq=0;
		if(eq) return 1;
	}
//	for(int i=0;i<6;i++){
//		int re=1;
//		for(int j=0;j<6;j++){
//			if(a[1+j]!=b[1+(i+j)%6]) re=0;
//		}
//		
//		if(re) return 1;
//		
//		for(int j=0;j<6;j++){
//			if(a[1+j]!=b[1+(i-j+6)%6]) re=0;
//		}
//		if(re) return 1;
//	}
//	for(int i=1;i<=6;i++){
//		for(int k=1;k<=6;k++){
//			int re=1;
//			for(int j=0;j<6;j++){
//				if(a[(i+j)%6]!=b[(k+j)%6]) re=0; 
//			}
//			if(re) return 1;
//		}
//	}
	return 0;
}

bool insert(int *a){
	int h=H(a);
	for(int i=head[h];i;i=nxt[i]){
		if(equal(snow[i],a)) return 1;
	}
	tot++;
	for(int i=0;i<6;i++){
		snow[tot][i]=a[i];
	}
	nxt[tot]=head[h];
	head[h]=tot;
	return 0;
}
int main(){
	int n;
	cin>>n;
	for(int i=1;i<=n;i++){
		int a[10];
		for(int j=0;j<6;j++){
			cin>>a[j];
		}
		if(insert(a)) {
			cout<<"Twin snowflakes found."<<endl;
			return 0;
		}
	}
	cout<<"No two snowflakes are alike."<<endl;
	return 0;
}
