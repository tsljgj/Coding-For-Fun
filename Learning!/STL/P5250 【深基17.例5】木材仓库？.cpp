#include<bits/stdc++.h>
using namespace std;
int main(){
	set<int> a;
	int n;
	cin>>n;
	set<int>::iterator sma;//upper_bound(key_value)���������һ�����ڵ���key_value�Ķ�λ��
	set<int>::iterator big;//lower_bound(y) ���ص�һ�����ڵ���y�Ķ�λ�� 
	for(int i=1;i<=n;i++){
		int x,y;
		cin>>x>>y;
		if(x==1){
			if(a.insert(y).second==0) cout<<"Already Exist"<<endl;	
		}
		else{
		if(a.size()){
		
			//if(a.empty()==1/*empty����1˵����*/) cout<<"Empty"<<endl;
//			else{
//				sma=a.lower_bound(y);
				big=a.lower_bound(y);
				sma=big;
//				while(*sma>=y&&sma!=a.begin()) {
//					sma--;
//				}
				if(sma!=a.begin())   //* ʱ��С�ı� 
					sma--;
				if(big!=a.end()&&y-*sma<=*big-y) {//�ж�big��״̬����big 
//					cout<<*sma<<endl;
//					a.erase(sma);//erase(iterator)  ,ɾ����λ��iteratorָ���ֵ
							//erase(first,second),ɾ����λ��first��second֮���ֵ
							//erase(key_value),ɾ����ֵkey_value��ֵ
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
