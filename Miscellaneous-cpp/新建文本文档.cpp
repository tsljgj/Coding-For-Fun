#include<bits/stdc++.h>
#define mp make_pair
#define pi pair<int,int> 
using namespace std;
set<pi > q;
vector<pi > a[400020];
int dis[2500];
int main(){
    int n;
    cin>>n;
    for(int i=1;i<=n;i++){
        int x,y,z;
        cin>>x>>y>>z;
        a[x].push_back(mp(y,z));
        a[y].push_back(mp(x,z));
    }

    for(int i=1;i<=n;i++) dis[i]=1e30;

    dis[1]=0;
    q.insert(mp(dis[1],1));

    while(!q.empty()){
        pi u=*q.begin();
        q.erase(q.begin());

        if(u.first>dis[u.second]) break;

        for(int i=0;i<a[u.second].size();i++)){
            pi e=a[u.second][i];

            if()
        }
    }
}