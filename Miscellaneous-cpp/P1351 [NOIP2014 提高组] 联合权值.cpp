#include<bits/stdc++.h>
using namespace std;
const int MAXN=200020, MAXM=2*MAXN, MOD=10007;
int n;
int w[MAXN];
vector<int> a[MAXM];
int b[3],f=1;
int ans1=0, ans2=0;
//int dfs(int u,int fa){
//	for(int i=0;i<a[u].size();i++){
//		int v=a[u][i];
//		if(v!=fa){
//			long long d=b[f^1]*w[fa];
//			b[f^=1]=w[u];
//			maxn=max(maxn,d);
//			ans=(ans+d)%MOD;
//			dfs(v,u);
//		}
//	}
//}
int main(){
	cin>>n;
	for(int i=1;i<n;i++){
		int u,v;
		cin>>u>>v;
		a[u].push_back(v);
		a[v].push_back(u);
	}
	
	for(int i=1;i<=n;i++) cin>>w[i];
	
//	dfs(1,0);
//	for(int i=1;i<=n;i++){
//		int sum=0;
//		for(int j=0;j<a[i].size();j++){
//			ans=(ans+sum*w[a[i][j]])%MOD;
//			maxn=max(maxn,(long long)w[a[i][j]]*sum);
//			sum=w[a[i][j]];
//		}
//	}
	for (int i = 1; i <= n; i++) {
		int sum = 0;
		for (int j = 0; j < a[i].size(); j++) {
			a[i][j] = w[a[i][j]];
			ans2 = (ans2 + sum * a[i][j]) % MOD;
			sum = (sum + a[i][j]) % MOD;
		}
		sort(a[i].begin(), a[i].end());
		if (a[i].size() >= 2) {
			ans1 = max(ans1, a[i][0] * a[i][1]);
		}
	}
	
	cout<<ans1<<" "<<ans2*2%MOD<<endl;
} 
