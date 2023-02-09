/*
* @title    : 6118번 숨바꼭질(실버 1)
* @content  : 너비 우선 탐색
* @author   : 탁준석
* @date     : 230110
* @time     : 16ms
* @memory   : 3752KB
* @state    : 완료
*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

void makeGraph();
void bfs(int i);

vector<vector<int>> adj;
vector<int> dist;
queue<int> q;

int N, M;
int barn, maxDistOfBarn, numOfBarn;

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
	dist = vector<int>(N + 1, -1);

	for (int i = 0; i < M; ++i) {
		int u, v;
		cin >> u >> v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
}

void bfs(int i) {
	q.push(i);
	dist[i] = 0;

	while (!q.empty()) {
		int vertex = q.front();
		q.pop();

		for (const auto& e : adj[vertex]) {
			if (dist[e] < 0) {
				q.push(e);
				dist[e] = dist[vertex] + 1;
			}
		}
	}

	barn = max_element(dist.begin(), dist.end()) - dist.begin();
	maxDistOfBarn = *max_element(dist.begin(), dist.end());

	for (const auto& e : dist) {
		if (e == maxDistOfBarn) {
			++numOfBarn;
		}
	}
	cout << barn << ' ' << maxDistOfBarn << ' ' << numOfBarn << '\n';
}