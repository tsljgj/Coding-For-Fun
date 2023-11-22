#include<bits/stdc++.h>
#define d first
#define p second
using namespace std;
const int MAXN=10020;
int n;
pair<int,int> g[MAXN];
int tree[MAXN];
int num=0;
long long ans=0;
void insert(int x){
	tree[++num]=x;
	int p=num;
	while(tree[p/2]>x&&p>0) {
		swap(tree[p/2],tree[p]);
		p/=2;
	}
}

void down(int p){
	int s=p*2;
	while(s<=n){
		if(s<n&&tree[s+1]<tree[s]) s++;
		if(tree[s]<tree[p]) swap(tree[s],tree[p]), p=s, s=p*2;
		else break;
	}
}
void extract(){
	tree[1]=tree[num--];
	down(1);
}
int main(){
	while(cin>>n){
		ans=0;
		num=0;
		for(int i=1;i<=n;i++){
			cin>>g[i].p>>g[i].d;
		}
		sort(g+1,g+n+1);
		
		for(int i=1;i<=n;i++){
			if(g[i].d==num){
				if(tree[1]<g[i].p) {
					ans+=g[i].p-tree[1];
					extract();
					insert(g[i].p);
				}
			}
			else {
				insert(g[i].p);
				ans+=g[i].p;
			}
		}
		
		cout<<ans<<endl;
		
	}
}
