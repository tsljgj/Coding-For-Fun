#include<bits/stdc++.h>
#define LL long long
//11111100101
//4
//2 0 2 1
using namespace std;
const long long MOD=1e9+7;
string s="a";
string n;
int k;
LL a[520], prep=0, ans=0;

inline void cal(LL x){
	for(int i=0;i<k;i++){
		LL sum=a[i];
		for(int j=1;j<=i;j++){
			sum=(sum*x)%MOD;
		}
		ans=(ans+sum)%MOD;
	}
}

inline void outS(){
	int l=s.size();         //上一次过s时最后的s里位置 
	for(int i=0;i<l;i++){
		if(s[i]=='a') {
			s+='b';
		}
		else {
			s+='a';
		}
	}
}

int main(){
//	cin>>n>>k; 
	n="1111111111";
	for(int i=0;i<k;i++) cin>>a[i];
	for(int i=0;i<n.size();i++) outS();
	int fl=1;
	for(int i=2;i<s.size()-1;i++){
		if(s[i]=='b') {
			cout<<i-fl<<" ";
			fl=i;
		}
	}
////	cout<<"a"<<s<<endl;
//	for(int i=0;i<n.size();i++){
//		if(n[i]=='1'){
////			cout<<"n[i]=1"<<endl;
//			int power=n.size()-i-1;
//			LL addi=(1<<power);
////			cout<<"addi="<<addi<<endl;
//			LL j;
//			for(j=prep;j<prep+addi;j++){
//				if(s[j]=='b') {
////					cout<<"j="<<j<<endl;
//					cal(j);
//				}	
//			}	
//			prep=j+1;
//		}
//	}
//	cout<<ans<<endl;
}
