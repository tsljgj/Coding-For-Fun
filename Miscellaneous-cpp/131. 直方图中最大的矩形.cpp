#include<bits/stdc++.h>
using namespace std;
int a[100020], b[100020], width[100020];
int p;
int n;
long long ans=0;
int main(){
	while(cin>>n,n){
	    b[n+1]=0, p=0, a[0]=-1, ans=0;                   //��ֹ���ȫ�ǵ�����û�м����
	    for(int i=1;i<=n;i++) cin>>b[i];
	    for(int i=1;i<=n+1;i++){
	        if(b[i]>a[p]){               //��������<=ջ�����ϲ�һ��
	            a[++p]=b[i];
	            width[p]=1;
	        }
	        else{
	            int sum=0;
	            while(a[p]>=b[i]){
	            	sum+=width[p];
//	                ans=max(ans,(long long)a[p]*width[p]);
					ans=max(ans,(long long)a[p]*sum);                  //�����ڼ���ǰ������ֵ ������Ϊ�ǵ������У�����ֱ���õ�ǰ��*���㵽>=��ǰ��������ȴ�С���� 
	                p--;
	            }
	            a[++p]=b[i];
	            width[p]=sum+1;
	        }
	    }
	    cout<<ans<<endl;
	}
    return 0;
}
