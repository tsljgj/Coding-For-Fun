#include<bits/stdc++.h>
using namespace std;
int n,m;
double dis[1010];
double x[1010],y[1010];
double a[1010][1010];  //�����������������ͨ�����㣬��dist���жϾ���ʱѭ��m���ж������Ƿ���ͨ���ᳬʱ 
bool done[1010];       //���ö�ά������(�ܵ����٣�������С������������) 
double sum=0;
double dist(int i,int j){
	return hypot(x[i]-x[j],	y[i]-y[j]);
}
int main(){
	cin>>n>>m;
	
	for(int i=1;i<=n;i++){
		cin>>x[i]>>y[i];
	}
	
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			a[i][j]=dist(i,j);
		}
	}
	
	for(int i=1;i<=m;i++){
		int p1,p2;
		cin>>p1>>p2;
		a[p1][p2]=0;
		a[p2][p1]=0;
	}
	
	for(int i=2;i<=n;i++){    //����1���ʱ���������յ���n 
		dis[i]=1e30;
	}
	
	for(int i=0;i<n;i++){
		double minn=1e30;
		int minum=-1;
		for(int j=1;j<=n;j++){
			if(!done[j])
				if(dis[j]<minn) {
					minn=dis[j];
					minum=j;
				}
		}
		
		done[minum]=1;
		sum+=minn;
		
		for(int j=1;j<=n;j++){
			if(!done[j]){
				dis[j]=min(dis[j],a[minum][j]);
			}
		}
	}
	cout<<fixed<<setprecision(2)<<sum<<endl;
	return 0;
}
