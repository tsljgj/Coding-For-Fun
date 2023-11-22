#include <bits/stdc++.h>
using namespace std;
int n, k, b[30],c[30],minn=1e9;
int main() {
	scanf("%d", &n);
	
	for(int i=0;i<n;i++){
		cin>>b[i]>>c[i];
	}
	

	
	for (int i = 1; i <= 1 << n; i++) {
		int s1=1,s2=0;
		for (int j = 0; j < n; j++) {
			if (i >> j & 1) {
				s1 *= b[j];
				s2 += c[j];
				minn=min(minn,abs(s1-s2));
			}
			
		}
		
//				cout<<s1<<" "<<s2<<" "<<minn;
//				cout<<endl;

	}
	
	cout<<minn<<endl;
	return 0;
}
