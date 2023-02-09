/*
* @title    : 7562번 나이트의 이동(실버 1)
* @content  : 너비 우선 탐색
* @author   : 탁준석
* @date     : 230104
* @time     : 28ms
* @memory   : 2816KB
* @state    : 완료
*/

#include <iostream>
#include <vector>
#include <queue>
using namespace std;

void makeGraph();
void bfs(int x, int y);

vector<vector<int>> dist;
pair<int, int> s, e;

int T, I;
int dx[8] = { 2, 2, -2, -2, 1, -1, 1, -1 };
int dy[8] = { 1, -1, 1, -1, 2, 2, -2, -2 };

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> T;
	for (int i = 0; i < T; ++i) {
		makeGraph();
		bfs(s.first, s.second);
	}
	return 0;
}

void makeGraph() {
	cin >> I;
	dist = vector<vector<int>>(I, vector<int>(I, -1));
	
	cin >> s.first >> s.second;
	cin >> e.first >> e.second;
}

void bfs(int x, int y) {
	queue<pair<int, int>> q;

	q.push({ x, y });
	dist[x][y] = 0;

	while (!q.empty()) {
		pair<int, int> pos = q.front();
		q.pop();

		if (pos.first == e.first && pos.second == e.second) {
			cout << dist[e.first][e.second] << '\n';
			break;
		}

		for (int d = 0; d < 8; ++d) {
			int nx = pos.first + dx[d];
			int ny = pos.second + dy[d];

			// 배열의 범위를 벗어나는 경우
			if (nx < 0 || ny < 0 || nx >= I || ny >= I) {
				continue;
			}

			// 이미 방문한 정점인 경우
			if (dist[nx][ny] > -1) {
				continue;
			}

			q.push({ nx, ny });
			dist[nx][ny] = dist[pos.first][pos.second] + 1;
		}
	}
}