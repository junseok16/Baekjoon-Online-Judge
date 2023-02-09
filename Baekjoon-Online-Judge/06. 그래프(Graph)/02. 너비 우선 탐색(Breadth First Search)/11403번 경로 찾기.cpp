/*
* @title    : 11403번 경로 찾기(실버 1)
* @content  : 너비 우선 탐색
* @author   : 탁준석
* @date     : 230106
* @time     : 4ms
* @memory   : 2156KB
* @state    : 완료
*/

#include <iostream>
#include <vector>
#include <queue>
using namespace std;

void makeGraph();
void bfsAll();
void bfs(int i);

vector<vector<int>> adj, path;
vector<bool> visited;

int N;

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);
	makeGraph();
	bfsAll();
	return 0;
}

void makeGraph() {
	cin >> N;
	adj = vector<vector<int>>(N + 1, vector<int>());
	path = vector<vector<int>>(N + 1, vector<int>(N + 1, 0));

	// 인접 행렬을 인접 리스트로 변환합니다.
	for (int i = 1; i <= N; ++i) {
		for (int j = 1; j <= N; ++j) {
			int e;
			cin >> e;

			if (e == 1) {
				adj[i].push_back(j);
			}
		}
	}
}

void bfsAll() {
	for (int i = 1; i <= N; ++i) {
		bfs(i);
	}

	for (int i = 1; i <= N; ++i) {
		for (int j = 1; j <= N; ++j) {
			cout << path[i][j] << ' ';
		}
		cout << '\n';
	}
}

void bfs(int i) {
	visited = vector<bool>(N + 1, false);
	queue<int> q;

	q.push(i);
	visited[i] = true;

	while (!q.empty()) {
		int v = q.front();
		q.pop();

		for (const auto& e : adj[v]) {
			if (visited[e] == true || path[i][e] == 0) {
				path[i][e] = 1;
			}

			if (visited[e] == false) {
				q.push(e);
				visited[e] = true;
				path[v][e] = 1;
				path[i][e] = 1;
			}
		}
	}
}