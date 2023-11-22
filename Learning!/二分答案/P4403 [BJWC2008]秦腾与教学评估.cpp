#include<bits/stdc++.h>
#define int long long       //±ØÐë¿ªlong long
using namespace std;
const int MAXN=200020;
int T, N, s[MAXN], e[MAXN], d[MAXN];
int pos, number;

inline int read() {
	int sum=0; char ch=getchar();
	while(!isdigit(ch)) ch=getchar();
	while(isdigit(ch)) 
		sum=sum*10+(ch^48),ch=getchar();
	return sum;
}

inline int valid(int mid){
	int num=0;
	for(int i=1;i<=N;i++){
		if(s[i]>mid) continue;
		num+=(min(mid,e[i])-s[i])/d[i]+1;
	}	
	return num;
}

signed main(){
	T=read();
	while(T--){
		N=read();
		int sum=0,maxn=0;
		for(int i=1;i<=N;i++){
	//		cin>>s[i]>>e[i]>>d[i];
			s[i]=read();
			e[i]=read();
			d[i]=read();
			sum+=(e[i]-s[i])/d[i]+1;
			maxn=max(maxn,e[i]);
		}
		
		if(sum%2==0) {
			cout<<"Poor QIN Teng:("<<endl;
			continue;
		}
		
		int l=0, r=maxn;
		while(l<r){
			int mid=(l+r)/2;
			if(valid(mid)&1) r=mid; else l=mid+1;            //?? 
		}
		
		int ans=0;
		for(int i=1;i<=N;i++){
			if(l<s[i]) continue; 
			if(l>e[i]) continue;
			if((l-s[i])%d[i]==0) ans++;
	//		if(l<=e[i]&&s[i]<=l&&(l-s[i])%d[i]==0) {
	//			ans++;	
	//		}
		}
		cout<<l<<" "<<ans<<endl;		
	} 
	return 0;
}
