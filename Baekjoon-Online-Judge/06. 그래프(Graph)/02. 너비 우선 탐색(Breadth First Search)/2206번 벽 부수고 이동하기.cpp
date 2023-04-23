/*
* @title    : 2206번 벽 부수고 이동하기(골드 3)
* @content  : 너비 우선 탐색
* @author   : 탁준석
* @date     : 230422
* @time     : 300ms
* @memory   : 62492KB
* @state    : 완료
*/

#include <iostream>
#include <vector>
#include <queue>
#include <tuple>
using namespace std;

void MakeGraph();
void BFS();

vector<vector<int>> adj;
vector<vector<vector<int>>> dist;
queue<tuple<int, int, int>> q;

vector<int> dx = { 1, 0, -1, 0 };
vector<int> dy = { 0, 1, 0, -1 };
int N, M;

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);
	MakeGraph();
	BFS();
	return 0;
}

void MakeGraph() {
	cin >> N >> M;
	adj = vector<vector<int>>(N, vector<int>(M, 0));
	dist = vector<vector<vector<int>>>(N, vector<vector<int>>(M, vector<int>(2, -1)));

	for (int i = 0; i < N; ++i) {
		string map;
		cin >> map;
		for (int j = 0; j < M; ++j) {
			adj[i][j] = map[j] - '0';
		}
	}
}

void BFS() {
	q.push({ 0, 0, 0 });
	dist[0][0][0] = dist[0][0][1] = 1;

	while (!q.empty()) {
		auto pos = q.front();
		q.pop();

		auto& [x, y, wall] = pos;
		if (x == N - 1 && y == M - 1) {
			cout << dist[x][y][wall] << '\n';
			return;
		}

		for (int i = 0; i < 4; ++i) {
			int nx = x + dx[i];
			int ny = y + dy[i];

			// 배열의 범위를 벗어나는 경우
			if (nx < 0 || ny < 0 || nx >= N || ny >= M) {
				continue;
			}

			// 이미 방문한 정점인 경우
			if (dist[nx][ny][wall] > -1) {
				continue;
			}

			// 방문한 정점이 빈 칸인 경우
			if (adj[nx][ny] == 0) {
				dist[nx][ny][wall] = dist[x][y][wall] + 1;
				q.push({ nx, ny, wall });
			}
			// 방문한 정점이 벽이고 아직 벽을 부수지 않은 경우
			else if (adj[nx][ny] == 1 && wall == 0) {
				dist[nx][ny][wall + 1] = dist[x][y][wall] + 1;
				q.push({ nx, ny, wall + 1 });
			}
		}
	}

	cout << -1 << '\n';
}