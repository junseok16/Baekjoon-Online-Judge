/*
* @title    : 2667번 단지번호붙이기(실버 1)
* @content  : 너비 우선 탐색
* @author   : 탁준석
* @date     : 230105
* @time     : 0ms
* @memory   : 2164KB
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
vector<int> sizeOfVillage;
queue<pair<int, int>> q;

int N, numOfVillage = 0;
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
	visited = vector<vector<bool>>(N, vector<bool>(N, false));

	for (int i = 0; i < N; ++i) {
		string s;
		cin >> s;
		for (int j = 0; j < N; ++j) {
			adj[i][j] = s[j] - '0';
		}
	}
}

void bfsAll() {
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < N; ++j) {
			if (adj[i][j] == 1 && visited[i][j] == false) {
				bfs(i, j);
				++numOfVillage;
			}
		}
	}
	sort(sizeOfVillage.begin(), sizeOfVillage.end());
	cout << numOfVillage << '\n';
	for (const auto& e : sizeOfVillage) {
		cout << e << '\n';
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

			if (nx < 0 || ny < 0 || nx >= N || ny >= N) {
				continue;
			}
			if (adj[nx][ny] == 0 || visited[nx][ny] == true) {
				continue;
			}
			q.push({ nx, ny });
			visited[nx][ny] = true;
			++size;
		}
	}
	sizeOfVillage.push_back(size);
}