#include<bits/stdc++.h> //����ɸ��ö�������ñ�����������,ŷ��ɸ��ö�ٺ�������֪��������� 
using namespace std;   //ŷ��ɸ�ľ���������ö�ٵ��ĺ�����ĳ��֪�����ı���(��������С������),��ô��ֹͣ������֪��������� 
int n,t=0;            //why correct? ���һ��ö�ٵ��ĺ�������С��������֪,��ô�ú���=p*a(pΪ��С������)һ�����ں���ö�ٵ�aʱ��p��˵õ����ʲ���Ҫ������ 
int prime[10000];    //ͬ��,��С������֮���������Ҳ����Ҫ������,����ֱ��break 
int num[10000]; 
int main(){
	cin>>n;
	for(int i=2;i<=n;i++) num[i]=1;
	for(int i=2;i<=n;i++){
		if(num[i]) {
			prime[++t]=i;      //����ش�ֵ  t++:�ش���� 	
		}
		
		for(int j=1;j<=t&&i*prime[j]<=n;j++){
			num[i*prime[j]]=0;
			if(i%prime[j]==0) break;      //������ͷ 
		}
		
	}
	
	for(int i=2;i<=n;i++) {
		if(num[i]) cout<<i<<endl;
	}
		
}
