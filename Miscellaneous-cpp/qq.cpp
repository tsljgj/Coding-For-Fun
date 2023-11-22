#include<bits/stdc++.h>
#include<ctime>
#include<random>
using namespace std;
int main(){
	std::random_device e;
	std::uniform_real_distribution<double> u(0,1); 
	for(int i=1;i<=100;i++){
		cout<<fixed<<setprecision(0)<<u(e)*10000000000<<endl;
	}
	return 0;
//	int n=0;
//	srand(time(0));
//	while(n<=10){
//		n++;
//		long long a=rand()%(999999999-100000000+1)+100000000;
//		cout<<a<<endl;
//	}
//	
//	return 0;
}
