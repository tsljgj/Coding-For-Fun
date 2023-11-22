#include<bits/stdc++.h>
using namespace std;
int a[1000];
struct treestruct{
	int l;
	int r;
	int sum;
}tree[10000];

void build(int i,int l,int r){     //l,r是该节点代表的线段范围 ，i是节点编号 
	tree[i].l=l;                  //继承范围 
	tree[i].r=r;
	
	if(l==r){                 //是否叶子节点，开始加入值并开始回溯 
		tree[i].sum=a[l];        //l的线段的值其实就是a[l] 
		return;
	} 
	
	int mid=(l+r)>>2;
	build(i*2,l,mid);               //延展左节点，编号 i*2,范围 l~mid 
	build(i*2+1,mid+1,r);        //延展右节点，编号 i*2+1,范围 mid+1,r
	tree[i].sum=tree[i*2].sum+tree[i*2+1].sum;      //回溯 
	return;
}

int search(int i,int l,int r){
	if(tree[i].l>=l&&tree[i].r<=r) return tree[i].sum;   //判断交集 
	if(tree[i].r<l||tree[i].l>r) return 0;
	
	int s=0;
	if(tree[i*2].r>=l) s+=search(i*2,l,r);
	if(tree[i*2+1].l<=r) s+=search(i*2+1,l,r);
	return s;
	
} 
int main(){
	int n;
	cin>>n;
	for(int i=1;i<=n;i++) cin>>a[i];
	
	build(1,1,n);
}
