#include<bits/stdc++.h>
using namespace std;
int n,q;
long long a[50020];
long long sum[150000];
long long la[150000];
void build(int i,int l,int r){
	if(l==r){
		sum[i]=a[l];
		return;
	}
	
	int mid=(r+l)/2;
	build(i*2,l,mid);
	build(i*2+1,mid+1,r);
	sum[i]=sum[i*2]+sum[i*2+1];
}

//void add(int i,int l,int r,long long debt){
//	sum[i]+=(r-l+1)*debt;
//	la[i]+=debt;
//}
//
//void push(int i,int l,int r){
//	int mid=(l+r)/2;
//	add(i*2,l,mid,la[i]);
//	add(i*2+1,mid+1,r,la[i]);
//	
//	la[i]=0;
//}

void change(int i,int l,int r,int L,int k){
	if(l==r) {
		sum[i]=k;
		return;
	}
		
	int mid=(l+r)/2;
	if(L<=mid){
		change(i*2,l,mid,L,k);
	}
	else{
		change(i*2+1,mid+1,r,L,k);
	}
	
	sum[i]=sum[i*2]+sum[i*2+1];
	return;

	
	
//	if(r<L||R<l) return;
//
//	if(L<=l&&r<=R){
//		sum[i]+=(r-l+1)*k;
//		la[i]+=k;
////		push(i,l,r,k);
//		return;
//	}
//		
//	push(i,l,r);
//	
//	int mid=(r+l)/2;
//	change(i*2,l,mid,L,R,k);
//	change(i*2+1,mid+1,r,L,R,k);
//	sum[i]=sum[i*2]+sum[i*2+1];
//	return;
}

long long query(int i,int l,int r,int L,int R){
	if(L<=l&&r<=R) return sum[i];
	if(l>R||r<L) return 0;
	
//	push(i,l,r);        //别忘了询问也要push 
	
	int mid=(l+r)/2;
	return query(i*2,l,mid,L,R)+query(i*2+1,mid+1,r,L,R);
}
int main(){
	cin>>n;
	for(int i=1;i<=n;i++) cin>>a[i];
	
	build(1,1,n);
	
	cin>>q;
	
	
	while(q>0){
		q--;
		int o;
		cin>>o;
		
		if(o==1){
			int l,r;
			cin>>l>>r;
			cout<<query(1,1,n,l,r)<<endl;
		}
		else{
			long long k;
			int l;
			cin>>l>>k;
			change(1,1,n,l,k);
		}
		
	}
	
	return 0;
}
