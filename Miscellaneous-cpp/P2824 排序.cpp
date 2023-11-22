#include<bits/stdc++.h>
using namespace std;
const int N=100010;
int n,m,p;
int T[4*N], lazy[4*N];
int a[N], ch[N], L[N], R[N];
void build(int o,int l,int r,int x){
	if(l==r){
		if(a[l]>=x) T[o]=1;
		else T[o]=0;
		lazy[o]=0;
		return;
	}
	int mid=(l+r)>>1;
	build(o*2,l,mid,x);
	build(o*2+1,mid+1,r,x);
	T[o]=T[o*2]+T[o*2+1];
	lazy[o]=0;
}

void pushdown(int o,int l,int r){
	if(!lazy[o]) return;
	lazy[o*2]=lazy[o*2+1]=lazy[o];
	int mid=(l+r)>>1;
	if(lazy[o]==1){
		T[o*2]=mid-l+1;
		T[o*2+1]=r-mid;
	}else{
		T[o*2]=T[o*2+1]=0;
	}
	lazy[o]=0;
}
void update(int o,int l,int r,int x,int y,int val){
	if(x<=l&&y>=r){
		T[o]=val*(r-l+1);
		lazy[o]=val?1:-1;
		return;
	}
	if(x>r||y<l) return;
	pushdown(o,l,r);
	int mid=(l+r)>>1;
	update(o*2,l,mid,x,y,val);
	update(o*2+1,mid+1,r,x,y,val);
	T[o]=T[o*2]+T[o*2+1];
}

int query(int o,int l,int r,int x,int y){
	if(x<=l&&y>=r) return T[o];
	if(x>r||y<l) return 0;
	pushdown(o,l,r);
	int mid=(l+r)>>1;
	return query(o*2,l,mid,x,y)+query(o*2+1,mid+1,r,x,y);
}

int queryPoint(int o,int l,int r,int x){
	if(l==x&&r==x) return T[o];
	pushdown(o,l,r);
	int mid=(l+r)>>1;
	if(x<=mid) return queryPoint(o*2,l,mid,x);
	else return queryPoint(o*2+1,mid+1,r,x);
}

bool check(int x){
	build(1,1,n,x);
	for(int i=1;i<=m;i++){
		int cnt1=query(1,1,n,L[i],R[i]);
		if(ch[i]==0){
			update(1,1,n,R[i]-cnt1+1,R[i],1);
			update(1,1,n,L[i],R[i]-cnt1,0);
		}
		else{
			update(1, 1, n, L[i], L[i]+cnt1-1, 1);
            update(1, 1, n, L[i]+cnt1, R[i], 0);
		}
	} 
	return queryPoint(1,1,n,p);
}
int main(){
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	for(int i=1;i<=m;i++){
		cin>>ch[i]>>L[i]>>R[i];
	}
	cin>>p;
	int ll=1, rr=n, midd, ans;
	while(ll<=rr){
		midd=(ll+rr)>>1;
		if(check(midd)) ans=midd, ll=midd+1; else rr=midd-1;
	}
	cout<<ans<<endl;
	return 0;
}
