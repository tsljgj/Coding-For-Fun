#include<bits/stdc++.h>
using namespace std;
int n,m;
bool done;
vector<int> a[100020];           //a[i][j] �ǵ�iΪ��㣬��j-1���ߵ��յ� 
vector<int> b;                 //���յ���ˮ�� 
unsigned long long tfenmu[100020],tfenzi[100020];

//double test[100020];
//void dfs(int i){
//	if(a[i].size()==0){
//		return;
//	}
//	else{
//		for(int j=0;j<a[i].size();j++){
//			test[a[i][j]]=test[i]/double(a[i].size());
//			dfs(a[i][j]);
////			test[a[i][j]]=0;
//		}
//	}
//	
//}

long long gcd(int i,int j){
	while(1){
		if(i%j==0){
			return j;
		}
		long long t=j;
		j=i%j;
		i=t;	
	}
}
void cal(int now,int next){
//	a[now].size()
//	tfenzi[now]
//	tfenmu[now]
//	tfenzi[next]
//	tfenmu[next]
	if(tfenzi[next]==0){
		tfenzi[next]=tfenzi[now];
		tfenmu[next]=tfenmu[now]*a[now].size();
	}
	else{
		tfenzi[next]=tfenzi[now]*tfenmu[next]+tfenzi[next]*tfenmu[now]*a[now].size();
		tfenmu[next]=tfenmu[now]*a[now].size()*tfenmu[next];
	}
	
	long long g=gcd(tfenzi[next],tfenmu[next]);
	tfenzi[next]=tfenzi[next]/g;
	tfenmu[next]=tfenmu[next]/g;
	
	return;
	
}
int main(){

	cin>>n>>m;
	for(int i=1;i<=n;i++){        //��iǰ���ĵ� 
		int x;
		cin>>x;                  //��x�� 
		if(x==0) {                 //ͳ���յ���ˮ�� 
			b.push_back(i);
		}
		else{
			for(int j=1;j<=x;j++){
				int y;
				cin>>y;                     //ǰ���ĵ�ı�� 
				a[i].push_back(y);
			}
		}
		
	}
	
	if(b.size()==1) {        //������� 
		cout<<1<<endl;
		return 0;
	}
	
	for(int i=1;i<=m;i++){          //��ʼ�� 
		tfenzi[i]=1;
		tfenmu[i]=1;
	}
	
	for(int k=1;k<=11;k++){          //������ 
		
		done=1;                     //���Ƿ������� 
		
		for(int i=1;i<=n;i++){        
			
			if(a[i].size()!=0&&tfenmu[i]!=0){
				done=0;
				
				for(int j=0;j<a[i].size();j++){
//					test[a[i][j]]+=test[i]/double(a[i].size());
					cal(i,a[i][j]);
//					cout<<a[i][j]<<"�ŵ�:"<<test[a[i][j]]<<endl;
				}
				
				tfenzi[i]=0;
				tfenmu[i]=0;
			}
			
		}
		
		if(done==1) break;
	}
	
	
	
	for(int i=0;i<b.size();i++){
		cout<<tfenzi[b[i]]<<" "<<tfenmu[b[i]]<<endl;
	}
	return 0;
}
