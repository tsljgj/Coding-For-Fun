#include<bits/stdc++.h>
using namespace std;
const int MAXN=50;
int a[500], g[500];
int n,m;
int f[MAXN][MAXN][MAXN][MAXN];
int main(){
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=m;i++){
		int x;
		cin>>x;
		g[x]++;
	}
	
	f[0][0][0][0]=a[1];
	for(int i=0;i<=g[1];i++){
		for(int j=0;j<=g[2];j++){
			for(int p=0;p<=g[3];p++){
				for(int q=0;q<=g[4];q++){
					if(i) f[i][j][p][q]=max(f[i][j][p][q],f[i-1][j][p][q]+a[i+j*2+p*3+q*4+1]);
					if(j) f[i][j][p][q]=max(f[i][j][p][q],f[i][j-1][p][q]+a[i+j*2+p*3+q*4+1]);
					if(p) f[i][j][p][q]=max(f[i][j][p][q],f[i][j][p-1][q]+a[i+j*2+p*3+q*4+1]);
					if(q) f[i][j][p][q]=max(f[i][j][p][q],f[i][j][p][q-1]+a[i+j*2+p*3+q*4+1]);
				}
			}
		}
	}
	
	cout<<f[g[1]][g[2]][g[3]][g[4]]<<endl;
	return 0;
} 
