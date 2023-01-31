/*
* @title    : 2606번 바이러스(실버 3)
* @content  : 너비 우선 탐색
* @author   : 탁준석
* @date     : 230106
* @time     : 0ms
* @memory   : 2024KB
* @state    : 완료
*/

#include <iostream>
#include <vector>
#include <queue>
using namespace std;

void makeGraph();
void bfs(int i);

vector<vector<int>> adj;
vector<bool> visited;
queue<int> q;

int N, M, infected = 0;

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);
	makeGraph();
	bfs(1);
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

void bfs(int i) {
	q.push(i);
	visited[i] = true;
	infected = 0;

	while (!q.empty()) {
		int v = q.front();
		q.pop();

		for (const auto& e : adj[v]) {
			if (visited[e] == false) {
				q.push(e);
				visited[e] = true;
				++infected;
			}
		}
	}
	cout << infected << '\n';
}