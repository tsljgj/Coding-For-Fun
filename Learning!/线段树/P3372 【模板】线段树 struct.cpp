#include<bits/stdc++.h>
using namespace std;
int a[1000];
struct treestruct{
	int l;
	int r;
	int sum;
}tree[10000];

void build(int i,int l,int r){     //l,r�Ǹýڵ������߶η�Χ ��i�ǽڵ��� 
	tree[i].l=l;                  //�̳з�Χ 
	tree[i].r=r;
	
	if(l==r){                 //�Ƿ�Ҷ�ӽڵ㣬��ʼ����ֵ����ʼ���� 
		tree[i].sum=a[l];        //l���߶ε�ֵ��ʵ����a[l] 
		return;
	} 
	
	int mid=(l+r)>>2;
	build(i*2,l,mid);               //��չ��ڵ㣬��� i*2,��Χ l~mid 
	build(i*2+1,mid+1,r);        //��չ�ҽڵ㣬��� i*2+1,��Χ mid+1,r
	tree[i].sum=tree[i*2].sum+tree[i*2+1].sum;      //���� 
	return;
}

int search(int i,int l,int r){
	if(tree[i].l>=l&&tree[i].r<=r) return tree[i].sum;   //�жϽ��� 
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
