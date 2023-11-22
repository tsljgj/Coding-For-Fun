#include<bits/stdc++.h>
using namespace std;
deque<long long> d,dd;
int a[1000020];
int main(){
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	

	int head=1;
	for(int i=1;i<=n;i++){
		while(!d.empty()&&d.back()>a[i]){
			d.pop_back();
			dd.pop_back();
		}
		while(!dd.empty()&&dd.front()<head){
			d.pop_front();
			dd.pop_front();
		}
		d.push_back(a[i]);
		dd.push_back(i);
		if(i>=m){
			head++;
			cout<<d.front()<<" ";
		}
	}
	cout<<endl;
	d.clear();
	dd.clear();
	head=1;
	for(int i=1;i<=n;i++){
		while(!d.empty()&&d.back()<a[i]){
			d.pop_back();
			dd.pop_back();
		}
		while(!dd.empty()&&dd.front()<head){
			d.pop_front();
			dd.pop_front();
		}
		d.push_back(a[i]);
		dd.push_back(i);
		if(i>=m){
			head++;
			cout<<d.front()<<" ";
		}
	}
}
