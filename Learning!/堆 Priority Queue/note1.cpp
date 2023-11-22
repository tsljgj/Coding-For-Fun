#include <bits/stdc++.h>
using namespace std;
int n, x, ans;
int main() {
	cin >> n;
	priority_queue<int, vector<int>, greater<int> > q; //greater 与default相反   堆默认大的在前  这里是从小到大 
	for (int i = 0; i < n; i++) {
		cin >> x;
		q.push(x);//加数字 (数据类型与queue定义的相同) 
	}
	for (int i = 1; i < n; i++) {
		int x = q.top();
		q.pop();//删掉一个数字 
		int y = q.top();
		q.pop();
		ans += x + y;
		q.push(x + y);
	}
	cout << ans << endl;
}
//queue,stack只能用top/front, except deque<int>(下标访问） 
//sort(a,a+n,greater<int>()); 
//复杂度检测：计数运行最多的一条语句
//部分有向无环，可以分层求最短路 
