#include<bits/stdc++.h>
using namespace std;
int n,m;
long long a[100020];    //原始数据 
long long sum[262143]; //叶子节点n个，则高log2(n)+1,总个数2^(log2(n)+1)-1 ,算的时候可以将log2(n)先算出来然后取天花板 
long long la[262143];   //标记 
void build(int i,int l,int r){
	if(l==r){
		sum[i]=a[l];       //a[l]不是a[i]啊啊啊啊啊啊啊啊啊 
		return;
	}
	int mid=(l+r)/2;
	build(i*2,l,mid);
	build(i*2+1,mid+1,r);
	sum[i]=sum[i*2]+sum[i*2+1];
}

void add(int i,int l,int r,long long k){
	sum[i]+=(r-l+1)*k;
	la[i]+=k;
	return;
}

void push(int i,int l,int r){
	int mid=(l+r)/2;            
	add(i*2,l,mid,la[i]);      //把父节点标记里的值更新到子节点去并且让子节点继承父标记 
	add(i*2+1,mid+1,r,la[i]);   //新标记直接在change里后传，此处只将父标记下传和求和 
	
	la[i]=0;                 //标记传承并将之标记和加入到子节点中后标记就用完了
	return;
}

void change(int i,int l,int r,int L,int R,long long k){    //L~R是要改的区间，l~r是搜索区间 
	if(L>r||R<l) return; //*写错 //如果搜索的区域完全不在要修改的区域内则return 
	if(L<=l&&r<=R){     //**写错 //如果搜索的区域都在修改的区域内则直接sum加,加标记，return 
//		add(i,l,r,k);
		sum[i]+=(r-l+1)*k;
		la[i]+=k;       //标记要累加 
		return;
	}
	
//	if(L>=l||R<=r){     //如果搜索的区域部分在要修改的区域内(可不写if) 
//		
//	}
	
//	int mid=(l+r)/2;             
//	add(i*2,l,mid,la[i]);       
//	add(i*2+1,mid+1,r,la[i]);
//	la[i]=0;                 //新标记传承并将之前标记求和加入到子节点中后标记就用完了 
	
	push(i,l,r);    //替换上面一坨 
	
	int mid=(l+r)/2;
	change(i*2,l,mid,L,R,k);          //继续搜索 
	change(i*2+1,mid+1,r,L,R,k);
	sum[i]=sum[i*2]+sum[i*2+1];                //这里直接求和而不打标记是因为有可能区间部分被修改了
	return;											//标记只用于子节点全部被修改了 
}

long long query(int i,int l,int r,int L,int R){
	if(L<=l&&r<=R){    //写错 
		return sum[i];
	}
	
	if(r<L||R<l) return 0;  //写错，此处特别小心 
	
	push(i,l,r);   //change和query都是要触碰到数据了才push标记 
	
	int mid=(r+l)/2;
	return query(i*2,l,mid,L,R)+query(i*2+1,mid+1,r,L,R);
}
int main(){
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	build(1,1,n);
	
	for(int i=1;i<=m;i++){
		int o;
		cin>>o;
		if(o==1) {
			int x,y;
			long long k;
			cin>>x>>y>>k;
			change(1,1,n,x,y,k);
		}
		else{
			int x,y;
			cin>>x>>y;
			cout<<query(1,1,n,x,y)<<endl;
		}
	}
	return 0;
}
