/*
* @title    : 1012번 유기농 배추(실버 2)
* @content  : 너비 우선 탐색
* @author   : 탁준석
* @date     : 230104
* @time     : 0ms
* @memory   : 2156KB
* @state    : 완료
*/

#include <iostream>
#include <vector>
#include <queue>
using namespace std;

void makeGraph();
void bfsAll();
void bfs(int x, int y);

vector<vector<int>> adj;
vector<vector<bool>> visited;

int T, M, N, K, worm = 0;
int dx[4] = { 1, 0, -1, 0 };
int dy[4] = { 0, 1, 0, -1 };

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> T;
	for (int i = 0; i < T; ++i) {
		makeGraph();
		bfsAll();
	}
	return 0;
}

void makeGraph() {
	cin >> N >> M >> K;
	adj = vector<vector<int>>(N, vector<int>(M, 0));
	visited = vector<vector<bool>>(N, vector<bool>(M, false));
	worm = 0;

	for (int i = 0; i < K; ++i) {
		int x, y;
		cin >> x >> y;
		adj[x][y] = 1;
	}
}

void bfsAll() {
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < M; ++j) {
			// 정점에 배추가 심어져있고 아직 방문하지 않은 경우
			if (adj[i][j] == 1 && visited[i][j] == false) {
				bfs(i, j);
				++worm;
			}
		}
	}
	cout << worm << '\n';
}

void bfs(int x, int y) {
	queue<pair<int, int>> q;
	q.push({ x, y });
	visited[x][y] = true;

	while (!q.empty()) {
		pair<int, int> pos = q.front();
		q.pop();

		for (int i = 0; i < 4; ++i) {
			int nx = pos.first + dx[i];
			int ny = pos.second + dy[i];

			// 배열의 범위를 벗어나는 경우
			if (nx < 0 || ny < 0 || nx >= N || ny >= M) {
				continue;
			}
			// 배추가 심어져있지 않거나 정점을 이미 방문한 경우
			if (adj[nx][ny] == 0 || visited[nx][ny] == true) {
				continue;
			}
			q.push({ nx, ny });
			visited[nx][ny] = true;
		}
	}
}