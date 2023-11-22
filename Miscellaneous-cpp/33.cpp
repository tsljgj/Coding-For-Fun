#include<bits/stdc++.h>
#define fi first
#define se second
#define mp make_pair
using namespace std;
const int MAXN=1e5+1e2;
int n,m1,m2;
//int a[MAXN], b[MAXN];
//priority_queue<pair<int,int> > a,b; 
set<pair<int,int> > a,b;
int aa[MAXN];
int bb[MAXN];

int main(){
	cin>>n>>m1>>m2;
	for(int i=1;i<=m1;i++){
		int x,y;
		cin>>x>>y;
//		a.push(mp(x,y));
//		cin>>a[i].fi>>a[i].se;
		a.insert(mp(x,y));
	}
	
	for(int i=1;i<=m2;i++){
		int x,y;
		cin>>x>>y;
//		b.push(mp(x,y));
//		cin>>b[i].fi>>b[i].se;
		b.insert(mp(x,y));
	}
	
	int late,cnt=0,ans;
	while(a.size()||cnt==n){
		late=0,ans=0;
		for(set<pair<int,int> >::iterator it=a.begin();it!=a.end();){
			if((*it).fi>late){
				late=(*it).se;
				set<pair<int,int> >::iterator ti=it;
				it++;
				a.erase(ti);
				ans++;
				continue;
			}
			it++;
		} 
		aa[++cnt]=ans+aa[cnt-1];
	}
	
	cnt=0;
	while(b.size()||cnt==n){
		late=0,ans=0;
		for(set<pair<int,int> >::iterator it=b.begin();it!=b.end();){
			if((*it).fi>late){
				late=(*it).se;
				set<pair<int,int> >::iterator ti=it;
				it++;
				b.erase(ti);
				ans++;
				continue;
			}
			it++;
		} 
		bb[++cnt]=ans+bb[cnt-1];
	}
	
	
//	for(int i=1;i<=cnt;i++) cout<<bb[i]<<" ";
	int ans0=0;
	for(int i=1;i<=n;i++){
		ans0=max(ans0,aa[i]+bb[i]);
	}
	
	cout<<ans0<<endl;
	
//	while(a.size()){
//		if(a.top().fi>late){
//			late=a.top().se;
//			a.pop();
//			cnt++;
//		}
//	}
}
