/*
* @title    : 1927번 최소 힙(실버 2)
* @content  : 우선순위 큐
* @author   : 탁준석
* @date     : 230310
* @time     : 16ms
* @memory   : 2916KB
* @state    : 완료
*/

#include <iostream>
#include <queue>
using namespace std;

priority_queue<int, vector<int>, greater<int>> pq;

int N;

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> N;
	for (int i = 0; i < N; ++i) {
		int x;
		cin >> x;

		switch (x) {
		case 0:
			if (pq.empty() == true) {
				cout << 0 << '\n';
			}
			else {
				cout << pq.top() << '\n';
				pq.pop();
			}
			break;

		default:
			pq.push(x);
			break;
		}
	}
	return 0;
}