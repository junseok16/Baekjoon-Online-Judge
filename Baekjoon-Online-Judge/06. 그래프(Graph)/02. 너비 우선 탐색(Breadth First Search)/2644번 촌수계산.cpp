/*
* @title    : 2644번 촌수계산(실버 2)
* @content  : 너비 우선 탐색
* @author   : 탁준석
* @date     : 230114
* @time     : 0ms
* @memory   : 2024KB
* @state    : 완료
*/

#include <iostream>
#include <vector>
#include <queue>
using namespace std;

void makeGraph();
void bfs(int a);

vector<vector<int>> adj;
vector<int> dist;
queue<int> q;

int N, A, B, M;

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);
	makeGraph();
	bfs(A);
	return 0;
}

void makeGraph() {
	cin >> N >> A >> B >> M;
	adj = vector<vector<int>>(N + 1, vector<int>());
	dist = vector<int>(N + 1, -1);
	
	for (int i = 0; i < M; ++i) {
		int u, v;
		cin >> u >> v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
}

void bfs(int a) {
	q.push(a);
	dist[a] = 0;

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
	cout << dist[B] << '\n';
}