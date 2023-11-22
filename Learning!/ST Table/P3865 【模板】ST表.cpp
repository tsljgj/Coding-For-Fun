#include<bits/stdc++.h>
using namespace std;
const int MAXN=1e6+10;
inline int read()
{
	int x=0,f=1;
	char ch=getchar();
	while (ch<'0'||ch>'9'){if (ch=='-') f=-1;ch=getchar();}
	while (ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
	return x*f;
}
int Max[MAXN][21];
int query(int l,int r){
	int len=log2(r-l+1);           //len是小于区间长度的最大2的幂 
	return max(Max[l][len],Max[r-(1<<len)+1][len]);
}
int main(){
	int n=read(),m=read();
	
//	lg[1]=0;
//	lg[2]=1;
//	
//	for(int i=3;i<=n;i++) lg[i]=lg[i/2]+1;
	
	
	for(int i=1;i<=n;i++){
		Max[i][0]=read();	
	} 
	
	for(int j=1;j<=21;j++){
		for(int i=1;i+(1<<j)-1<=n;i++){
			Max[i][j]=max(Max[i][j-1],Max[i+(1<<(j-1))][j-1]);
		}
	}
	
	for(int i=1;i<=m;i++){
		int l=read(),r=read();
		cout<<query(l,r)<<endl;     //   ??
//      printf("%d\n",query(l,r));

	}
	return 0;
}
