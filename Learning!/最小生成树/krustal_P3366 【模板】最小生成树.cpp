#include<bits/stdc++.h> 
using namespace std;
pair<int,pair<int,int> > a[200020];
int f[5020],sum=0;
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
	
	int cnt=n-1;       //krustal��ʼ��,��һ����һ�δ���������㣬����Ҫͳ�Ƶ�һ��Ҫn-1 
	
	for(int i=1;i<=n;i++){
		f[i]=i;
	}
	
	for(int i=0;i<m;i++){
		cin>>a[i].second.first>>a[i].second.second>>a[i].first;
	}
	
	sort(a,a+m);
//	cout<<endl;
//	for(int i=0;i<m;i++){
//		cout<<a[i].second.first<<" "<<a[i].second.second<<" "<<a[i].first<<endl;
//	}
	
	for(int i=0;i<m;i++){
		int x=r(a[i].second.first);  //ÿ�ζ����ҵ������������ĸ������õ��ĸ��ᱻ�ֿ�   
		int y=r(a[i].second.second); //1->2, x=1,y=2 -> f[1]=2; 1->3,x=2,y=3 -> f[2]=3
		if(x!=y){ 					//����⣺ÿ�κϲ��Ĳ���ԭ���ݣ�����x��y(�������) 
			f[x]=y;                             
			sum+=a[i].first;
			cnt--;
			if(cnt==0){
				cout<<sum<<endl;
				return 0;
			}
		} 
	}
	
	cout<<"orz"<<endl;
	return 0;
}
