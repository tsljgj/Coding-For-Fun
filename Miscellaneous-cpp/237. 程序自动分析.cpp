#include<bits/stdc++.h>
#define mp make_pair
#define fi first
#define se second
using namespace std;
int t;
pair<pair<int,int>,int>  a[100020];
int b[200020],tot;
int f[200020];

int get(int x){
    if(f[x]==x) return x;
    else return f[x]=get(f[x]);
}

int findx(int x){
    for(int i=1;i<tot;i++){
        if(b[i]==x) return i;
    }
}

int main(){
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        tot=0;
        for(int i=1;i<=200020;i++){
            f[i]=i;
        }
        
        for(int k=1;k<=n;k++){
            int i,j,e;
            cin>>i>>j>>e;
            a[k]=mp(mp(i,j),e);
            b[++tot]=i;
            b[++tot]=j;
        }
        
        sort(b+1,b+tot+1);
        tot=unique(b+1,b+tot+1)-b;
        
//        for(int i=1;i<tot;i++) cout<<b[i]<<endl;
        
        for(int k=1;k<=n;k++){
            if(a[k].se==1){
//            	cout<<tot<<endl;
//            	cout<<a[k].fi.fi<<endl;
//            	cout<<findx(a[k].fi.fi)<<" "<<findx(a[k].fi.se)<<endl;
                f[findx(a[k].fi.fi)]=findx(a[k].fi.se);
            }
        }
        
//        for(int i=1;i<tot;i++) cout<<f[i]<<endl;
        
        bool ppp=1;
        for(int k=1;k<=n;k++){
            if(a[k].se==0){
                if(get(findx(a[k].fi.fi))==get(findx(a[k].fi.se))) {
                    cout<<"NO"<<endl;
                    ppp=0;
                    break;
                }
            }
        }
        
        if(ppp==1) cout<<"YES"<<endl;
    }
    
}
