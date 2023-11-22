
¡®l#include<bits/stdc++.h>
using namespace std;
int steps, ans;
bool a[10][10],b[10][10];
string s[10];

void display(){
	for(int i=1;i<=5;i++){
		for(int j=1;j<=5;j++){
			cout<<b[i][j];
		}
		cout<<endl;
	}
	cout<<endl;
}
void press(int x,int y){
	b[x][y]^=1;
	b[x+1][y]^=1;
	b[x-1][y]^=1;
	b[x][y+1]^=1;
	b[x][y-1]^=1;
}

bool Res(int x){
	if(x==5){
		for(int i=1;i<=5;i++){
			if(b[5][i]!=1) return 0;
		}
		return 1;
	}
	
	for(int i=1;i<=5;i++){
		if(b[x][i]==0){
			press(x+1,i);
			steps++;
		}
	}
	
//	display();
	 
	return Res(x+1);
}
int main(){
	int n;
	cin>>n;
	while(n--){
		ans=7;
		for(int i=1;i<=5;i++) cin>>s[i];
	 
	for(int i=1;i<=5;i++)
		for(int j=1;j<=5;j++)
			a[i][j]=s[i][j-1]-'0';
	
	for(int i=0;i<32;i++){         //Ñ¡Ò»ÏÂ 
//		cout<<"i="<<i<<endl<<endl;	
		steps=0;
		for(int x=1;x<=5;x++)
			for(int y=1;y<=5;y++) 
				b[x][y]=a[x][y];
			
		for(int j=0;j<5;j++){
//			cout<<"==="<<((i>>j)&1)<<endl;
			if((i>>j)&1==1) {
//				cout<<"press"<<j+1<<endl;
				press(1,j+1);  
				steps++;
			}
		}
		
//		display();
			
		if(Res(1)){
			ans=min(ans,steps);
		}
	}
	
	cout<<(ans<7 ? ans : -1)<<endl;
	}
	
}
