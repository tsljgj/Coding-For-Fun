#include<bits/stdc++.h>
using namespace std;
const int N=(1<<24)+1;
long long ans, n, m, a[N], s[N], n_2;
long long find(int val){
	int l=1, r=n_2, check=m-val;
	while(l<r){
		int mid=(l+r+1)>>1;
		if(s[mid]<=check){
			l=mid;
		}
		else r=mid-1;
	}
	ans=max(ans,s[l]+val);
}
bool cmd(long long  a,long long b){
	return a>b;
}
int dfs(int x,long long sum){
	if(x==(n/2+2)+1){
		s[++n_2]=sum;
		return true;
	}
	dfs(x+1,sum);
	if(sum+a[x]<=m) dfs(x+1,sum+a[x]);
}

int dfs2(int x,int sum){
	if(x==n+1){
		find(sum);
		return true;
	}
	dfs2(x+1,sum);
	if(sum+a[x]<=m)
		dfs2(x+1,sum+a[x]);
}
int main(){
	cin>>m>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1,cmd);
	dfs(1,0);
	sort(s+1,s+n_2+1);
	n_2=unique(s+1,s+n_2+1)-(s+1);
	dfs2(n/2+3,0);
	cout<<ans<<endl;
	return 0;
}

