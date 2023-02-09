/*
* @title    : 13565번 침투(실버 2)
* @content  : 너비 우선 탐색
* @author   : 탁준석
* @date     : 230209
* @time     : 36ms
* @memory   : 5212KB
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
queue<pair<int, int>> q;

int dx[4] = { 1, 0, -1, 0 };
int dy[4] = { 0, 1, 0, -1 };
int N, M;

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);
	makeGraph();
	bfsAll();
	return 0;
}

void makeGraph() {
	cin >> N >> M;
	adj = vector<vector<int>>(N, vector<int>(M, 0));
	visited = vector<vector<bool>>(N, vector<bool>(M, false));

	for (int i = 0; i < N; ++i) {
		string percolate;
		cin >> percolate;

		for (int j = 0; j < M; ++j) {
			adj[i][j] = percolate[j] - '0';
		}
	}
}

void bfsAll() {
	for (int i = 0; i < M; ++i) {
		if (adj[0][i] == 0 && visited[0][i] == false) {
			bfs(0, i);
		}
	}

	for (int i = 0; i < M; ++i) {
		if (adj[N - 1][i] == 0 && visited[N - 1][i] == true) {
			cout << "YES" << '\n';
			return;
		}
	}
	cout << "NO" << '\n';
}

void bfs(int x, int y) {
	q.push({ x, y });
	visited[x][y] = true;

	while (!q.empty()) {
		auto pos = q.front();
		q.pop();

		for (int i = 0; i < 4; ++i) {
			int nx = pos.first + dx[i];
			int ny = pos.second + dy[i];

			// 배열의 범위를 벗어나는 경우
			if (nx < 0 || ny < 0 || nx >= N || ny >= M) {
				continue;
			}
			// 이미 방문한 정점이거나 전류가 흐르지 않는 정점인 경우
			if (adj[nx][ny] == 1 || visited[nx][ny] == true) {
				continue;
			}
			q.push({ nx, ny });
			visited[nx][ny] = true;
		}
	}
}