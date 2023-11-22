#include<bits/stdc++.h>
using namespace std;
const int MAXN=100020*2, MAXM=2*MAXN;
int n;
int d[MAXN];
int head[MAXN], nxt[MAXM], to[MAXM], val[MAXM], tot1=0;
int trie[MAXN*32][2], tot2=0;         //漏乘32
int ans=0;

void add(int u,int v,int w){
    nxt[++tot1]=head[u], to[tot1]=v, val[tot1]=w, head[u]=tot1;
    nxt[++tot1]=head[v], to[tot1]=u, val[tot1]=w, head[v]=tot1;
}

void dfs(int u,int fa){              //fa是-1没关系 
    for(int i=head[u];i;i=nxt[i]){
        int v=to[i];
        if(v!=fa){
            d[v]=d[u]^val[i];
            dfs(v,u);
        }
    }
}

void insert(int x){
    int p=0;
    for(int i=30;i>=0;i--){
        int u=(x>>i)&1;
        if(!trie[p][u]) trie[p][u]=++tot2;
        p=trie[p][u];
    }
}

int query(int x){
    int p=0, re=0;
    for(int i=30;i>=0;i--){
        int u=(x>>i)&1;
        if(trie[p][!u]){
            p=trie[p][!u];
            re+=(1<<i);
        }
        else{
            p=trie[p][u];
        }
    }
    return re;
}

int main(){
    cin>>n;
    for(int i=1;i<n;i++){
        int u,v,w;
        cin>>u>>v>>w;
        add(u,v,w);
    }
    
    dfs(0,-1);
    
    for(int i=1;i<=n;i++){
        insert(d[i]);
        ans=max(ans,query(d[i]));
    }
    
    cout<<ans<<endl;
    return 0;
    
}
