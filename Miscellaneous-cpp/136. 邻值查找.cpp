#include<bits/stdc++.h>
//#define ios                               \
//    ios::sync_with_stdio(false); \
//    cin.tie(nullptr);                     \
//    cout.tie(nullptr)
using namespace std;
set<pair<long long,int> > s;

int main(){
//	ios;
	int n;
	long long a;
	cin>>n>>a;
	s.insert({a,1});
	for(int i=2;i<=n;i++){
		cin>>a;
		s.insert({a,i});
		set<pair<long long,int> >::iterator it=s.find({a,i});
		pair<long long,int> ans;
		ans.first=0x3f3f3f3f;          //必须有 
		if(++it!=s.end()){
			ans={(*it).first-a,(*it).second};
		} 
		it--;
		if(it--!=s.begin()){           //不可以是--it 
			if(ans.first>=a-(*it).first){
				ans={a-(*it).first,(*it).second};
			}
		}
		cout<<ans.first<<" "<<ans.second<<endl;
	}
}
