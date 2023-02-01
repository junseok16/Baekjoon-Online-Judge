/*
* @title    : 18352번 특정 거리의 도시 찾기(실버 2)
* @content  : 너비 우선 탐색
* @author   : 탁준석
* @date     : 230131
* @time     : 416ms
* @memory   : 21728KB
* @state    : 완료
*/

#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

void makeGraph();
void bfs(int x);

vector<vector<int>> adj;
vector<int> dist;
vector<int> numOfCity;
queue<int> q;

int N, M, K, X;

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);
	makeGraph();
	bfs(X);
	return 0;
}

void makeGraph() {
	cin >> N >> M >> K >> X;
	adj = vector<vector<int>>(N + 1);
	dist = vector<int>(N + 1, -1);

	for (int i = 0; i < M; ++i) {
		int A, B;
		cin >> A >> B;
		adj[A].push_back(B);
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
				
				// 거리가 K만큼 떨어진 도시만 저장합니다.
				if (dist[e] == K) {
					numOfCity.push_back(e);
				}
			}
		}
	}

	if (numOfCity.size() > 0) {
		sort(numOfCity.begin(), numOfCity.end());
		for (const auto& e : numOfCity) {
			cout << e << '\n';
		}
	}
	else {
		cout << -1 << '\n';
	}
}