#include <bits/stdc++.h>
using namespace std;
int n, m, ans;
int a[100020];
int p[100020];
map<int, int> g;
set<int> s;
int main() {
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	for (int i = n - 1; i >= 0; i--) {
		cout<<endl;
		cout<<"a[i]="<<a[i]<<endl;
		if (g.find(a[i]) == g.end()) {
			cout<<"not found"<<endl;
			p[i] = n;
		} else {
			cout<<"found"<<endl; 
			p[i] = g[a[i]];
		}
		g[a[i]] = i;
		cout<<"p[i]:"<<endl;
		for(int j=0;j<n;j++){
			cout<<p[j]<<" ";
		} 
//		cout<<endl;
//		cout<<"g[j]:"<<endl;
//		for(int j=0;j<g.size();j++)        ***输出则会在下一次find是found,不输出则不会 
//			cout<<g[j]<<" ";
		cout<<endl;
	}
	for (int i = 0; i < n; i++) {
		if (s.find(i) == s.end()) {
			ans++;
			if (s.size() == m) {
				s.erase(--s.end());
			}
		} else {
			s.erase(i);
		}
		s.insert(p[i]);
	}
	cout << ans << endl;
	return 0;
}
