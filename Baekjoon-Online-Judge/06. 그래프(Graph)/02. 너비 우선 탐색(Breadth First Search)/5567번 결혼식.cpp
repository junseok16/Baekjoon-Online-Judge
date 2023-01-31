/*
* @title    : 5567번 결혼식(실버 2)
* @content  : 너비 우선 탐색
* @author   : 탁준석
* @date     : 230106
* @time     : 0ms
* @memory   : 2288KB
* @state    : 완료
*/

#include <iostream>
#include <vector>
#include <queue>
using namespace std;

void makeGraph();
void bfs(int i);

vector<vector<int>> adj;
vector<int> dist;
queue<int> q;

int N, M, guest;

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	makeGraph();
	bfs(1);
	return 0;
}

void makeGraph() {
	cin >> N >> M;
	adj = vector<vector<int>>(N + 1, vector<int>());
	dist = vector<int>(N + 1, -1);
	guest = 0;

	for (int i = 0; i < M; ++i) {
		int a, b;
		cin >> a >> b;
		adj[a].push_back(b);
		adj[b].push_back(a);
	}
}

void bfs(int i) {
	dist[i] = 0;
	q.push(i);

	while (!q.empty()) {
		int v = q.front();
		q.pop();

		for (const auto& e : adj[v]) {
			if (dist[e] < 0) {
				dist[e] = dist[v] + 1;
				q.push(e);
			}
		}
	}

	for (const auto& e : dist) {
		if (e == 1 || e == 2) {
			++guest;
		}
	}
	cout << guest << '\n';
}