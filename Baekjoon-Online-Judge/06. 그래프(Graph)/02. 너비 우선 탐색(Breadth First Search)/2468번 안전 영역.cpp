/*
* @title    : 2468번 안전 영역(실버 1)
* @content  : 너비 우선 탐색
* @author   : 탁준석
* @date     : 230105
* @time     : 28ms
* @memory   : 2156KB
* @state    : 완료
*/

#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

void makeGraph();
void bfsAll();
void bfs(int x, int y, int rain);

vector<vector<int>> adj;
vector<vector<bool>> visited;

int N, height = 0, safety = 0, maxSizeOfSafety = 0;
int dx[4] = { 1, 0, -1, 0 };
int dy[4] = { 0, 1, 0, -1 };

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);
	makeGraph();
	bfsAll();
	return 0;
}

void makeGraph() {
	cin >> N;
	adj = vector<vector<int>>(N, vector<int>(N, 0));
	
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < N; ++j) {
			cin >> adj[i][j];

			// 안전 영역의 최대 높이를 구합니다.
			height = adj[i][j] > height ? adj[i][j] : height;
		}
	}
}

void bfsAll() {
	// 비가 오지 않은 경우와 비가 최대 높이까지 온 경우도 고려해야 합니다.
	for (int rain = 0; rain <= height; ++rain) {
		visited = vector<vector<bool>>(N, vector<bool>(N, false));
		safety = 0;

		for (int i = 0; i < N; ++i) {
			for (int j = 0; j < N; ++j) {
				// 아직 물에 잠기지 않고 방문하지 않은 정점인 경우
				if (adj[i][j] > rain && visited[i][j] == false) {
					bfs(i, j, rain);

					// 안전 영역의 개수를 셉니다.
					++safety;
				}
			}
		}
		// 안전 영역의 최대 개수를 갱신합니다.
		maxSizeOfSafety = safety > maxSizeOfSafety ? safety : maxSizeOfSafety;
	}
	cout << maxSizeOfSafety << '\n';
}

void bfs(int x, int y, int rain) {
	queue<pair<int, int>> q;

	q.push({ x, y });
	visited[x][y] = true;

	while (!q.empty()) {
		pair<int, int> pos = q.front();
		q.pop();

		for (int i = 0; i < 4; ++i) {
			int nx = pos.first + dx[i];
			int ny = pos.second + dy[i];

			if (nx < 0 || ny < 0 || nx >= N || ny >= N) {
				continue;
			}

			// 물에 잠겼거나 이미 방문한 정점인 경우
			if (adj[nx][ny] <= rain || visited[nx][ny] == true) {
				continue;
			}
			q.push({ nx, ny });
			visited[nx][ny] = true;
		}
	}
}