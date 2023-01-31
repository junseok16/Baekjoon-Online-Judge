/*
* @title    : 11724번 연결 요소의 개수(실버 2)
* @content  : 너비 우선 탐색
* @author   : 탁준석
* @date     : 230106
* @time     : 88ms
* @memory   : 6524KB
* @state    : 완료
*/

#include <iostream>
#include <vector>
#include <queue>
using namespace std;

void makeGraph();
void bfsAll();
void bfs(int i);

vector<vector<int>> adj;
vector<bool> visited;
queue<int> q;

int N, M, component = 0;

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);
	makeGraph();
	bfsAll();
	return 0;
}

void makeGraph() {
	cin >> N >> M;
	adj = vector<vector<int>>(N + 1, vector<int>());
	visited = vector<bool>(N + 1, false);

	for (int i = 0; i < M; ++i) {
		int u, v;
		cin >> u >> v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
}

void bfsAll() {
	for (int i = 1; i < N + 1; ++i) {
		if (visited[i] == false) {
			bfs(i);
			++component;
		}
	}
	cout << component << '\n';
}

void bfs(int i) {
	q.push(i);
	visited[i] = true;

	while (!q.empty()) {
		int v = q.front();
		q.pop();

		for (const auto& e : adj[v]) {
			if (visited[e] == false) {
				q.push(e);
				visited[e] = true;
			}
		}
	}
}