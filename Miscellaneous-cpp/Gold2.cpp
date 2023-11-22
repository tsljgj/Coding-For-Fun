#include<bits/stdc++.h>
using namespace std;
int n, m;
int f[200020];
pair<int, int> c[200020];
int a[200020][4];
int x[200020];
int y[200020];
int F(int x){
	return f[x]!=x? f[x]=F(f[x]) : x;
}

void U(int x, int y)
{
	x = F(x);
	y = F(y);
	f[x] = y;
}

int main(){
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>c[i].first>>a[i][0]>>a[i][1]>>a[i][2]>>a[i][3];
		c[i].second=i;
		for(int j=0; j<2; j++){
			y[a[i][j]]=x[a[i][j]];
			x[a[i][j]]=i;
		}
		for (int j = 2; j < 4; j++){
			y[a[i][j]] = x[a[i][j]];
			x[a[i][j]] = i + n;
		}	
	}
	
	for(int i=1;i<=2*n;i++){
		f[i]=i;
	}
	
	for(int i=1;i<=2*n;i++){
		U(x[i],y[i]);
	}
	sort(c+1,c+1+n);
	int ans=0;
	for(int i=1;i<=n;i++){
		if(F(c[i].second)!=F(c[i].second+n)){
			ans+=c[i].first;
			U(c[i].second,c[i].second+n);
		}
	}
	cout<<ans<<endl;
	return 0;
	
	
}
