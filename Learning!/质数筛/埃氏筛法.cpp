#include<bits/stdc++.h>
using namespace std;
int n;
bool b[100000];
int main(){
	cin>>n;
	for(int i=2;i<=n;i++) b[i]=1;
	for(int i=2;i<=n;i++){
		
		if(b[i]){
			for(int j=i;j*i<=n;j++){  //j=i����Ϊ: i֮ǰ����(a),��������or����,�Ѿ�����Ϊ������֮ǰ��ö��������� 
				b[j*i]=0;             //����(5): 5*4 ��2*10ʱ���, 5*3 ��3*5ʱ��� 
			}
		}
		
	}
	
	for(int i=2;i<=n;i++){
		if(b[i]) cout<<i<<endl;
	}
}
