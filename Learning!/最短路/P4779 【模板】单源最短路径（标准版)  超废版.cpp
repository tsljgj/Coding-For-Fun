#include<bits/stdc++.h>
#define MAX 5010              //#...   ��β���ü� ";"    # �Ķ�������using..֮ǰ** 
using namespace std;
const int INF=1<<30-1;
int n,m,s;
int dis[MAX],edge[MAX][MAX]; //��㵽����룬�����⵽����� 
bool done[MAX];           //�Ƿ��� 
priority_queue<pair<int,int>,vector<pair<int,int> >,greater<pair<int,int> > > a;        //pairҲ��һ������ 
int main(){
	cin>>n>>m>>s;
	
	memset(done,0,sizeof(done));          //��ʼ�� done 
	
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++)
			i==j ? edge[i][j]=0 : edge[i][j]=INF;              //��ʼ�� edge 
	
	for(int i=1;i<=n;i++)
		dis[i]=edge[s][i];                    //��ʼ�� dis 
		
	for(int i=1;i<=m;i++){
		int x,y,z;
		cin>>x>>y>>z;
		edge[x][y]=z;
		edge[y][x]=z;
	}
	
	a.push(make_pair(dis[s],s));
	
	while(!a.empty()){
		pair<int,int> u=a.top();
		a.pop();
		int k=u.second;
		if(done[k]) continue;
		done[k]=true;
		
		for(int i=1;i<=n;i++){
			if(!done[i]&&edge[k][i]<INF/*����*/&&edge[k][i]+dis[k]<dis[i]){
				dis[i]=edge[k][i]+dis[k];
				a.push(make_pair(dis[i],i));
			}
		}
		
	}
	
	for(int i=1;i<=n;i++){
		cout<<dis[i]<<" ";
	}
	
//	for(int i=1;i<=n;i++){
//		cout<<"dis[i]="<<dis[i]<<endl;
//		for(int j=1;j<=n;j++){
//			cout<<"i��j:"<<edge[i][j]<<" ";
//		}
//		cout<<endl;
//	}	
	
	return 0;
}
