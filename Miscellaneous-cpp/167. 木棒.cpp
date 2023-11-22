#include<bits/stdc++.h>
using namespace std;
const int MAXN=1020;
int n;
int a[MAXN], v[MAXN], fail;
int len,cnt;
int sum=0;

bool cmd(int a,int b){
	return a>b;
}

bool dfs(int stick, int length, int last){    //优化1：last 递减地放入木块 
	if(stick==cnt+1) return true;           //?
	if(length==len) return dfs(stick+1,0,1);
	
	int fail=0;
	for(int i=last;i<=n;i++){
		if(!v[i]&&a[i]+length<=len&&a[i]!=fail){   //优化2：fail 当之前失败的长度重复出现时，不再重复搜索 
			v[i]=1;
			if(dfs(stick,length+a[i],i+1)) return true;
			fail=a[i];
			v[i]=0;
			if(length==0||length+a[i]==len) return false;    //优化3 (1)当一个木块填入一个length为0的原始木块时就跪就直接宣告失败，因为反正都要填，它只要填就跪不就都跪了
																 // (2)当当前能放入的最长木块失败时，后面的小木块也没用了 (小的更灵活，连大的都不能放，用灵活的小木块填完后大的就更不可能在后面填上了 
		}
	}
	
	return false;
}
int main(){
	while(cin>>n&&n){
		sum=0;
		for(int i=1;i<=n;i++) cin>>a[i], sum+=a[i]; 
		sort(a+1,a+n+1,cmd);
		int maxn=a[1];
		for(len=maxn;len<=sum;len++){
			if(sum%len) continue;
			cnt=sum/len;
			memset(v,0,sizeof(v));
			if(dfs(1,0,1)) {
				cout<<len<<endl;
				break;
			}
		}
	}
}
