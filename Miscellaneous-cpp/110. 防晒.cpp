#include<bits/stdc++.h>
#define fi first
#define se second
using namespace std;
pair<int,int> SPFcow[3000];
pair<int,int> SPF[3000];
bool cmd(pair<int,int> a,pair<int,int> b){
    return a.fi>b.fi;
}
int main(){
    int c,l;
    cin>>c>>l;
    for(int i=1;i<=c;i++){
        cin>>SPFcow[i].fi>>SPFcow[i].se;
    }
    
    for(int i=1;i<=l;i++){
        cin>>SPF[i].fi>>SPF[i].se;
    }
    
    sort(SPFcow+1,SPFcow+c+1,cmd);
    sort(SPF+1,SPF+l+1,cmd);
    
//    for(int i=1;i<=c;i++){
//    	cout<<SPFcow[i].fi<<SPFcow[i].se<<endl;
//	}
//	
//	for(int i=1;i<=l;i++){
//		cout<<SPF[i].fi<<SPF[i].se<<endl;
//	}
    
    int ans=0, j=1;
    for(int i=1;i<=c;i++){
    	for(int j=1;j<=l;j++){
    		if(SPF[j].fi<=SPFcow[i].se&&SPF[j].fi>=SPFcow[i].fi&&SPF[j].se>0) {
	            SPF[j].se--;
	            ans++;
	            break;
	        }
		}
    }
    
    cout<<ans<<endl;
}
