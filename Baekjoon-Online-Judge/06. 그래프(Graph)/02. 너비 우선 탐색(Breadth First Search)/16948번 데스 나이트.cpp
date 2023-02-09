/*
* @title    : 16948번 데스 나이트(실버 1)
* @content  : 너비 우선 탐색
* @author   : 탁준석
* @date     : 230209
* @time     : 0ms
* @memory   : 2288KB
* @state    : 완료
*/

#include <iostream>
#include <vector>
#include <queue>
#include <utility>
using namespace std;

void makeGraph();
void bfs(int x, int y);

vector<vector<int>> dist;
queue<pair<int, int>> q;

int dx[6] = { -2, -2, 0, 0, 2, 2 };
int dy[6] = { -1, 1, -2, 2, -1, 1 };
int N, r1, c1, r2, c2;

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);
	makeGraph();
	bfs(r1, c1);
	return 0;
}

void makeGraph() {
	cin >> N >> r1 >> c1 >> r2 >> c2;
	dist = vector<vector<int>>(N, vector<int>(N, -1));
}

void bfs(int x, int y) {
	q.push({ x, y });
	dist[x][y] = 0;

	while (!q.empty()) {
		auto pos = q.front();
		q.pop();
		
		// 최소 이동 횟수를 출력합니다.
		if (pos.first == r2 && pos.second == c2) {
			cout << dist[r2][c2] << '\n';
			return;
		}

		for (int i = 0; i < 6; ++i) {
			int nx = pos.first + dx[i];
			int ny = pos.second + dy[i];

			// 배열의 범위를 벗어나는 경우
			if (nx < 0 || ny < 0 || nx >= N || ny >= N) {
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
	// 이동할 수 없는 경우, -1을 출력합니다.
	cout << -1 << '\n';
}