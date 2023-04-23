/*
* @title    : 1260번 DFS와 BFS(실버 2)
* @content  : 깊이 우선 탐색
* @author   : 탁준석
* @date     : 230313
* @time     : 0ms
* @memory   : 2300KB
* @state    : 진행 중
*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

void MakeGraph();
void DFS(int i);
void BFS(int i);

vector<vector<int>> adj;
vector<bool> visited;
queue<int> q;

int N, M, V;

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);
	MakeGraph();
	DFS(V);
	cout << '\n';
	BFS(V);
	return 0;
}

void MakeGraph() {
	cin >> N >> M >> V;
	adj = vector<vector<int>>(N + 1, vector<int>());
	visited = vector<bool>(N + 1, false);

	for (int i = 0; i < M; ++i) {
		int u, v;
		cin >> u >> v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}

	// 방문할 수 있는 정점이 여러 개인 경우, 작은 것을 먼저 방문합니다.
	for (int j = 1; j < N + 1; ++j) {
		sort(adj[j].begin(), adj[j].end());
	}
}

void DFS(int i) {
	visited[i] = true;
	cout << i << ' ';

	for (const auto& e : adj[i]) {
		if (visited[e] == false) {
			DFS(e);
		}
	}
}

void BFS(int i) {
	visited = vector<bool>(N + 1, false);
	q.push(i);
	visited[i] = true;

	while (!q.empty()) {
		int v = q.front();
		q.pop();
		cout << v << ' ';

		for (const auto& e : adj[v]) {
			if (visited[e] == false) {
				q.push(e);
				visited[e] = true;
			}
		}
	}
}