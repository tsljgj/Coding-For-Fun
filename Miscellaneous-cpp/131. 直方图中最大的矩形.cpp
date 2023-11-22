#include<bits/stdc++.h>
using namespace std;
int a[100020], b[100020], width[100020];
int p;
int n;
long long ans=0;
int main(){
	while(cin>>n,n){
	    b[n+1]=0, p=0, a[0]=-1, ans=0;                   //防止最后全是单调而没有计算答案
	    for(int i=1;i<=n;i++) cin>>b[i];
	    for(int i=1;i<=n+1;i++){
	        if(b[i]>a[p]){               //但凡长度<=栈顶都合并一下
	            a[++p]=b[i];
	            width[p]=1;
	        }
	        else{
	            int sum=0;
	            while(a[p]>=b[i]){
	            	sum+=width[p];
//	                ans=max(ans,(long long)a[p]*width[p]);
					ans=max(ans,(long long)a[p]*sum);                  //这里在计算前面的最大值 ，正因为是单调队列，所以直接拿当前项*计算到>=当前项的数量比大小即可 
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
