#include <bits/stdc++.h>
using namespace std;
int n, x, ans;
int main() {
	cin >> n;
	priority_queue<int, vector<int>, greater<int> > q; //greater ��default�෴   ��Ĭ�ϴ����ǰ  �����Ǵ�С���� 
	for (int i = 0; i < n; i++) {
		cin >> x;
		q.push(x);//������ (����������queue�������ͬ) 
	}
	for (int i = 1; i < n; i++) {
		int x = q.top();
		q.pop();//ɾ��һ������ 
		int y = q.top();
		q.pop();
		ans += x + y;
		q.push(x + y);
	}
	cout << ans << endl;
}
//queue,stackֻ����top/front, except deque<int>(�±���ʣ� 
//sort(a,a+n,greater<int>()); 
//���Ӷȼ�⣺������������һ�����
//���������޻������Էֲ������· 
