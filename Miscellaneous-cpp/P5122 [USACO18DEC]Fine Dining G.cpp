#include<bits/stdc++.h>  //���Զ����һ����dijk~!!! �~ (һ��㵽һ��������·) 
#define mp make_pair
using namespace std;
int n,m,h;
//int dis[50020][50020]/*���Ϊi,�յ�Ϊj�����·*/; �ᱬ 
int d1[50020],d2[50020];    //dis�ǳ�����,dis2���յ� 
vector<pair<int,int> > a[50020];
//vector<pair<int,int> > hay;
set<pair<int,int> > q;

void dijk(int *dis){	

//	for(int i=1;i<=n;i++) dis[i]=1e30;

 	for(int i=1;i<=n;i++) q.insert(mp(dis[i],i));
 	//һ���������������dijk���Ƕ��һ�٣�����������
	//�����Ҫ��  ������γɵĵ�������dijk(һ��㵽����������·)  ����Ҫ�������е�ÿһ������ǰ��ֵ��һ����� 
	
	while(!q.empty()){
		pair<int,int> u=*q.begin();
		q.erase(q.begin());
		
		for(int j=0;j<a[u.second].size();j++){
			pair<int,int> e=a[u.second][j];
			if(dis[e.first]>e.second+u.first){
				q.erase(mp(dis[e.first],e.first));
				dis[e.first]=e.second+u.first;				
				q.insert(mp(dis[e.first],e.first));
			}
		}
	}
}

int main(){
	cin>>n>>m>>h;
		
	for(int i=1;i<=m;i++){
		int x,y;
		int z;
		cin>>x>>y>>z;
		a[x].push_back(mp(y,z));
		a[y].push_back(mp(x,z));
	}
	
	memset(d1,0x3f,sizeof(d1));
	d1[n]=0;	
	dijk(d1);         //��n��ÿ��������· 
	
	memset(d2,0x3f,sizeof(d1));
	for(int i=1;i<=h;i++){
		int x;
		int y;
		cin>>x>>y;
		d2[x]=d1[x]-y;  //��¼��n��x�������˸ɲݶ�ļ����µ���̾��� 
//		hay.push_back(mp(x,y));
	}
	dijk(d2); //�����иɲݶ⿴����������dijk,�õ����� (��n -> �ɲݶ��� -> ĳһ��) �ľ��� 
				//���ֻҪ�Ƚ�  d2����(n->i�����ɲݶ�����·)  ��  d1����(ԭ��n->i�����·) 
	
	for(int i=1;i<n;i++) cout<<(d1[i]>=d2[i])<<endl;
	
	return 0;
	
	
	
//	int c;
//	cin>>c;
//	int x;
//	for(int i=1;i<=c;i++){
//		cin>>x;
//		cout<<disn[x]<<endl;
//	}
} 
