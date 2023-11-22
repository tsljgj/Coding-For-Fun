#include<bits/stdc++.h>
using namespace std;
int main(){
	int n,a[20],r;
	cin>>n>>r;
	for(int i=0;i<r;i++){
		a[i]=0;
	}
	for(int i=r;i<n;i++){
		a[i]=1;
	}
	
	do{
		for(int i=0;i<n;i++){
			if(a[i]==0) printf("%3d",i+1);      //3d 占三个位置向右对齐   -3d向左对齐  +3d 输出符号（即便是正数） 
		}
		cout<<endl;
	}
	while(next_permutation(a,a+n));  //手动next-...  找长降序后缀 
	return 0;
}
