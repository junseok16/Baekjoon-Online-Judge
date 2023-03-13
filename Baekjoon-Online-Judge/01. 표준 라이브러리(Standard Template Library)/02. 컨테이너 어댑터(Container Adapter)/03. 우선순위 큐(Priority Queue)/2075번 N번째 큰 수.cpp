/*
* @title    : 2075번 N번째 큰 수(실버 2)
* @content  : 우선순위 큐
* @author   : 탁준석
* @date     : 230310
* @time     : 364ms
* @memory   : 2156KB
* @state    : 완료
*/

#include <iostream>
#include <queue>
using namespace std;

priority_queue<int, vector<int>, greater<int>> pq;

unsigned long int N;

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> N;
	for (int i = 0; i < N * N; ++i) {
		int x;
		cin >> x;
		pq.push(x);

		if (pq.size() > N) {
			pq.pop();
		}
	}
	cout << pq.top() << '\n';
	return 0;
}