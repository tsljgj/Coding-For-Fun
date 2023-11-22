#include<bits/stdc++.h>
using namespace std;
int n,m;
long long a[100020];    //ԭʼ���� 
long long sum[262143]; //Ҷ�ӽڵ�n�������log2(n)+1,�ܸ���2^(log2(n)+1)-1 ,���ʱ����Խ�log2(n)�������Ȼ��ȡ�컨�� 
long long la[262143];   //��� 
void build(int i,int l,int r){
	if(l==r){
		sum[i]=a[l];       //a[l]����a[i]������������������ 
		return;
	}
	int mid=(l+r)/2;
	build(i*2,l,mid);
	build(i*2+1,mid+1,r);
	sum[i]=sum[i*2]+sum[i*2+1];
}

void add(int i,int l,int r,long long k){
	sum[i]+=(r-l+1)*k;
	la[i]+=k;
	return;
}

void push(int i,int l,int r){
	int mid=(l+r)/2;            
	add(i*2,l,mid,la[i]);      //�Ѹ��ڵ������ֵ���µ��ӽڵ�ȥ�������ӽڵ�̳и���� 
	add(i*2+1,mid+1,r,la[i]);   //�±��ֱ����change��󴫣��˴�ֻ��������´������ 
	
	la[i]=0;                 //��Ǵ��в���֮��Ǻͼ��뵽�ӽڵ��к��Ǿ�������
	return;
}

void change(int i,int l,int r,int L,int R,long long k){    //L~R��Ҫ�ĵ����䣬l~r���������� 
	if(L>r||R<l) return; //*д�� //���������������ȫ����Ҫ�޸ĵ���������return 
	if(L<=l&&r<=R){     //**д�� //����������������޸ĵ���������ֱ��sum��,�ӱ�ǣ�return 
//		add(i,l,r,k);
		sum[i]+=(r-l+1)*k;
		la[i]+=k;       //���Ҫ�ۼ� 
		return;
	}
	
//	if(L>=l||R<=r){     //������������򲿷���Ҫ�޸ĵ�������(�ɲ�дif) 
//		
//	}
	
//	int mid=(l+r)/2;             
//	add(i*2,l,mid,la[i]);       
//	add(i*2+1,mid+1,r,la[i]);
//	la[i]=0;                 //�±�Ǵ��в���֮ǰ�����ͼ��뵽�ӽڵ��к��Ǿ������� 
	
	push(i,l,r);    //�滻����һ�� 
	
	int mid=(l+r)/2;
	change(i*2,l,mid,L,R,k);          //�������� 
	change(i*2+1,mid+1,r,L,R,k);
	sum[i]=sum[i*2]+sum[i*2+1];                //����ֱ����Ͷ�����������Ϊ�п������䲿�ֱ��޸���
	return;											//���ֻ�����ӽڵ�ȫ�����޸��� 
}

long long query(int i,int l,int r,int L,int R){
	if(L<=l&&r<=R){    //д�� 
		return sum[i];
	}
	
	if(r<L||R<l) return 0;  //д���˴��ر�С�� 
	
	push(i,l,r);   //change��query����Ҫ�����������˲�push��� 
	
	int mid=(r+l)/2;
	return query(i*2,l,mid,L,R)+query(i*2+1,mid+1,r,L,R);
}
int main(){
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	build(1,1,n);
	
	for(int i=1;i<=m;i++){
		int o;
		cin>>o;
		if(o==1) {
			int x,y;
			long long k;
			cin>>x>>y>>k;
			change(1,1,n,x,y,k);
		}
		else{
			int x,y;
			cin>>x>>y;
			cout<<query(1,1,n,x,y)<<endl;
		}
	}
	return 0;
}
