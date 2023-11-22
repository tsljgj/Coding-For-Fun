#include<bits/stdc++.h>//levmaxo[i]为第i层循环的最大复杂度 
//10
//F 1 n
//F 1 2
//F 1 3
//F 3 2
//F 1 n
//E
//E
//E
//E
//E
using namespace std;
int T,L;
string ans0;
int levmaxo[200], mione[200];

int cbiggerd(string x,string y){
	if(x.size()<y.size()) return 0;
	if(x.size()>y.size()) return 1;
	for(int i=0;i<x.size();i++){
		if(x[i]>y[i]) return 1;
		else if(x[i]<y[i]) return 0;
	}
}

int main(){
	cin>>T;
	while(T--){
//		cin>>L>>ans0;
		cin>>L;
		int level=0,lresume=1e9;
		memset(levmaxo,0,sizeof(levmaxo));
		memset(mione,0,sizeof(mione));
		for(int i=1;i<=L;i++){
			string a,b,c,d;
			cin>>a;
			if(a=="F"){
				cin>>c>>d;
				if(lresume<1e9){
					level++;
					cout<<"level:"<<level<<endl;
					continue;
				}
				else if(c!="n"&&d=="n") {
					level++;
					cout<<"level:"<<level<<endl;
				}
				else if((c=="n"&&d!="n")||(c!="n"&&d!="n"&&cbiggerd(c,d))){
					level++;
					lresume=level;
					cout<<"lresume:"<<lresume<<endl;
					cout<<"level:"<<level<<endl;
				}
				else if(c!="n"&&d!="n"&&!cbiggerd(c,d)){
					level++;
					mione[level]=1;
					cout<<"mione"<<level<<":"<<mione[level]<<endl;
					cout<<"level:"<<level<<endl;
				}
			}
			else if(a=="E"){
				if(lresume<=level){
					if(lresume==level) lresume=1e9;
					level--;
					cout<<"level:"<<level<<endl;
					continue;
				}
				levmaxo[level]=max(levmaxo[level],levmaxo[level+1]+1-mione[level]);
				mione[level]=0;
				
				cout<<"levmaxo"<<level<<": "<<levmaxo[level]<<endl;
				levmaxo[level+1]=0;
				level--;	
	//			cout<<"level:"<<level<<endl;
			}
			
		}
		
		stringstream ss;
		int ss0;
		ss<<ans0.substr(4,ans0.size()-5);
		ss>>ss0;
		if(ans0[2]=='n'&&ss0==levmaxo[1]) cout<<"Yes"<<endl;
		else if(ans0[2]!='n'&&levmaxo[1]==0) cout<<"Yes"<<endl;
		else cout<<"No"<<endl;
	}
}
