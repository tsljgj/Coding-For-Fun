#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[100][100];
int z[6]={2,1,0,0,0,0}, s[6]={6,6,6,6,5,4};
int maxx=0, maxy=0;
char c1[10][10]={
	"  +---+",
	" /   /|",
	"+---+ |",
	"|   | +",
	"|   |/",
	"+---+",
};
char c[1001][1001];

void add(int x,int y){
	for(int i=5;i>=0;i--){
		for(int j=z[i];j<=s[i];j++){
			c[5-i+x][j+y]=c1[i][j];
			maxx=max(maxx,5-i+x);
			maxy=max(maxy,j+y);
		}
	}
}
int main(){
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		for(int j=0;j<m;j++){
			cin>>a[i][j];
		}
	}
	
	for(int o=1;o<=n;o++){
		for(int k=0;k<m;k++){
			for(int l=0;l<a[o][k];l++){
				int x=(n-o)*2+l*3+1, y=1+k*4+(n-o)*2;
				add(x,y);
			}
		}
	}
	
	for(int i=maxx;i>=1;i--){
		for(int j=1;j<=maxy;j++){
			if(c[i][j]=='\000') cout<<".";
			else cout<<c[i][j];
		}
		cout<<endl;
	}
	
	
}
