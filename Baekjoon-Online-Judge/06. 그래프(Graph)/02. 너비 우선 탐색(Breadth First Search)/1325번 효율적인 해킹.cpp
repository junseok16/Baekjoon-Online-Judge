/*
* @title    : 1325번 효율적인 해킹(실버 1)
* @content  : 너비 우선 탐색
* @author   : 탁준석
* @date     : 230110
* @time     : 3720ms
* @memory   : 3212KB
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
vector<bool> visited;
vector<int> hackedComputer;
queue<int> q;

int N, M, maxNumOfHackedComputer = 0;

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
	hackedComputer = vector<int>(N + 1, 0);

	for (int i = 0; i < M; ++i) {
		int u, v;
		cin >> u >> v;
		adj[v].push_back(u);
	}
}

void bfsAll() {
	for (int i = 1; i <= N; ++i) {
		bfs(i);
	}

	for (int i = 1; i <= N; ++i) {
		if (hackedComputer[i] == maxNumOfHackedComputer) {
			cout << i << ' ';
		}
	}
}

void bfs(int i) {
	visited = vector<bool>(N + 1, false);
	q.push(i);
	visited[i] = true;

	int edge = 0;

	while (!q.empty()) {
		int vertex = q.front();
		q.pop();

		for (const auto& e : adj[vertex]) {
			if (visited[e] == false) {
				q.push(e);
				visited[e] = true;
				++edge;
			}
		}
	}
	hackedComputer[i] = edge + 1;
	maxNumOfHackedComputer = edge + 1 > maxNumOfHackedComputer ? edge + 1 : maxNumOfHackedComputer;
}