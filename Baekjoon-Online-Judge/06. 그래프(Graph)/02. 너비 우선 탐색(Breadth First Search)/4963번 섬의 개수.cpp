/*
* @title    : 4963번 섬의 개수(실버 2)
* @content  : 너비 우선 탐색
* @author   : 탁준석
* @date     : 230114
* @time     : 0ms
* @memory   : 2156KB
* @state    : 완료
*/

#include <iostream>
#include <vector>
#include <queue>
using namespace std;

void makeGraph(int w, int h);
void bfsAll();
void bfs(int i, int j);

vector<vector<int>> adj;
vector<vector<bool>> visited;
queue<pair<int, int>> q;

int W, H, numOfIsland = 0;
int dx[8] = { 1, 1, 1, 0, 0, -1, -1, -1 };
int dy[8] = { -1, 0, 1, -1, 1, -1, 0, 1 };

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);

	while (true) {
		cin >> W >> H;
		if (W == 0 && H == 0) { break; }

		makeGraph(W, H);
		bfsAll();
	}
	return 0;
}

void makeGraph(int w, int h) {
	adj = vector<vector<int>>(h, vector<int>(w, 0));
	visited = vector<vector<bool>>(h, vector<bool>(w, false));
	numOfIsland = 0;

	for (int i = 0; i < h; ++i) {
		for (int j = 0; j < w; ++j) {
			cin >> adj[i][j];
		}
	}
}

void bfsAll() {
	for (int i = 0; i < H; ++i) {
		for (int j = 0; j < W; ++j) {
			if (adj[i][j] == 1 && visited[i][j] == false) {
				bfs(i, j);
				++numOfIsland;
			}
		}
	}

	cout << numOfIsland << ' ';
}

void bfs(int i, int j) {
	q.push({ i, j });
	visited[i][j] = true;

	while (!q.empty()) {
		pair<int, int> pos = q.front();
		q.pop();

		for (int i = 0; i < 8; ++i) {
			int nx = pos.first + dx[i];
			int ny = pos.second + dy[i];

			if (nx < 0 || ny < 0 || nx >= H || ny >= W) {
				continue;
			}
			if (adj[nx][ny] == 0 || visited[nx][ny] == true) {
				continue;
			}
			q.push({ nx, ny });
			visited[nx][ny] = true;
		}
	}
}