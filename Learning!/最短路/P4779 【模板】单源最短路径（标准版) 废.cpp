#include<bits/stdc++.h>
#define MAX 50010              //#...   ��β���ü� ";"    # �Ķ�������using..֮ǰ** 
using namespace std;
const int INF=(1<<30)-1;         // 
int n,m,s;
int dis[MAX]; //��㵽����� 
bool done[MAX];           //�Ƿ��� 
priority_queue<pair<int,int>,vector<pair<int,int> >,greater<pair<int,int> > > a;        //pairҲ��һ������ 
int main(){
	cin>>n>>m>>s;
	
	memset(done,0,sizeof(done));          //��ʼ�� done 
	
	struct edge{
		int next,dis,now;	
	};                                  //struct���Ҫ�� "," 
	
	edge e[100010];
	
//	for(int i=1;i<=n;i++)
//		for(int j=1;j<=n;j++){
//				if(i==j)
//					edge[i].dis=0;
//				else 
//					edge[i].dis=IFN;
//				edge[i].next
//		}              //��ʼ�� edge 

	for(int i=1;i<=n;i++)
		dis[i]=INF;                    //��ʼ�� dis 
		
	dis[s]=0;
		
	for(int i=1;i<=m;i++){
		int x,y,z;
		cin>>x>>y>>z;
		e[i].now=x;
		e[i].next=y;
		e[i].dis=z;
	}
	
	a.push(make_pair(dis[s],s));
	
	while(!a.empty()){
		pair<int,int> u=a.top();
		a.pop();
		int k=u.second;
		if(done[k]) continue;
		done[k]=true;
		
		for(int i=1;i<=m;i++){
//			if(!done[i]&&edge[k][i]<INF/*����*/&&edge[k][i]+dis[k]<dis[i]){
//				dis[i]=edge[k][i]+dis[k];
//				a.push(make_pair(dis[i],i));
//			}
			if(e[i].now==k&&e[i].dis+dis[k]<dis[e[i].next]&&!done[e[i].next]){
				dis[e[i].next]=e[i].dis+dis[k];
				a.push(make_pair(dis[e[i].next],e[i].next));
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
