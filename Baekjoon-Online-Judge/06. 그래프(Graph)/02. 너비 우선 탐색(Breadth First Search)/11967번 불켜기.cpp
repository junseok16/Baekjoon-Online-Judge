/*
* @title    : 11967번 불켜기(골드 2)
* @content  : 너비 우선 탐색
* @author   : 탁준석
* @date     : 230423
* @time     : 8ms
* @memory   : 2820KB
* @state    : 완료
*/

#include <iostream>
#include <vector>
#include <queue>
using namespace std;

void MakeGraph();
void BFS();

vector<vector<bool>> light, visited;
vector<vector<vector<pair<int, int>>>> switches;
queue<pair<int, int>> q;

vector<int> dx = { 1, 0, -1, 0 };
vector<int> dy = { 0, 1, 0, -1 };
int N, M;

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);
	MakeGraph();
	BFS();
	return 0;
}

void MakeGraph() {
	cin >> N >> M;
	light = vector<vector<bool>>(N + 1, vector<bool>(N + 1, false));
	visited = vector<vector<bool>>(N + 1, vector<bool>(N + 1, false));
	switches = vector<vector<vector<pair<int, int>>>>(N + 1, vector<vector<pair<int, int>>>(N + 1));

	// (1, 1) 방은 불이 켜져 있습니다.
	light[1][1] = true;

	for (int i = 0; i < M; ++i) {
		int x, y, a, b;
		cin >> x >> y >> a >> b;
		switches[x][y].push_back({ a, b });
	}
}

void BFS() {
	int numOfRoom = 1;
	q.push({ 1, 1 });
	visited[1][1] = true;

	for (const auto& s : switches[1][1]) {
		if (light[s.first][s.second] == true) {
			continue;
		}
		light[s.first][s.second] = true;
		++numOfRoom;
	}

	while (!q.empty()) {
		auto pos = q.front();
		q.pop();

		for (const auto& s : switches[pos.first][pos.second]) {
			// 불이 꺼진 방만 불을 켭니다.
			if (light[s.first][s.second] == true) {
				continue;
			}
			light[s.first][s.second] = true;

			// 새로 불이 켜진 방을 셉니다.
			++numOfRoom;

			// 불이 켜진 방이 이전 경로를 통해 다시 갈 수 있는 방인지 확인합니다.
			for (int i = 0; i < 4; ++i) {
				int nx = s.first + dx[i];
				int ny = s.second + dy[i];

				// 배열의 범위를 벗어나는 경우
				if (nx < 1 || ny < 1 || nx > N || ny > N) {
					continue;
				}

				if (visited[nx][ny] == false) {
					continue;
				}
				
				// 이전 경로를 통해 갈 수 있는 방으로 다시 너비 우선 탐색합니다.
				q.push({ nx, ny });
				visited[nx][ny] = true;
				break;
			}
		}

		for (int i = 0; i < 4; ++i) {
			int nx = pos.first + dx[i];
			int ny = pos.second + dy[i];

			// 배열의 범위를 벗어나는 경우
			if (nx < 1 || ny < 1 || nx > N || ny > N) {
				continue;
			}
			// 이미 방문한 곳이거나 불이 꺼진 방인 경우
			if (visited[nx][ny] == true || light[nx][ny] == false) {
				continue;
			}

			q.push({ nx, ny });
			visited[nx][ny] = true;
		}
	}

	cout << numOfRoom << '\n';
}