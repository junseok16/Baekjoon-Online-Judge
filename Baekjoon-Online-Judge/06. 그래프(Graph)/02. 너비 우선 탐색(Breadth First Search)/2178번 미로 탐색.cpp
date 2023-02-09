/*
* @title    : 2178번 미로 탐색(실버 1)
* @content  : 너비 우선 탐색
* @author   : 탁준석
* @date     : 230104
* @time     : 0ms
* @memory   : 2160KB
* @state    : 완료
*/

#include <iostream>
#include <vector>
#include <queue>
#include <utility>
using namespace std;

void makeGraph();
void bfs(int x, int y);

vector<vector<int>> adj;
vector<vector<int>> dist;
queue<pair<int, int>> q;

int N, M;
int dx[4] = { 1, 0, -1, 0 };
int dy[4] = { 0, 1, 0, -1 };

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);
	makeGraph();

	// (0, 0)에서 (N - 1, M - 1)까지 이동 거리를 구합니다.
	bfs(0, 0);
	return 0;
}

void makeGraph() {
	cin >> N >> M;
	adj = vector<vector<int>>(N, vector<int>(M, 0));
	dist = vector<vector<int>>(N, vector<int>(M, -1));
	
	for (int i = 0; i < N; ++i) {
		string s;
		cin >> s;

		for (int j = 0; j < M; ++j) {
			// char에 '0'을 빼서 int 벡터에 저장할 수 있습니다.
			adj[i][j] = s[j] - '0';
		}
	}
}

void bfs(int x, int y) {
	dist[x][y] = 1;
	q.push({ x, y });

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
			if (!adj[nx][ny] || dist[nx][ny] > -1) {
				continue;
			}

			// 이동 거리를 갱신합니다.
			dist[nx][ny] = dist[pos.first][pos.second] + 1;
			q.push({ nx, ny });
		}
	}
	// 최소 거리를 출력합니다.
	cout << dist[N - 1][M - 1] << '\n';
}