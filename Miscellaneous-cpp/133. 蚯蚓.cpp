#include<bits/stdc++.h>
#define LL long long
using namespace std;
const int INF=(1<<31);
LL n,m,q;
double u,v;
LL t;
double p;
LL a[100020];
queue<LL> q0,qq,qqq;
LL cmp(LL a,LL b){
	return a>b;
}
//LL check(){
//	LL maxn=-1;
//	if(!q0.empty()) maxn=max(q0.front(),maxn);
//	if(!qq.empty()) maxn=max(qq.front(),maxn);
//	if(!qqq.empty()) maxn=max(qqq.front(),maxn);
//	if(maxn==q0.front()) q0.pop();
//	else if(maxn==qq.front()) qq.pop();
//	else if(maxn==qqq.front()) qqq.pop();
//	return maxn;
//}

//LL check(LL T){
//	LL x=-1,a=-1,b=-1,c=-1;
//    if (!q0.empty())
//        a=q0.front()+T*q;
//    if (!qq.empty())
//        b=qq.front()+T*q;
//    if (!qqq.empty())
//        c=qqq.front()+T*q;
//    x=max(a,max(b,c));
//    if (x==a)
//        q0.pop();
//    else
//    if (x==b)
//        qq.pop();
//    else
//    if (x==c)
//        qqq.pop();
//    return x;
//}

LL check(LL T){
	LL x=-INF,a=-INF,b=-INF,c=-INF;     //a,b,c���ܸ�-1(��������żӵĻ��� ��Ϊ���������������T*q���п����Ǹ��ģ�����a=-1=x���п��ܵģ�����pop��һ���ն��� 
    if (!q0.empty())
        a=q0.front();
    if (!qq.empty())
        b=qq.front();
    if (!qqq.empty())
        c=qqq.front();
    x=max(max(b,c),a);
    if (x==b)
        qq.pop();
    else
    if (x==c)
        qqq.pop();
    else 
	if (x==a)
        q0.pop();
//    cout<<"���д�С��"<<q0.size()<<" "<<qq.size()<<" "<<qqq.size()<<endl;

    return x+T*q;
}
	

int main(){
	cin>>n>>m>>q>>u>>v>>t; p=u/v;
	
	for(int i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+n+1,cmp);
	for(int i=1;i<=n;i++) q0.push(a[i]);
	
	for(int i=1;i<=m;i++){
		LL maxn=check(i-1);
		
		if(!(i%t)) cout<<maxn<<" ";
		
		LL now1=maxn*p, now2=maxn-now1;
		qq.push(now1-i*q);
		qqq.push(now2-i*q);
//		qq.push(maxn*p-i*q);             //����������д����Ϊmaxn*p�����int��maxn-maxn*p�����int�ǲ�һ����, double*int��double, �м�û���� 
//		qqq.push(maxn-maxn*p-i*q);
	}
	
	cout<<endl;
	for(int i=1;i<=n+m;i++){
		LL x=check(m);
		if(i%t==0) cout<<x<<" ";
	}
}
