#include<bits/stdc++.h>
using namespace std;
pair<int,int> lo[3000],p[3000];
bool b[3000];
int ans=0;
int main(){
	int C,L;
	cin>>C>>L;
	for(int i=1;i<=C;i++) cin>>lo[i].second>>lo[i].first;
	for(int i=1;i<=L;i++) cin>>p[i].first>>p[i].second;
	
	sort(lo+1,lo+C+1);
	sort(p+1,p+L+1);
	
	for(int j=1;j<=C;j++){
		for(int i=1;i<=L;i++){
			if(p[i].second>0&&p[i].first>=lo[j].second&&p[i].first<=lo[j].first) {
				ans++;
				p[i].second--;
				break;
			}
		}
	}
	
	cout<<ans<<endl;
	return 0;
	
}
