#include<bits/stdc++.h>
//���ڵ���Ϊ1����tot=1;���ڵ���Ϊ0����tot=0 
using namespace std;
const int MAXN=100010;
int trie[MAXN*31][2], tot=1;
int n;
int ans=0;
void insert(int x){
    int p=1;
    for(int i=30;i>=0;i--){          //��д���++ 
        int u=(x>>i)&1;
        if(!trie[p][u]) trie[p][u]=++tot;
        p=trie[p][u];
    }
}
int query(int x){
    int p=1,re=0;
    for(int i=30;i>=0;i--){
        int u=(x>>i)&1;
        if(!trie[p][!u]){
            p=trie[p][u];
        } 
        else {
            re+=(1<<i);
            p=trie[p][!u];
        }
    }
    return re;
}
int main(){
    cin>>n;
    while(n--){
        int x;
        cin>>x;
        insert(x);
        ans=max(ans,query(x));
    }
    cout<<ans<<endl;
    return 0;
}
