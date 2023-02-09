/*
* @title    : 1389번 케빈 베이컨의 6단계 법칙(실버 1)
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
#include <algorithm>
using namespace std;

void makeGraph();
void bfsAll();
void bfs(int i);

vector<vector<int>> adj;
vector<int> dist, kevinBacon;
queue<int> q;

int N, M;

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
	kevinBacon = vector<int>(N, 0);

	for (int i = 0; i < M; ++i) {
		int u, v;
		cin >> u >> v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
}

void bfsAll() {
	for (int i = 1; i <= N; ++i) {
		dist = vector<int>(N + 1, -1);
		bfs(i);
	}
	cout << min_element(kevinBacon.begin(), kevinBacon.end()) - kevinBacon.begin() + 1 << '\n';
}

void bfs(int i) {
	q.push(i);
	dist[i] = 0;

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

	int sum = 0;
	for (const auto& e : dist) {
		sum += e;
	}
	kevinBacon[i - 1] = sum + 1;
}