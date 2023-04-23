/*
* @title    : 14502번 연구소(골드 4)
* @content  : 시뮬레이션
* @author   : 탁준석
* @date     : 230419
* @time     : 80ms
* @memory   : 2028KB
* @state    : 완료
*/

#include <iostream>
#include <vector>
#include <queue>
using namespace std;

void MakeGraph();
void Combination(unsigned int index, unsigned int begin);
void BFS();

vector<vector<int>> adj, temp;
vector<vector<bool>> visited;
vector<pair<int, int>> emptyCells, viruses, walls;
queue<pair<int, int>> q;
vector<int> dx = { 1, 0, -1, 0 };
vector<int> dy = { 0, 1, 0, -1 };

// 새로 세울 수 있는 벽의 개수
const unsigned int MAX_WALL = 3;
int maxSafeArea = 0;
int N, M;

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);
	MakeGraph();

	// 조합을 구합니다.
	Combination(0, 0);
	cout << maxSafeArea << '\n';
	return 0;
}

void MakeGraph() {
	cin >> N >> M;
	adj = vector<vector<int>>(N, vector<int>(M, 0));
	walls = vector<pair<int, int>>(MAX_WALL, { 0, 0 });
	visited = vector<vector<bool>>(N, vector<bool>(M, false));

	for (int n = 0; n < N; ++n) {
		for (int m = 0; m < M; ++m) {
			cin >> adj[n][m];

			// 빈 칸의 좌표를 모두 저장합니다.
			if (adj[n][m] == 0) {
				emptyCells.push_back({ n, m });
			}
			// 바이러스의 좌표를 모두 저장합니다.
			else if (adj[n][m] == 2) {
				viruses.push_back({ n, m });
			}
		}
	}
}

void Combination(unsigned int index, unsigned int begin) {
	if (index == MAX_WALL) {
		visited = vector<vector<bool>>(N, vector<bool>(M, false));

		// 원본 연구소를 복사합니다.
		temp = adj;

		// 벽 세 개를 새로 세웁니다.
		for (const auto& wall : walls) {
			temp[wall.first][wall.second] = 1;
		}

		// 바이러스가 있는 곳에서 너비 우선 탐색합니다.
		for (const auto& virus : viruses) {
			q.push({ virus.first, virus.second });
			visited[virus.first][virus.second] = true;
		}
		BFS();
		return;
	}

	for (unsigned int i = begin; i < emptyCells.size(); ++i) {
		walls[index] = emptyCells[i];
		Combination(index + 1, i + 1);
	}
}

void BFS() {
	// 바이러스가 퍼지기 전 안전 영역의 넓이입니다.
	unsigned int safeArea = emptyCells.size() - MAX_WALL;

	while (!q.empty()) {
		pair<int, int> cell = q.front();
		q.pop();

		for (int i = 0; i < 4; ++i) {
			int nx = cell.first + dx[i];
			int ny = cell.second + dy[i];

			// 배열의 범위를 벗어나는 경우
			if (nx < 0 || ny < 0 || nx >= N || ny >= M) {
				continue;
			}

			// 이미 방문한 곳이거나 벽인 경우
			if (visited[nx][ny] == true || temp[nx][ny] == 1) {
				continue;
			}

			q.push({ nx, ny });
			visited[nx][ny] = true;

			// 바이러스가 도달하여 안전 영역의 넓이를 감소시킵니다.
			safeArea -= 1;
		}
	}

	if (maxSafeArea < safeArea) {
		maxSafeArea = safeArea;
	}
}