#include<bits/stdc++.h> 
using namespace std;
pair<int,pair<int,int> > a[100020];
int f[10020],cow[10020],sum=0;
int minn=1e9;

int r(int num){
	if(f[num]==num) return num;
	else{
		f[num]=r(f[num]);
		return f[num];
	}
}
int main(){
	int n,m;
	cin>>n>>m;
	
	int cnt=n-1;       //krustal开始后,第一条边一次处理好两个点，所以要统计点一定要n-1 
	
	for(int i=1;i<=n;i++){
		f[i]=i;
	}
	
	for(int i=1;i<=n;i++){
		cin>>cow[i];
		minn=min(cow[i],minn);
	}
	
	for(int i=1;i<=m;i++){
		cin>>a[i].second.first>>a[i].second.second>>a[i].first;
		a[i].first=a[i].first*2+cow[a[i].second.first]+cow[a[i].second.second];
	}
	
	sort(a+1,a+1+m);
//	cout<<endl;
//	for(int i=0;i<m;i++){
//		cout<<a[i].second.first<<" "<<a[i].second.second<<" "<<a[i].first<<endl;
//	}
	
	for(int i=1;i<=m;i++){
		int x=r(a[i].second.first);  //每次都会找到两个点的最深的根，不用担心根会被分开   
		int y=r(a[i].second.second); //1->2, x=1,y=2 -> f[1]=2; 1->3,x=2,y=3 -> f[2]=3
		if(x!=y){ 					//简单理解：每次合并的不是原数据，而是x和y(求完根后) 
			f[x]=y;                             
			sum+=a[i].first;
			cnt--;
			if(cnt==0){
				cout<<sum+minn<<endl;
				return 0;
			}
		} 
	}
	
	cout<<"orz"<<endl;
	return 0;
}
