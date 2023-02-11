/*
* @title    : 7576번 토마토(골드 5)
* @content  : 너비 우선 탐색
* @author   : 탁준석
* @date     : 230104
* @time     : 96ms
* @memory   : 14216KB
* @state    : 완료
*/

#include <iostream>
#include <vector>
#include <queue>
using namespace std;

void makeGraph();
void bfs();

vector<vector<int>> adj;
vector<vector<int>> dist;
queue<pair<int, int>> q;

int N, M, days = 0;
int dx[4] = { 1, 0, -1, 0 };
int dy[4] = { 0, 1, 0, -1 };

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);
	makeGraph();
	bfs();
	return 0;
}

void makeGraph() {
	cin >> M >> N;
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
	while (!q.empty()) {
		pair<int, int> pos = q.front();
		q.pop();

		for (int d = 0; d < 4; ++d) {
			int nx = pos.first + dx[d];
			int ny = pos.second + dy[d];

			// 배열의 범위를 벗어나는 경우
			if (nx < 0 || ny < 0 || nx >= N || ny >= M) {
				continue;
			}

			// 벽이거나 이미 방문한 정점인 경우
			if (adj[nx][ny] == -1 || dist[nx][ny] > -1) {
				continue;
			}

			q.push({ nx, ny });
			adj[nx][ny] = 1;
			dist[nx][ny] = dist[pos.first][pos.second] + 1;
		}
	}

	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < M; ++j) {
			if (adj[i][j] == 0) {
				cout << -1 << '\n';
				return;
			}
			days = dist[i][j] > days ? dist[i][j] : days;
		}
	}
	cout << days << '\n';
}