#include<bits/stdc++.h>
using namespace std;
double sum1[300000],sum2[300000];
double la[300000];
void build(int i,int l,int r){
	if(l==r){
		cin>>sum1[i];
		sum2[i]=sum1[i]*sum1[i];
		return;
	}
	
	int mid=(l+r)/2;
	build(i*2,l,mid);
	build(i*2+1,mid+1,r);
	sum1[i]=sum1[i*2]+sum1[i*2+1];
	sum2[i]=sum2[i*2]+sum2[i*2+1];
	return;
}

void add(int i,int l,int r,double lazy){
	la[i]+=lazy;
	sum2[i]+=2*lazy*sum1[i]+(r-l+1)*lazy*lazy;    // 两行顺序不能反，改变后用的代数表达式中的值除了变值k(lazy)其他都是原来的值 
	sum1[i]+=(r-l+1)*lazy;						 // 因为平方和的变化代数表达式中，总和是改变之前的总和 
	return;
}

void push(int i,int l,int r){         //下传标记 
	int mid=(l+r)/2;
	add(i*2,l,mid,la[i]);
	add(i*2+1,mid+1,r,la[i]);
	la[i]=0;
	return;
}

void change(int i,int l,int r,int L,int R,double k){
	if(l>R||r<L) return;
	if(L<=l&&r<=R) {
//		sum1[i]+=k*(r-l+1);
//		sum2[i]+=2*k*sum1[i]+(r-l+1)*k*k;
//		la[i]+=k;      //无论如何，标记要累加 
		add(i,l,r,k);
		return;
	}
	
	push(i,l,r);
	
	int mid=(l+r)/2;
	change(i*2,l,mid,L,R,k);
	change(i*2+1,mid+1,r,L,R,k);
	sum1[i]=sum1[i*2]+sum1[i*2+1];
	sum2[i]=sum2[i*2]+sum2[i*2+1];
	return;
}

double query(double s[],int i,int l,int r,int L,int R){
	if(l>R||r<L) return 0;
	if(L<=l&&r<=R) return s[i];
	
	push(i,l,r);
	
	int mid=(l+r)/2;
	return query(s,i*2,l,mid,L,R)+query(s,i*2+1,mid+1,r,L,R);
}

int main(){
	int n,m;
	cin>>n>>m;
	
	build(1,1,n);     //别忘了build.. 
	
	for(int i=1;i<=m;i++){
		int o;
		cin>>o;
		if(o==1){
			int x,y;
			double k;
			cin>>x>>y>>k;
			change(1,1,n,x,y,k);
//			for(int j=1;j<=pow(2,log2(n)+1);j++) cout<<sum1[j]<<" "<<sum2[j]<<endl;
		}
		else if(o==2){
			int x,y;
			cin>>x>>y;
			cout<<fixed<<setprecision(4)<<query(sum1,1,1,n,x,y)/(y-x+1)<<endl;
		}
		else{
			int x,y;
			cin>>x>>y;
			double z1=query(sum1,1,1,n,x,y)/(y-x+1),z2=query(sum2,1,1,n,x,y)/(y-x+1);
			cout<<fixed<<setprecision(4)<<z2-z1*z1<<endl;	
		}
	}
}
