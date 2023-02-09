/*
* @title    : 5014번 스타트링크(실버 1)
* @content  : 너비 우선 탐색
* @author   : 탁준석
* @date     : 230105
* @time     : 12ms
* @memory   : 5932KB
* @state    : 완료
*/

#include <iostream>
#include <vector>
#include <queue>
using namespace std;

void makeGraph();
void bfs(int x);

vector<int> dist;
queue<int> q;

int F, S, G, U, D;

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);
	makeGraph();
	bfs(S);
	return 0;
}

void makeGraph() {
	cin >> F >> S >> G >> U >> D;
	dist = vector<int>(F + 1, -1);
}

void bfs(int x) {
	q.push(x);
	dist[x] = 0;

	while (!q.empty()) {
		int pos = q.front();
		q.pop();

		for (const auto& nx : { pos + U, pos - D }) {
			if (1 <= nx && nx <= F && dist[nx] < 0) {
				q.push(nx);
				dist[nx] = dist[pos] + 1;
			}
		}
	}

	if (dist[G] < 0) { cout << "use the stairs" << '\n'; }
	else { cout << dist[G] << '\n'; }
}