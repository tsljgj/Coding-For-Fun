#include<bits/stdc++.h>
using namespace std;
int main(){
	int n,a[20],r;
	cin>>n>>r;
	for(int i=0;i<r;i++){
		a[i]=0;
	}
	for(int i=r;i<n;i++){
		a[i]=1;
	}
	
	do{
		for(int i=0;i<n;i++){
			if(a[i]==0) printf("%3d",i+1);      //3d ռ����λ�����Ҷ���   -3d�������  +3d ������ţ������������� 
		}
		cout<<endl;
	}
	while(next_permutation(a,a+n));  //�ֶ�next-...  �ҳ������׺ 
	return 0;
}
