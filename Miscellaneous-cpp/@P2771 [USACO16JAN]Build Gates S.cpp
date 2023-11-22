#include<bits/stdc++.h>
using namespace std;
bool p[2010][2010];               //全局变量在堆上，局部变量在栈上，局部容量<全局,小心爆栈，一般递归 
int main(){
	int n;
	cin>>n;
	vector<pair<pair<int,int>,pair<int,int> > > s;
	
	p[1010][1010]=1;                 //有可能有负的坐标啊啊啊 
	int side=0,point=1;
	
	int x=1010,y=1010;
	for(int i=1;i<=n;i++){
		char a;
		cin>>a;
		int x1=x,y1=y;
		if(a=='N') y++;        //字符是'' 
		if(a=='S') y--;
		if(a=='W') x--;
		if(a=='E') x++;
		
		int k=1;
		if(p[x][y]==0) {
			point++;
			p[x][y]=1;
		}
		else{
			for(int j=0;j<s.size();j++){
				if((s[j].first.first==x1&&s[j].first.second==y1&&s[j].second.first==x&&s[j].second.second==y)||(s[j].first.first==x&&s[j].first.second==y&&s[j].second.first==x1&&s[j].second.second==y1)){
					k=0;
					break;
				}
			}	
		}
		
		if(k==1) {
				side++;
				s.push_back(make_pair(make_pair(x1,y1),make_pair(x,y)));
			}
		
//		cout<<point<<" "<<side<<endl;
			
	}
	cout<<side-point+1<<endl;
	return 0; 

}
