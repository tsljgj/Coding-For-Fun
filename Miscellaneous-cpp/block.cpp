#include<bits/stdc++.h>
using namespace std;
int main(){
	long long sum=0;
	int n;
	cin>>n;
	string s,t;
	cin>>s>>t;
	for(int i=0;i<n;i++){
		for(int j=i;j<n;j++){      //决定t的区间 
			int f=i;
			for(int p=0;p<s.size();p++){
				if(t[f]==s[p]) f++;
				if(f>j) break;
			}
			if(f>j) sum++;
		}
	}
	cout<<sum<<endl;
	return 0;
}
