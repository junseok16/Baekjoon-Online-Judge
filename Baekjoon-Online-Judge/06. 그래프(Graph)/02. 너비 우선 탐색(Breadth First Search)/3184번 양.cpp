/*
* @title    : 3184번 양(실버 1)
* @content  : 너비 우선 탐색
* @author   : 탁준석
* @date     : 230209
* @time     : 0ms
* @memory   : 2156KB
* @state    : 완료
*/

#include <iostream>
#include <vector>
#include <queue>
using namespace std;

void makeGraph();
void bfsAll();
void bfs(int x, int y);

vector<vector<char>> adj;
vector<vector<bool>> visited;
queue<pair<int, int>> q;

int dx[4] = { 1, 0, -1, 0 };
int dy[4] = { 0, 1, 0, -1 };
int R, C, numOfWolf, numOfSheep;

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);
	makeGraph();
	bfsAll();
	return 0;
}

void makeGraph() {
	cin >> R >> C;
	adj = vector<vector<char>>(R, vector<char>(C, '.'));
	visited = vector<vector<bool>>(R, vector<bool>(C, false));

	for (int i = 0; i < R; ++i) {
		for (int j = 0; j < C; ++j) {
			cin >> adj[i][j];
		}
	}
}

void bfsAll() {
	for (int i = 0; i < R; ++i) {
		for (int j = 0; j < C; ++j) {
			if ((adj[i][j] == 'v' && visited[i][j] == false) || 
				(adj[i][j] == 'o' && visited[i][j] == false)) {
				bfs(i, j);
			}
		}
	}
	// 아침에 도달했을 때 살아남은 양과 늑대의 수를 출력합니다.
	cout << numOfSheep << ' ' << numOfWolf << '\n';
}

void bfs(int x, int y) {
	q.push({ x, y });
	visited[x][y] = true;
	int wolf = 0;
	int sheep = 0;

	if (adj[x][y] == 'v') { wolf++; }
	if (adj[x][y] == 'o') { sheep++; }

	while (!q.empty()) {
		auto pos = q.front();
		q.pop();

		for (int i = 0; i < 4; ++i) {
			int nx = pos.first + dx[i];
			int ny = pos.second + dy[i];

			// 배열의 범위를 벗어나는 경우
			if (nx < 0 || ny < 0 || nx >= R || ny >= C) {
				continue;
			}
			// 이미 방문한 정점이거나 울타리로 막힌 정점인 경우
			if (adj[nx][ny] == '#' || visited[nx][ny] == true) {
				continue;
			}

			q.push({ nx, ny });
			visited[nx][ny] = true;
			if (adj[nx][ny] == 'v') { wolf++; }
			if (adj[nx][ny] == 'o') { sheep++; }
		}
	}

	// 영역 안에 양의 수가 늑대의 수보다 적은 경우
	if (sheep <= wolf) { sheep = 0; }
	// 영역 안에 양의 수가 늑대의 수보다 많은 경우
	else { wolf = 0; }

	numOfWolf += wolf;
	numOfSheep += sheep;
}