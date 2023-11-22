#include<bits/stdc++.h>
using namespace std;
int yy=4713+1,mm=12,dd=31,ru=1,k=0;
int n,r;
int checkyear(int yy1){
	if(ru==1){
		if(yy1%4==0) return 1;
	}
	else{
		if(yy1%400==0||(yy1%4==0&&yy1%100!=0)) return 1;
	}
	
	return 0;
}
int main(){
//	freopen("1","r",stdin);
//	freopen("2","w",stdout);
	int n;
	cin>>n;
	for(int ti=1;ti<=n;ti++){
		cin>>r;
	r+=1;
	
	int a[13]={0,31,28+31,31+59,30+90,31+120,30+151,31+181,31+212,30+243,31+273,30+304,31+334};
	yy=4713+1,mm=12,dd=31,ru=1,k=0;
	
	while(r>355){
		
		if((yy!=1581||k!=0)&&r<365) break;
		
		int t=365;
		if(yy==1581&&k==1) {
			t=355;
			ru=0;
		}
		
		if(k==0){
			if(checkyear(yy-1)==1) t=366;
			yy--;
		}
		else {
			if(checkyear(yy+1)==1) t=366;
			yy++;
		}
		
		r-=t;
		
		if(yy==0) {
			yy=1;
			k=1;
		}
			
			
	}
	
	if(k==0){
		if(checkyear(yy-1-1)==1){
			for(int i=2;i<=12;i++) a[i]++;
		}
	}
	else{
		if(checkyear(yy+1)==1) {
			for(int i=2;i<=12;i++) a[i]++;
		}
	}
	
	if(yy==1581&&k==1){
		a[10]-=10;
		a[11]-=10;
		a[12]-=10;
		
		for(int j=0;j<=11;j++){
			if(r>a[j]&&r<=a[j+1]) {
				mm=j+1;
				r-=a[j];
				if(mm==10){
					if(r>4) dd=r+10;
				}
				else dd=r;
				break;
			}
		}
		
	}
	
	for(int j=0;j<=11;j++){
		if(r>a[j]&&r<=a[j+1]) {
			mm=j+1;
			r-=a[j];
			dd=r;
			break;
		}
	}
	
	if(k==0)
		cout<<dd<<" "<<mm<<" "<<yy-1<<" "<<"BC"<<endl;
	if(k==1)
		cout<<dd<<" "<<mm<<" "<<yy+1<<endl;
		
	}
	
	return 0;	
} 
