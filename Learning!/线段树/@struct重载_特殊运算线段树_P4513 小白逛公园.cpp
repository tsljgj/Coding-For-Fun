#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[500020];
//int la[500020];
struct Node{
	int sm,lm,rm,mx;
	Node(int sm=0,int lm=0,int rm=0,int mx=0):sm(sm),lm(lm),rm(rm),mx(mx){};
}t[1048577]; 

Node operator +(const Node&a, const Node&b){
	return Node(a.sm+b.sm,max(a.lm,a.sm+b.lm),max(b.rm,b.sm+a.rm),max(a.rm+b.lm,max(a.mx,b.mx)));
}

void build(int i,int l,int r){
	if(l==r) {
		t[i]=Node(a[l],a[l],a[l],a[l]);
		return;
	}
	
	int mid=(l+r)/2;
	build(i*2,l,mid);
	build(i*2+1,mid+1,r);
	t[i]=t[i*2]+t[i*2+1];
	return;
	
}

//void add(int i,int l,int r,int k){
//	t[i]=Node(t[])
//	la[i]+=k;
//	return;
//}
//
//void push(int i,int l,int r){
////	cout<<"push"<<endl;
//	int mid=(l+r)/2;
//	add(i*2,l,mid,la[i]);
//	add(i*2+1,mid+1,r,la[i]);
//	la[i]=0;
//	return;
//}

void change(int i,int l,int r,int p,int k){
	if(l==r) {
		t[i]=Node(k,k,k,k);
		return;
	}
	
	int mid=(l+r)/2;

	if(p>mid){
		change(i*2+1,mid+1,r,p,k);
	}
	else{
		change(i*2,l,mid,p,k);
	}

	t[i]=t[i*2]+t[i*2+1];
	return;
}

Node query(int i,int l,int r,int L,int R){
	if(L<=l&&r<=R){     // 小心！l,r在变,L,R是查找的范围,不变 
		return t[i];
	}
	
	int mid=(l+r)/2;

	if(L>mid) return query(i*2+1,mid+1,r,L,R);  //
	if(R<=mid) return query(i*2,l,mid,L,R);
	
	return query(i*2,l,mid,L,R)+query(i*2+1,mid+1,r,L,R);
}
int main(){
	cin>>n>>m;
	
	for(int i=1;i<=n;i++){
		cin>>a[i];
//		la[i]=0;
	}
	
	build(1,1,n);
	
//	for(int i=1;i<=2*n;i++) cout<<t[i]<<endl;
	
	for(int i=1;i<=m;i++){
		int o,x,y;
		cin>>o>>x>>y;
		if(o==1){
			if(x>y) swap(x,y);
			cout<<query(1,1,n,x,y).mx<<endl;
		}
		else change(1,1,n,x,y);
	}
	
	return 0;
}
