#include<bits/stdc++.h>
using namespace std;
int m;
int a[10000];
int ans[10000];
struct Node{
	int val;
	int prev,next;
	int id;
} A[10000];

bool operator < (const Node &x,const Node &y){
	return x.val<y.val;
}

void remove(int pos){
	A[A[pos].prev].next=A[pos].next;
	A[A[pos].next].prev=A[pos].prev;
}

void solve(){
	int cnt=0;
	sort(A+1,A+m+1);
	for(int i=1;i<=m;i++) a[A[i].id]=i;      //原数列中的数在链表里的位置 
	for(int i=1;i<=m;i++) A[i].prev=i-1, A[i].next=i+1;
	
	int mid=(m+1)/2;
	ans[++cnt]=A[mid].val;
	
	for(int i=m;i>1;i-=2){           //i>=1不行? ->i=m, i>1? 是则运行，然后-2；不是则停，所以不能= 
		int p1=a[i], p2=a[i-1];
		if(p1>p2) swap(p1,p2);
//		if(p1>=mid) mid--;              //不能怎么写，第一次删除是对的，接下来就错了，因为"删掉"链表是虚构的，只是接上两端而已，不能把下标拿来完 
//		if(p2<=mid) mid++;
		if(p1>=mid) mid=A[mid].prev;     
		if(p2<=mid) mid=A[mid].next;
//		cout<<A[mid].val<<" ";
		ans[++cnt]=A[mid].val;
		remove(p1), remove(p2);
	}
	int k=0;
	while(cnt--){
		++k;
		cout<<ans[cnt+1]<<" ";
		if(!(k%10)) cout<<endl;
	}
	if(k%10) cout<<endl;
	
}
int main(){
	int p;
	cin>>p;
	while(p--){
		int id;
		cin>>id>>m;
		for(int i=1;i<=m;i++){
			cin>>A[i].val;
			A[i].id=i;
		}
		cout<<id<<" "<<(m+1)/2<<endl;
		solve();
	}
}
