#include<bits/stdc++.h>
using namespace std;
int n;
int head[520],tail[520];
long long sum=0;
int main(){
	cin>>n;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			int x;
			cin>>x;
			if(x>=100) head[j]++;
			if(x<100) head[j]=0;
			if(x==100) tail[j]=i;
		}
		
		for(int j=1;j<=n;j++){
			int maxh=head[j],mint=tail[j];
			for(int k=j;k<=n;k++){
				maxh=max(maxh,head[j]);
				mint=min(mint,tail[j]);
				sum+=maxh-mint+1;
			}
		}
	}
	cout<<sum<<endl;
	return 0;
}
