#include<bits/stdc++.h>
using namespace std;
void dfs(string in, string post){
	if(in.size()>0){
		char ch=post[post.size()-1];
		cout<<ch;
		int pos=in.find(ch);
		dfs(in.substr(0,pos),post.substr(0,pos));
		dfs(in.substr(pos+1),post.substr(pos,post.size()-1-pos));   //截取下标从pos+1开始到字符串结尾的字符串
	} 
}
int main(){
	string in,post;
	cin>>in>>post;
	dfs(in,post);
	return 0;
} 
