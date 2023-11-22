#include<bits/stdc++.h>
using namespace std;
int main(){
	vector<long long> a;
	for(int i=1;i<=10;i++)
		a.push_back(i);
	sort(a.begin(),a.end(),greater<int>());
	cout<<a[2-1];
//	for(int i=0;i<=9;i++){
//		cout<<a[i]<<endl;
//	}
}
