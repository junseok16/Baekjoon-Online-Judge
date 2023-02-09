/*
* @title    : 1926번 그림(실버 1)
* @content  : 너비 우선 탐색
* @author   : 탁준석
* @date     : 230104
* @time     : 24ms
* @memory   : 3084KB
* @state    : 완료
*/

#include <iostream>
#include <vector>
#include <queue>
using namespace std;

void makeGraph();
void bfsAll();
void bfs(int i, int j);

vector<vector<int>> adj;
vector<vector<bool>> visited;
queue<pair<int, int>> q;

int n, m, maxSizeOfPicture = 0, numOfPicture = 0;
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
	cin >> n >> m;
	adj = vector<vector<int>>(n, vector<int>(m, 0));
	visited = vector<vector<bool>>(n, vector<bool>(m, false));

	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			cin >> adj[i][j];
		}
	}
}

void bfsAll() {
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			if (!visited[i][j] && adj[i][j]) {
				bfs(i, j);

				// 그림의 개수를 갱신합니다.
				++numOfPicture;
			}
		}
	}
	cout << numOfPicture << '\n';
	cout << maxSizeOfPicture << '\n';
}

void bfs(int i, int j) {
	visited[i][j] = true;
	q.push({ i, j });

	int sizeOfPicture = 1;

	while (!q.empty()) {
		pair<int, int> pos = q.front();
		q.pop();

		for (int d = 0; d < 4; ++d) {
			int nx = pos.first + dx[d];
			int ny = pos.second + dy[d];

			if (nx < 0 || ny < 0 || nx >= n || ny >= m) {
				continue;
			}
			if (visited[nx][ny] || !adj[nx][ny]) {
				continue;
			}
			visited[nx][ny] = true;
			q.push({ nx, ny });
			++sizeOfPicture;
		}
	}

	// 그림의 최대 크기를 갱신합니다.
	if (sizeOfPicture > maxSizeOfPicture) {
		maxSizeOfPicture = sizeOfPicture;
	}
}