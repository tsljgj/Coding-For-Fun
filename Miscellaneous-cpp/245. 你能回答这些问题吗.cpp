#include<bits/stdc++.h>
using namespace std;
const int MAXN=500020;
int a[MAXN];
int n,m;
struct tree{
	int lm, rm, mm;
	int sum;
} t[MAXN*4];

void build(int p,int l,int r){
	if(l==r) {
		t[p].lm=a[l], t[p].rm=a[l], t[p].mm=a[l], t[p].sum=a[l];
		return;
	}
	int mid=(l+r)>>1;
	build(p*2,l,mid);
	build(p*2+1,mid+1,r);
	t[p].lm=max(t[p*2].lm,t[p*2].sum+t[p*2+1].lm);
	t[p].rm=max(t[p*2+1].rm,t[p*2+1].sum+t[p*2].rm);
	t[p].mm=max(t[p*2].rm+t[p*2+1].lm,max(t[p*2].mm,t[p*2+1].mm));
	t[p].sum=t[p*2].sum+t[p*2+1].sum;
}

void change(int p,int l,int r, int x, int y){
	if(l==r) {
		t[p].lm=y, t[p].rm=y, t[p].mm=y, t[p].sum=y;
		return;
	}
	int mid=(l+r)/2;
	if(mid>=x) change(p*2,l,mid,x,y);
	else change(p*2+1,mid+1,r,x,y);
	t[p].lm=max(t[p*2].lm,t[p*2].sum+t[p*2+1].lm);
	t[p].rm=max(t[p*2+1].rm,t[p*2+1].sum+t[p*2].rm);
	t[p].mm=max(t[p*2].rm+t[p*2+1].lm,max(t[p*2].mm,t[p*2+1].mm));
	t[p].sum=t[p*2].sum+t[p*2+1].sum;
}

tree query(int p, int l, int r, int x, int y){
	if(x<=l&&r<=y) return t[p];
	int mid=(l+r)/2;
	tree pp,q,k;
	if(y<=mid) {
		return query(p*2, l, mid, x, y);
	}
	else if(x>mid) return query(p*2+1, mid+1, r, x, y);
	
	pp=query(p*2, l, mid, x, y), q=query(p*2+1, mid+1, r, x, y);
	k.lm=max(pp.lm,pp.sum+q.lm);
	k.rm=max(q.rm,q.sum+pp.rm);
	k.mm=max(pp.rm+q.lm,max(pp.mm,q.mm));
	k.sum=pp.sum+q.sum;
	
	return k;	
}

int main(){
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	build(1,1,n);
	
	for(int i=1;i<=m;i++){
		int o,l,r;
		cin>>o>>l>>r;
		if(o==1){
			if(l>r) swap(l,r);
			cout<<query(1,1,n,l,r).mm<<endl;
		}
		else{
			change(1,1,n,l,r);
		}
	}
}
