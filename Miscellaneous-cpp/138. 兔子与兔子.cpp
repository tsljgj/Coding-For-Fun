#include<bits/stdc++.h>
using namespace std;
const unsigned long long P=131;
unsigned long long W[1000020], p[1000020];
string s;

void prep(){
    p[0]=1;
    for(int i=0;i<s.size();i++){
        W[i+1]=W[i]*P+s[i]-'a'+1;
        p[i+1]=p[i]*P;
    }
}

unsigned long long cal(int l,int r){
    return W[r]-p[r-l+1]*W[l-1];            //不要忘了前缀和是后一项-前一项的前一项
}

int main(){
    cin>>s;
    prep();
    int m;
    cin>>m;
    while(m--){
        int l1,r1,l2,r2;
        cin>>l1>>r1>>l2>>r2;
        if(cal(l1,r1)==cal(l2,r2)) cout<<"Yes"<<endl;
        else cout<<"No"<<endl;
    }
}
