/*
* @title    : 13975번 파일 합치기 3(골드 4)
* @content  : 우선순위 큐
* @author   : 탁준석
* @date     : 230310
* @time     : 728ms
* @memory   : 18532KB
* @state    : 완료
*/

#include <iostream>
#include <queue>
using namespace std;

int T, K;

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> T;
	for (int i = 0; i < T; ++i) {
		priority_queue<long long, vector<long long>, greater<long long>> pq;
		long long cost = 0;

		cin >> K;
		for (int j = 0; j < K; ++j) {
			int size;
			cin >> size;
			pq.push(size);
		}

		while (pq.size() > 1) {
			long long firstSize = pq.top();
			pq.pop();
			long long secondSize = pq.top();
			pq.pop();

			long long combinedSize = firstSize + secondSize;
			cost += combinedSize;
			pq.push(combinedSize);
		}
		cout << cost << '\n';
	}
	return 0;
}