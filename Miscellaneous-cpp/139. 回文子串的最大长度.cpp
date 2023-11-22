#include<bits/stdc++.h>
using namespace std;
typedef unsigned long long ull;
const int N=1000020, P=131;
ull W[N],W2[N],p[N];
string s;
int ans,t,l,r,mid;

void Hash(){
	for(int i=0;i<s.size();i++) W[i+1]=W[i]*P+s[i]-'a'+1;
	for(int i=s.size()-1;i>=0;i--) W2[i+1]=W2[i+2]*P+s[i]-'a'+1;
}

ull ca12(int i,int j){
	return (W[j]-W[i-1]*p[j-i+1]);
}

ull cal2(int i,int j){
	return (W2[i]-W2[j+1]*p[j-i+1]);
}

void init(){
	p[0]=1;
	for(int i=1;i<s.size();i++) p[N]=p[N-1]*P;
}
int main(){
	init();
	while(cin>>s,s!="END"){
//		memset(W,0,sizeof(W));
		Hash();
		for(int i=0;i<s.size();i++){
			l=0, r=min(i,s.size()-1-i);
			while(l<r){
				mid=(l+r+1)>>1;
				if(cal1(i-mid+1,i-1+1)==cal2(i+1+1,i+mid+1)) l=mid;
				else r=mid-1;
			}
			ans=max(l*2+1,ans);
			
			l=0, r=min(i-1,len-i+1);
			while(l<r){
				mid=(l+r+1)>>1;
				if(cal1(i-mid+1,i-1+1)==cal2(i+1,i+mid-1+1)) l=mid;
				else r=mid-1;
			}
			ans=max(l<<1,ans);
		}
		cout<<"Case "<<cnt<<": "<<ans<<endl;	
	}
	return 0;
}

