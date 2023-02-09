/*
* @title    : 1697번 숨바꼭질(실버 1)
* @content  : 너비 우선 탐색
* @author   : 탁준석
* @date     : 230104
* @time     : 0ms
* @memory   : 2548KB
* @state    : 완료
*/

#include <iostream>
#include <vector>
#include <queue>
using namespace std;

void makeGraph();
void bfs(int x);

vector<int> adj, dist;
queue<int> q;

int N, K;

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);
	makeGraph();
	bfs(N);
	return 0;
}

void makeGraph() {
	cin >> N >> K;
	dist = vector<int>(100001, -1);
}

void bfs(int x) {
	q.push(x);
	dist[x] = 0;

	while (!q.empty()) {
		int pos = q.front();
		q.pop();

		if (pos == K) {
			cout << dist[K] << '\n';
			break;
		}

		// 범위 기반 for 반복문으로 걷거나 순간이동합니다.
		for (const auto& nx : { pos + 1, pos - 1, 2 * pos }) {
			if (0 <= nx && nx <= 100000 && dist[nx] < 0) {
				dist[nx] = dist[pos] + 1;
				q.push(nx);
			}
		}
	}
}