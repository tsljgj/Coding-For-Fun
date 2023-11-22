#include<bits/stdc++.h>
using namespace std;
int n,m,k;
int f[20020], s[20020];
vector<int> v;
int sum=0, minn=1e9;
int ans=1e9;
int vis[20020];
int dp[40040];
int find(int x){
	if(f[x]==x) return x;
	else return f[x]=find(f[x]);
}
void U(int x,int y){
	int xx=find(x);
	int yy=find(y);
	f[x]=y;
	s[y]+=s[x];
	s[x]=0;
}
bool cmp(int x,int y){
	return x>y;
}

void dfs(int x){
	if(x==v.size()){
		minn=sum;
		return;
	} 
	
	if(abs(sum-m)>abs(minn-m)) return;
	if(abs(sum-m)==abs(minn-m)) {
		minn=min(minn,sum);
		return;
	}
	
	for(int i=0;i<v.size();i++){
		if(vis[i]) continue;
		vis[i]=1;
		sum+=v[i];
		dfs(x+1);
		vis[i]=0;
		sum-=v[i];
	}
}

int main(){
	cin>>n>>m>>k;
	for(int i=1;i<=n;i++) f[i]=i,s[i]=1;
	for(int i=1;i<=k;i++){
		int x,y;
		cin>>x>>y;
		U(x,y);
	}
	
	for(int i=1;i<=n;i++){
		if(s[i]) v.push_back(s[i]);
	}
	
	sort(v.begin(),v.end(),cmp);
	
	for(int i=0;i<v.size();i++){
		for(int j=2*m;j>=v[i];j--){
			dp[j]=max(dp[j],dp[j-v[i]]+v[i]);
		}
	}
	
	for(int i=0;i<=2*m;i++){
		if(minn>=abs(dp[i]-m)&&dp[i]){
			minn=abs(dp[i]-m);
			ans=min(ans,dp[i]);
		}
	}
//	for(int i=0;i<v.size();i++) cout<<v[i]<<endl;
	
//	dfs(0);
	
	cout<<ans<<endl;
	
}
