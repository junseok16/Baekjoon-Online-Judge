/*
* @title    : 17086번 아기 상어 2(실버 2)
* @content  : 너비 우선 탐색
* @author   : 탁준석
* @date     : 230211
* @time     : 0ms
* @memory   : 2156KB
* @state    : 완료
*/

#include <iostream>
#include <vector>
#include <queue>
using namespace std;

void makeGraph();
void bfs();

vector<vector<int>> adj, dist;
queue<pair<int, int>> q;

int dx[8] = { 1, 1, 1, 0, 0, -1, -1, -1 };
int dy[8] = { -1, 0, 1, -1, 1, -1, 0, 1 };
int N, M;

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);
	makeGraph();
	bfs();
	return 0;
}

void makeGraph() {
	cin >> N >> M;
	adj = vector<vector<int>>(N, vector<int>(M, 0));
	dist = vector<vector<int>>(N, vector<int>(M, -1));

	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < M; ++j) {
			cin >> adj[i][j];

			if (adj[i][j] == 1) {
				q.push({ i, j });
				dist[i][j] = 0;
			}
		}
	}
}

void bfs() {
	int safeDistance = 0;

	while (!q.empty()) {
		auto pos = q.front();
		q.pop();

		for (int i = 0; i < 8; ++i) {
			int nx = pos.first + dx[i];
			int ny = pos.second + dy[i];

			if (nx < 0 || ny < 0 || nx >= N || ny >= M) {
				continue;
			}
			// 상어가 있는 정점이거나 이미 방문한 정점인 경우
			if (adj[nx][ny] == 1 || dist[nx][ny] > -1) {
				continue;
			}
			q.push({ nx, ny });
			dist[nx][ny] = dist[pos.first][pos.second] + 1;

			if (safeDistance < dist[nx][ny]) {
				safeDistance = dist[nx][ny];
			}
		}
	}
	cout << safeDistance << '\n';
}