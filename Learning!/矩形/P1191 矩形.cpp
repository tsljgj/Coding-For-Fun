#include<bits/stdc++.h>  //单调栈怎么做？ 
using namespace std;
int n;
long long sum=0;
int head[200];
stack<int> s;
int main(){
	cin>>n;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			char c;
			cin>>c;
			if(c=='W'){
				head[j]++;
			}
			else head[j]=0;
		}
		
//		while(!s.empty()&&){
//			
//		}
		
		for(int j=1;j<=n;j++){
			int room=head[j];
			
			for(int k=j;k<=n;k++){
				room=min(room,head[k]);
				if(room==0) break;
				else sum+=room;
			}
		}
	}
	cout<<sum<<endl;
	return 0;
}
