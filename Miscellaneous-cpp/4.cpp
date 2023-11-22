#include<bits/stdc++.h>
#define rank first
#define stri second
using namespace std;
typedef unsigned long long ull;

string a[4][120]={{},{},{},{}};

pair<ull,string> word[4][120];

int groupNumber;

int main(){
	cout<<"This is a little program which helps people who have naming-phobia."<<endl;
	cout<<"We help you find an ideal name without your brain's working hard."<<endl;
	cout<<"We collect popular words from web and then combine 2 to 3 of them together."<<endl;
	cout<<"We let you choose the new-made word, and collect your preference to sequence all the words."<<endl;
	cout<<"Now, first decide which humor do you belong to?"<<endl;
	cout<<"1.Melancholic-thoughtful&sad"<<endl<<"2.Phlegmatic-cool&calm"<<endl<<"3.Choleric-brave&clinging"<<endl<<"4.Sanguine-simple&zealous"<<endl;
	
	while(cin>>groupNumber&&!(groupNumber<=4&&groupNumber>=1)){          //enter word groupNumber
		cin.clear();
		cin.sync();
		cout<<"error! please enter again!"<<endl;
	
	} 
	cout<<"Now, decide the showing word interests you or not, and we'll help you pick up a fantastic name after this program"<<endl;
	cout<<"You have to choose 100 times"<<endl;
	
	for(int i=0;i<=99;i++) word[groupNumber][i]=make_pair(0,a[i]);        //put every word into sequencing list
	
	for(int i=1;i<=n;i++){
		srand((time(0)));                                      //renew seed
		int wordsNumber=1+rand()%3;                            //random how many words to combine
		
		for(int j=1;j<=wordsNumber;j++){                       //print the new -made word
			srand((time(0)));                                  //renew seed
			cout<<word[groupNumber][rand()%10]<<" ";           //only words ranked <= NO.10 will be chosen 
		}
		
		cout<<"Please score the new-made word: 1-10"<<endl;    //enter score
		int score;
		while(cin>>score&&!(score<=10&&score>=1)){             
			cin.clear();
			cin.sync();
			cout<<"error! please enter again!"<<endl;
		} 
		
		word[groupNumber]
	}
	
	
	
	
}
