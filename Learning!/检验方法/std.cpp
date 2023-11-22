#include<bits/stdc++.h>
#define ll long long
#define int long long
#define ljc 998244353
#define gc getchar
#define ull unsigned long long
using namespace std;
inline ll read(){
	ll x=0,f=1;char ch=gc();
	while (!isdigit(ch)){if (ch=='-') f=-1;ch=gc();}
	while (isdigit(ch)){x=x*10ll+ch-'0';ch=gc();}
	return x*f;
}
inline void file(){
	freopen("1","r",stdin);
	freopen("3","w",stdout);
}
struct QWQ{
	int y,m,d;
}ori,tmp,ans[101010],anss[300001];
inline int mabs(int x){return (x>0?x:-x);}
inline bool isr(QWQ a){
	if (a.y<0){
		if ((-a.y-1)%4==0) return 1;
	    else return 0;
	}else if (a.y>=1582){
		if (a.y%400==0) return 1;
		else if (a.y%4==0&&a.y%100) return 1;
		else return 0;
	}else{
		if (a.y%4==0) return 1;
		else return 0;
	}
}
inline QWQ init(int y,int m,int d){
	QWQ x;
	x.y=y,x.m=m,x.d=d;
	return x;
}
const int mon[13]={0,31,28,31,30,31,30,31,31,30,31,30,31};
const int rmon[13]={0,31,29,31,30,31,30,31,31,30,31,30,31};
inline QWQ nextday(QWQ a){
	QWQ ans=a;
	if (a.y==1582){
		if (a.m==12&&a.d==31) ans.y++,ans.d=1,ans.m=1;
		else if (a.m==10&&a.d==4) ans.d=15;
        else if (a.d==mon[a.m]) ans.d=1,ans.m++;
        else ans.d++;
		return ans;
	}
	if (a.y==-1&&a.m==12&&a.d==31){
		ans.y=1,ans.d=1,ans.m=1;	
	}else if (isr(a)){
		if (a.m==12&&a.d==31) ans.y++,ans.d=1,ans.m=1;
		else if (a.d==rmon[a.m]) ans.d=1,ans.m++;
		else ans.d++;
	}else{
		if (a.m==12&&a.d==31) ans.y++,ans.d=1,ans.m=1;
		else if (a.d==mon[a.m]) ans.d=1,ans.m++;
		else ans.d++;
	}
	return ans;
}
struct que{
	int tim,id;
}q[1010101];
inline bool cmp(que a,que b){
	return a.tim<b.tim;
}
int Q;
signed main(){
//	file();
	ori.y=-4713,ori.m=1,ori.d=1;
	Q=read();
	for (int i=1;i<=Q;i++) q[i].id=i,q[i].tim=read();
	sort(q+1,q+1+Q,cmp);
	tmp=ori;
	int mx=0;
	for (int i=1;i<=Q;i++){
		if (q[i].tim>=2451545) break;
		mx=i; 
	}
	for (int i=1,now=0;i<=mx;i++){
		for (;now!=q[i].tim;now++) tmp=nextday(tmp);
		ans[q[i].id]=tmp;
	}
	tmp.d=1,tmp.m=1,tmp.y=2000;
	int cnt=-1;
	for (;tmp.y!=2400;) anss[++cnt]=tmp,tmp=nextday(tmp);
	for (int i=mx+1;i<=Q;i++){
		ans[q[i].id].d=anss[(q[i].tim-2451545)%146097].d;
		ans[q[i].id].m=anss[(q[i].tim-2451545)%146097].m;
		ans[q[i].id].y=anss[(q[i].tim-2451545)%146097].y+400*((q[i].tim-2451545)/146097);
	}
	for (int i=1;i<=Q;i++){
		printf("%lld %lld %lld",ans[i].d,ans[i].m,mabs(ans[i].y));
		if (ans[i].y<0) printf(" BC");
		puts("");
	}
	return 0;
}
