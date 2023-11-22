#include<bits/stdc++.h>
#define mp make_pair
#define fi first
#define se second
using namespace std;
const int MAXM=1e5+1e2;
int n,m1,m2;
pair<int,int> dome[MAXM], inte[MAXM];
priority_queue<int, vector<int>, greater<int> > qq;
priority_queue<pair<int,int>, vector<pair<int,int> >, greater<pair<int,int> > >  q; 
int domes[MAXM], intes[MAXM];
int ans=0;
int main(){
	 cin>>n>>m1>>m2;
	 for(int i=1;i<=m1;i++){
	 	int arr, lea;
	 	cin>>arr>>lea;
	 	dome[i]=mp(arr,lea);
	 }
	 
	 for(int i=1;i<=m2;i++){
	 	int arr, lea;
	 	cin>>arr>>lea;
	 	inte[i]=mp(arr,lea);
	 }
	 
	 sort(dome+1,dome+m1+1);
	 sort(inte+1,inte+m2+1);
	 
	 for(int i=1;i<=m1;i++) qq.push(i);
	 
	 for(int i=1;i<=m1;i++){
	 	while(q.size()){
	 		if(q.top().fi<dome[i].fi){
	 			qq.push(q.top().se);
	 			q.pop();
			}
			else break;
		}
		q.push(mp(dome[i].se,qq.top()));
//		cout<<qq.top()<<" ";
		domes[qq.top()]++;
//		cout<<domes[qq.top()]<endl;
		qq.pop();
	 }
	 
	 for(int i=1;i<=m1;i++) domes[i]+=domes[i-1];
	 
	 while(q.size()) q.pop();
	 while(qq.size()) qq.pop();
	 while(1){
	 	for(){
	 		set<int> ::iterator
		 }
	 }
	 
	 for(int i=1;i<=m2;i++) qq.push(i);
	 
	 for(int i=1;i<=m2;i++){
	 	while(q.size()){
	 		if(q.top().fi<inte[i].fi){
	 			qq.push(q.top().se);
	 			q.pop();
			}
			else break;
		}
		q.push(mp(inte[i].se,qq.top()));
//		cout<<qq.top()<<" ";
		intes[qq.top()]++;
//		cout<<domes[qq.top()]<endl;
		qq.pop();
	 }
	 
	 for(int i=1;i<=m1;i++) intes[i]+=intes[i-1];
	 
//	 for(int i=1;i<=m1;i++) cout<<intes[i]<<endl;
//	 for(int i=1;i<=m2;i++)

	 for(int i=0;i<=n;i++){
	 	ans=max(ans,domes[i]+intes[n-i]);
	 }
	 
	 cout<<ans<<endl;
}
