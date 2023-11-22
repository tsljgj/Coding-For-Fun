#include<bits/stdc++.h>
using namespace std;
int a[500020];
int main(){
	int n,k;
	cin>>n>>k;
	
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	
	sort(a,a+n);
	
	int t=1;
	int r=0;
	
	while(t){
		int cnt=a[0];    //计数组值 
		int c=0;        //记数组下标 
		r++;
		for(int i=1;i<=k;i++){
			
			while(1){
				c++;
				if(c>=n) {
					t=0;
					break;
				}
				
				if(a[c]>cnt+2*r) {
					cnt=a[c];
					break;
				}
				
			}
			
			if(t==0){
				break;
			}
			
		}
		
		
	}
	cout<<r<<endl;
} 
