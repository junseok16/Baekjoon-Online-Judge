/*
* @title    : 11060번 점프 점프(실버 2)
* @content  : 너비 우선 탐색
* @author   : 탁준석
* @date     : 230209
* @time     : 0ms
* @memory   : 2024KB
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

int N;

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);
	makeGraph();
	bfs(0);
	return 0;
}

void makeGraph() {
	cin >> N;
	adj = vector<int>(N, -1);
	dist = vector<int>(N, -1);
	for (int i = 0; i < N; ++i) { cin >> adj[i]; }
}

void bfs(int x) {
	q.push(x);
	dist[x] = 0;

	while (!q.empty()) {
		int pos = q.front();
		q.pop();

		for (int i = 1; i <= adj[pos]; ++i) {
			int nx = pos + i;

			// 배열의 범위를 벗어나는 경우
			if (nx >= N) { continue; }

			// 이미 방문한 정점인 경우
			if (dist[nx] > -1) { continue; }
			q.push(nx);
			dist[nx] = dist[pos] + 1;
		}
	}
	cout << dist[N - 1] << '\n';
}