#include<bits/stdc++.h>
using namespace std;
void dfs(string in, string post){
	if(in.size()>0){
		char ch=post[post.size()-1];
		cout<<ch;
		int pos=in.find(ch);
		dfs(in.substr(0,pos),post.substr(0,pos));
		dfs(in.substr(pos+1),post.substr(pos,post.size()-1-pos));   //��ȡ�±��pos+1��ʼ���ַ�����β���ַ���
	} 
}
int main(){
	string in,post;
	cin>>in>>post;
	dfs(in,post);
	return 0;
} 
