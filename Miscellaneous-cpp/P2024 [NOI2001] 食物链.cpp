#include<bits/stdc++.h>
using namespace std;
const int N=5*10020, K=100020;
int n,k;
int f[N*3];
int ans=0;
int advfind(int x){
	if(f[x]==x) return x;
	return f[x]=advfind(f[x]);
}

void U(int x,int y){
	int X=advfind(x);
	int Y=advfind(y);
	if(X!=Y) f[X]=Y; 
}

int find(int x){
	if(f[x]==x) return x;
	return find(f[x]);
}

int main(){
	cin>>n>>k;
	for(int i=1;i<=3*n;i++) f[i]=i;
	
	for(int i=1;i<=k;i++){
		int op,x,y;
		cin>>op>>x>>y;
		
		if(x>n||y>n){
			ans++;
//			cout<<ans<<endl;
			continue;
		}
		
		if(op==1){
			if(x==y) continue;
					
			int a,b,c;
				
			int X=advfind(x), X2=advfind(x+n), X3=advfind(x+n+n);
			a=f[X], b=f[X2], c=f[X3];
			
			int Y=advfind(y);
			f[X]=Y;
			int Y2=find(y+n);
			f[X2]=Y2;
			int Y3=find(y+n+n);
			f[X3]=Y3;
					
			if(find(x)==find(x+n)) {
				ans++;
//				cout<<ans<<endl;
				f[X]=a;
				f[X2]=b;
				f[X3]=c;
			}
			
		}
		else{
			if(x==y) {
				ans++;
//				cout<<ans<<endl;
				continue;
			}
			
			int X=advfind(x), Y=advfind(y), Z=advfind(x+n);
			
			int a=f[X], b=f[Y], c=f[Z];
			
			int A=advfind(y+n);
			f[X]=A;
			int B=find(x+n*2);
			f[Y]=B;
			int C=find(y+2*n);
			f[Z]=C;
						
			if(find(x)==find(x+n)){
				ans++;
//				cout<<ans<<endl;
				f[X]=a;
				f[Y]=b;
				f[Z]=c;
			}
		}
	}
	
	cout<<ans<<endl;
	return 0; 
}
