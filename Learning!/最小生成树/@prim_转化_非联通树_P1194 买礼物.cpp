#include<bits/stdc++.h>
#define mp make_pair
using namespace std;
vector<pair<int,int> > a[520];
int dis[520],sum=0;
int main(){
	int A,n;
	cin>>A>>n;
	for(int i=1;i<=n;i++) dis[i]=10000;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			int x;
			cin>>x;
			if(x==0||x>=A) x=10000;
			a[i].push_back(mp(j,x));
		}
	}
	bool done[520];
	// memset(done,0,sizeof(done));
	for(int i=1;i<=n;i++){
		done[i]=0;
	}

	int minn;
	int minum;
	int cnt=n;
	while(cnt>0){
		for(int i=1;i<=n;i++){         //找尚未买到的点
			if(!done[i]) { 
				minum=i;           //确立下一个起始点
				done[i]=1;
				cnt--;
				sum+=A;
				break;
			}
		}

		while(1){
			for(int j=0;j<a[minum].size();j++)               //更新图到各未到点的距离
				if(!done[a[minum][j].first])
					dis[a[minum][j].first]=min(dis[a[minum][j].first],a[minum][j].second);
		
			minn=10000;
			minum=-1;

			for(int j=1;j<=n;j++){             //find next point to expand
				if(dis[j]<minn&&done[j]==0){
					minn=dis[j];
					minum=j;
				}
			}

			if(minum==-1) break;

			done[minum]=1;
			cnt--;
			sum+=minn;
		}
		

	}
	
	cout<<sum;
}
