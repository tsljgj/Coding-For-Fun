#include<bits/stdc++.h>
using namespace std;
int main(){
	set<int> a;
	int n;
	cin>>n;
	set<int>::iterator sma;//upper_bound(key_value)，返回最后一个大于等于key_value的定位器
	set<int>::iterator big;//lower_bound(y) 返回第一个大于等于y的定位器 
	for(int i=1;i<=n;i++){
		int x,y;
		cin>>x>>y;
		if(x==1){
			if(a.insert(y).second==0) cout<<"Already Exist"<<endl;	
		}
		else{
		if(a.size()){
		
			//if(a.empty()==1/*empty返回1说明空*/) cout<<"Empty"<<endl;
//			else{
//				sma=a.lower_bound(y);
				big=a.lower_bound(y);
				sma=big;
//				while(*sma>=y&&sma!=a.begin()) {
//					sma--;
//				}
				if(sma!=a.begin())   //* 时刻小心爆 
					sma--;
				if(big!=a.end()&&y-*sma<=*big-y) {//判断big的状态再用big 
//					cout<<*sma<<endl;
//					a.erase(sma);//erase(iterator)  ,删除定位器iterator指向的值
							//erase(first,second),删除定位器first和second之间的值
							//erase(key_value),删除键值key_value的值
					big=sma;
				}
				
				if(big==a.end()){
					big--;
					cout<<*big<<endl;
				}
				else{
					cout<<*big<<endl;
				}
				
				a.erase(big);
//				else{
////					cout<<*big<<endl;
////					a.erase(big);
//				}
			}
			else cout<<"Empty"<<endl;
		}
		
	}
} 
