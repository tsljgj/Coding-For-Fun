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

bool dfs(int stick, int length, int last){    //�Ż�1��last �ݼ��ط���ľ�� 
	if(stick==cnt+1) return true;           //?
	if(length==len) return dfs(stick+1,0,1);
	
	int fail=0;
	for(int i=last;i<=n;i++){
		if(!v[i]&&a[i]+length<=len&&a[i]!=fail){   //�Ż�2��fail ��֮ǰʧ�ܵĳ����ظ�����ʱ�������ظ����� 
			v[i]=1;
			if(dfs(stick,length+a[i],i+1)) return true;
			fail=a[i];
			v[i]=0;
			if(length==0||length+a[i]==len) return false;    //�Ż�3 (1)��һ��ľ������һ��lengthΪ0��ԭʼľ��ʱ�͹��ֱ������ʧ�ܣ���Ϊ������Ҫ���ֻҪ��͹򲻾Ͷ�����
																 // (2)����ǰ�ܷ�����ľ��ʧ��ʱ�������Сľ��Ҳû���� (С�ĸ�������Ķ����ܷţ�������Сľ��������ľ͸��������ں��������� 
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
