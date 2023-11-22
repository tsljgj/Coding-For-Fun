#include<bits/stdc++.h>
#define fi first
#define se second
using namespace std;
const int MAXN=1e5+1e2;
int n,m1,m2;
set<int> s;
pair<int,int> dome[MAXN], inte[MAXN];
int ans=0;
int cnt=0;
int main(){
	cin>>n>>m1>>m2;
	for(int i=1;i<=m1;i++) cin>>dome[i].fi>>dome[i].se;
	for(int i=1;i<=m2;i++) cin>>inte[i].fi>>inte[i].se;
	sort(dome+1,dome+m1+1);
	sort(inte+1,inte+m2+1);
	for(int i=0;i<=n;i++){
		cnt=0;
		s.clear();
		for(int j=1;j<=m1;j++){
			if(i==0) break;
			if(!s.size()){
				s.insert(dome[j].se);
				cnt++;
//				cout<<"无停 +1:"<<cnt<<endl;
				continue;
			}
			if(*s.begin()<=dome[j].fi){
				s.erase(s.begin());
				s.insert(dome[j].se);
				cnt++;
//				cout<<"有飞走 +1："<<cnt<<endl;
			}else if(s.size()<i){
				s.insert(dome[j].se);
				cnt++;
//				cout<<"有空余 +1:"<<cnt<<endl;
			}
		}
		
		s.clear();
		
		for(int j=1;j<=m2;j++){
			if(i==n) break;
			if(!s.size()){
				s.insert(inte[j].se);
				cnt++;
//				cout<<cnt<<endl;
				continue;
			}
			if(*s.begin()<=inte[j].fi){
				s.erase(s.begin());
				s.insert(inte[j].se);
				cnt++;
//				cout<<cnt<<endl;
			}else if(s.size()<n-i){
				s.insert(inte[j].se);
				cnt++;
//				cout<<cnt<<endl;
			}
		}
//		cout<<"结论："<<cnt<<endl;
		ans=max(ans,cnt);
	}
	
	cout<<ans<<endl;
}
