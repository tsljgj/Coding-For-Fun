#include<bits/stdc++.h>
#define mp make_pair
#define fi first
#define se second
#define pb push_back
using namespace std;
const int MAXN=100020, MAXM=2*MAXN;
int n;
vector<pair<int,int> > a[MAXM];
int dis[MAXN];

void dfs(int u, int fa){
	for(int i=0;i<a[u].size();i++){
		int v=a[u][i].fi;
		if(v!=fa){                   //˫�������Ҫ�жϣ��Է�fa=v�ֻ�ȥ�� 
			dis[v]=dis[u]^a[u][i].se;         //��һ������չ�������ǻ��ݺ��ٸ�ֵ 
			dfs(v,u);
		}
	}
}
int main(){
	cin>>n;
	for(int i=1;i<n;i++) {
		int u,v,c;
		cin>>u>>v>>c;
		a[u].pb(mp(v,c));
		a[v].pb(mp(u,c));
	}
	
	dfs(1,0);
	
	int k;
	cin>>k;
	for(int i=1;i<=k;i++){
		int u,v;
		cin>>u>>v;
		cout<<(dis[u]^dis[v])<<endl;
	}
	return 0;
} 
