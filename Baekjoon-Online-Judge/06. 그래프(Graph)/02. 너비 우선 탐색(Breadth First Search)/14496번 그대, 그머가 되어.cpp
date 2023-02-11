/*
* @title    : 14496번 그대, 그머가 되어(실버 2)
* @content  : 너비 우선 탐색
* @author   : 탁준석
* @date     : 230211
* @time     : 4ms
* @memory   : 2300KB
* @state    : 완료
*/

#include <iostream>
#include <vector>
#include <queue>
using namespace std;

void makeGraph();
void bfs(int x);

vector<vector<int>> adj;
vector<int> dist;
queue<int> q;

int a, b, N, M;

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);
	makeGraph();
	bfs(a);
	return 0;
}

void makeGraph() {
	cin >> a >> b >> N >> M;
	adj = vector<vector<int>>(N + 1, vector<int>());
	dist = vector<int>(N + 1, -1);

	for (int i = 0; i < M; ++i) {
		int u, v;
		cin >> u >> v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
}

void bfs(int x) {
	q.push(x);
	dist[x] = 0;

	while (!q.empty()) {
		int v = q.front();
		q.pop();

		for (const auto& e : adj[v]) {
			if (dist[e] < 0) {
				q.push(e);
				dist[e] = dist[v] + 1;
			}
		}
	}
	cout << dist[b] << '\n';
}