#include<bits/stdc++.h>
#define mp make_pair
#define fi first
#define se second
using namespace std;
int n,m;
int a[20020][20020];
pair<int,pair<int,int> > r[100020];
set<int> q1,q2;
int minn=0;
bool cmp(int x,int y) {
	return x>y;
}

int cal1(int x){
	set<int>::iterator it;
	int maxn=0;
	for(it=q1.begin();it!=q1.end();it++){
		maxn=max(maxn,a[x][(*it)]);
	} 
	return maxn;
}

int cal2(int x){
	set<int>::iterator it;
	int maxn=0;
	for(it=q2.begin();it!=q2.end();it++){
		maxn=max(maxn,a[x][(*it)]);
	} 
	return maxn;
}

int main(){
	cin>>n>>m;
	for(int i=1;i<=m;i++){
		int x,y,c;
		cin>>x>>y>>c;
		a[x][y]=c;
		a[y][x]=c;
		r[i]=mp(c,mp(x,y));
	}
	
	sort(r+1,r+m+1);
	
	for(int i=m;i>=1;i--){
		if(r[i].fi<=minn) break;
		int max1=max(cal1(r[i].se.fi),cal2(r[i].se.se)), max2=max(cal1(r[i].se.se),cal2(r[i].se.fi));
		if(max1<max2) q1.insert(r[i].se.fi), q2.insert(r[i].se.se), minn=max1;
		else q1.insert(r[i].se.se), q2.insert(r[i].se.fi), minn=max2;
	}
	
	cout<<minn<<endl;
	return 0;
}
