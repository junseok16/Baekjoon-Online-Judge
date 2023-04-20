/*
* @title    : 1715번 카드 정렬하기(골드 4)
* @content  : 우선순위 큐
* @author   : 탁준석
* @date     : 230310
* @time     : 24ms
* @memory   : 2916KB
* @state    : 완료
*/

#include <iostream>
#include <queue>
using namespace std;

priority_queue<int, vector<int>, greater<int>> pq;
int N, numOfComparison;

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> N;
	for (int i = 0; i < N; ++i) {
		int x;
		cin >> x;
		pq.push(x);
	}

	while (pq.size() > 1) {
		int firstBundle = pq.top();
		pq.pop();
		int secondBundle = pq.top();
		pq.pop();

		int combinedBundle = firstBundle + secondBundle;
		numOfComparison += combinedBundle;
		pq.push(combinedBundle);
	}
	cout << numOfComparison << '\n';
	return 0;
}