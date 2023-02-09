/*
* @title    : 16953번 A → B(실버 2)
* @content  : 너비 우선 탐색
* @author   : 탁준석
* @date     : 230209
* @time     : 0ms
* @memory   : 2284KB
* @state    : 완료
*/

#include <iostream>
#include <queue>
#include <utility>
using namespace std;

void makeGraph();
void bfs(long long x);

// dist 배열을 선언할 경우, 메모리를 초과합니다.
queue<pair<long long, long long>> q;

long long A, B;

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);
	makeGraph();
	bfs(A);
	return 0;
}

void makeGraph() {
	cin >> A >> B;
}

void bfs(long long x) {
	q.push({ x, 0 });

	while (!q.empty()) {
		pair<long long, long long> pos = q.front();
		q.pop();

		if (pos.first == B) {
			cout << pos.second + 1 << '\n';
			return;
		}

		for (const auto& e : { 2 * pos.first, 10 * pos.first + 1 }) {
			if (e < B + 1) {
				q.push({ e, pos.second + 1 });
			}
		}
	}
	cout << -1 << '\n';
}