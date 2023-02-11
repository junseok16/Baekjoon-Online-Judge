/*
* @title    : 7569번 토마토(골드 5)
* @content  : 너비 우선 탐색
* @author   : 탁준석
* @date     : 230104
* @time     : 136ms
* @memory   : 12196KB
* @state    : 완료
*/

#include <iostream>
#include <vector>
#include <queue>
#include <tuple>
using namespace std;

void makeGraph();
void bfs();

vector<vector<vector<int>>> adj, dist;
queue<tuple<int, int, int>> q;

int M, N, H, days = 0;
int dx[6] = { 1, -1, 0, 0, 0, 0 };
int dy[6] = { 0, 0, 1, -1, 0, 0 };
int dz[6] = { 0, 0, 0, 0, 1, -1 };

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);
	makeGraph();
	bfs();
	return 0;
}

void makeGraph() {
	cin >> M >> N >> H;
	adj = vector<vector<vector<int>>>(N, vector<vector<int>>(M, vector<int>(H, 0)));
	dist = vector<vector<vector<int>>>(N, vector<vector<int>>(M, vector<int>(H, -1)));

	for (int k = 0; k < H; ++k) {
		for (int i = 0; i < N; ++i) {
			for (int j = 0; j < M; ++j) {
				cin >> adj[i][j][k];

				if (adj[i][j][k] == 1) {
					dist[i][j][k] = 0;
					q.push({ i, j, k });
				}
			}
		}
	}
}

void bfs() {
	while (!q.empty()) {
		tuple<int, int, int> pos = q.front();
		q.pop();

		for (int i = 0; i < 6; ++i) {
			int nx = get<0>(pos) + dx[i];
			int ny = get<1>(pos) + dy[i];
			int nz = get<2>(pos) + dz[i];

			if (nx < 0 || ny < 0 || nz < 0 || nx >= N || ny >= M || nz >= H) {
				continue;
			}
			if (adj[nx][ny][nz] == -1 || dist[nx][ny][nz] > -1) {
				continue;
			}
			q.push({ nx, ny, nz });
			adj[nx][ny][nz] = 1;
			dist[nx][ny][nz] = dist[get<0>(pos)][get<1>(pos)][get<2>(pos)] + 1;
		}
	}

	for (int k = 0; k < H; ++k) {
		for (int i = 0; i < N; ++i) {
			for (int j = 0; j < M; ++j) {
				if (adj[i][j][k] == 0) {
					cout << -1 << '\n';
					return;
				}
				if (dist[i][j][k] > days) {
					days = dist[i][j][k];
				}
			}
		}
	}
	cout << days << '\n';
}