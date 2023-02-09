/*
* @title    : 2583번 영역 구하기(실버 1)
* @content  : 너비 우선 탐색
* @author   : 탁준석
* @date     : 230105
* @time     : 0ms
* @memory   : 2160KB
* @state    : 완료
*/

#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

void makeGraph();
void bfsAll();
void bfs(int x, int y);

vector<vector<int>> adj;
vector<vector<bool>> visited;
queue<pair<int, int>> q;
vector<int> sizeOfRect;

int M, N, K, numOfRect = 0;
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
	cin >> M >> N >> K;
	adj = vector<vector<int>>(M, vector<int>(N, 1));
	visited = vector<vector<bool>>(M, vector<bool>(N, false));
	
	for (int i = 0; i < K; ++i) {
		int leftX, leftY, rightX, rightY;
		cin >> leftX >> leftY >> rightX >> rightY;
		
		// 직사각형을 0, 나머지 부분을 1로 나타냅니다.
		for (int x = leftY; x < rightY; ++x) {
			for (int y = leftX; y < rightX; ++y) {
				adj[x][y] = 0;
			}
		}
	}
}

void bfsAll() {
	for (int i = 0; i < M; ++i) {
		for (int j = 0; j < N; ++j) {
			// 아직 방문하지 않은 나머지 영역인 경우
			if (adj[i][j] == 1 && visited[i][j] == false) {
				bfs(i, j);

				// 나머지 영역의 개수를 셉니다.
				++numOfRect;
			}
		}
	}

	// 나머지 영역의 크기를 오름차순으로 정렬합니다.
	sort(sizeOfRect.begin(), sizeOfRect.end());
	cout << numOfRect << '\n';
	for (const auto& e : sizeOfRect) {
		cout << e << ' ';
	}
}

void bfs(int x, int y) {
	q.push({ x, y });
	visited[x][y] = true;

	int size = 1;

	while (!q.empty()) {
		pair<int, int> pos = q.front();
		q.pop();

		for (int i = 0; i < 4; ++i) {
			int nx = pos.first + dx[i];
			int ny = pos.second + dy[i];

			if (nx < 0 || ny < 0 || nx >= M || ny >= N) {
				continue;
			}
			if (adj[nx][ny] == 0 || visited[nx][ny] == true) {
				continue;
			}
			q.push({ nx, ny });
			visited[nx][ny] = true;
			
			// 나머지 영역의 크기를 구합니다.
			++size;
		}
	}
	// 나머지 영역의 크기를 저장합니다.
	sizeOfRect.push_back(size);
}