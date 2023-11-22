#include<bits/stdc++.h>
#include<windows.h>
#include<ctime>
#define rank first
#define stri second
using namespace std;
//original data
string a[120]={"adagio","blue","agita","agog","akimbo","alfresco","aloof","ambrosial","amok","aplomb","apogee","apoplectic","appaloosa","apparatus","archipelago","atingle","avuncular","azure","babushka","bailiwick","bafflegab","balderdash","braggadocio","brainstorm","brannigan","cockatoo","derecho","desperado","diaphanous","diddly-squat","digeridoo","dilemma","dillydally","dumbfounded","dumbwaiter","dunderhead","earwig","eavesdrop","ebullient","effervescence","egads","eggcorn","egghead","elixir","ephemeral","epiphany","flotsam","flummery","flummoxed","flyaway","flyspeck","folderol","foofaraw","foolhardy","foolscap","footl","gangway","gargoyle","gasbag","gazebo","gazpacho","gewgaw","genteel","ghostwriter","gibberish","gimcrack","gizmo","gossamer","grandiloquent","greenhorn","guffaw","gumshoe","guru","hoodwink","hooey","hoo","hotbed","hotfoot","hothead","hyperbole","idiom","jubilee","juggernaut","jujubes","jumbo","manifesto","mastermind","mayhem","whizbang","whodunit","whoop","widget","wigwam","willy-nilly","windbag","woozy","xylophone","yahoo","zoom","zydec"};
//list used for ranking
pair<double,string> word[120];
//good words creation
vector<string> new_string;

string new_s;
void prepare(){
	for(int i=0;i<=99;i++) word[i]=make_pair(0,a[i]);        //put every word into sequencing list
}

void rank(double num,int list[],double score){
	if(score>=8) new_string.push_back(new_s);          //if the word seems good, then add to new_string 
	
	double val=(score-5)/(num+1);                     //a special formula to calculate a proper val to add on the score of selected words       
	 
	for(int i=1;i<=num;i++){                         //add the val
		word[list[i]].rank+=val;
	}
	
	for(int i=0;i<=99;i++) {                        //bubble sort
		for(int j=0;j<=98;j++){
			if(word[j]<word[j+1]) swap(word[j],word[j+1]);
		}
	}
}

int main(){
	cout<<"This is a little program which helps people who have naming-phobia."<<endl;
	cout<<"We help you find an ideal name without your brain's working hard."<<endl;
	cout<<"We collect popular words from web and then combine 1 to 2 of them together."<<endl;
	cout<<"We let you score the new-made word, and collect your preference to sequence all the words."<<endl;
	cout<<"Now, decide the showing word interests you or not, and we'll help you pick up a fantastic name after this program."<<endl;
	cout<<"You have to score 20 times."<<endl;
	
	prepare();
	
	for(int i=1;i<=20;i++){
		cout<<endl;
		srand((time(0)));                                      //renew seed
		int wordsNumber=1+rand()%2;                            //random how many words to combine  (<=2)
//		cout<<"wordsNumber="<<wordsNumber<<endl;
		
		int wordChoice[4];   								   //This list records the words being chosed
		bool usedWord[10];                                     //This list records whether each word from top 10 is chosen, to avoid repeat
		memset(usedWord,0,sizeof(usedWord));
		new_s="";
		for(int j=1;j<=wordsNumber;){                          //calculate the new -made word
			srand((time(0)));                                  //renew seed
			int x=rand()%10;                                     //only words ranked <= NO.10 will be chosen, each word can be only chosed one time
			if(usedWord[x]==1) continue;
			
			wordChoice[j]=x;        
			usedWord[x]=1;                     
			new_s=new_s+word[x].stri+" ";
			j++;                                               //if chosen, j++
		}
		cout<<new_s<<endl<<endl;
		
		cout<<"Please score the new-made word: 1-10"<<endl;    //enter score
		int score;
		while(cin>>score&&!(score<=10&&score>=1)){             
			cin.clear();
			cin.sync();
			cout<<"error! please enter again!"<<endl;
		} 
		 		
		rank(double(wordsNumber),wordChoice,double(score));                     //after evaluating some words, rank all the words again
		for(int i=0;i<=99;i++) cout<<word[i].rank<<endl;
	}
	
	cout<<endl<<"This is a list of name you may have great interest:"<<endl<<endl;
	for(int i=0;i<new_string.size();i++) cout<<new_string[i]<<endl;
	
	return 0;
}
