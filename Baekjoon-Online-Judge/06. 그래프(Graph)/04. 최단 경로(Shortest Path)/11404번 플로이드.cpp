/*
* @title    : 11404번 플로이드(골드 4)
* @content  : 최단 경로
* @author   : 탁준석
* @date     : 230202
* @time     : 24ms
* @memory   : 2152KB
* @state    : 완료
*/

#include <iostream>
#include <vector>
using namespace std;

void makeGraph();
void floydWarshall();

vector<vector<int>> dist;

const int INF = 1e9;
int N, M;

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);
	makeGraph();
	floydWarshall();
	return 0;
}

void makeGraph() {
	cin >> N >> M;
	dist = vector<vector<int>>(N + 1, vector<int>(N + 1, INF));

	for (int i = 1; i <= N; ++i) {
		dist[i][i] = 0;
	}

	for (int i = 0; i < M; ++i) {
		int from, to, cost;
		cin >> from >> to >> cost;

		if (cost < dist[from][to]) {
			dist[from][to] = cost;
		}
	}
}

void floydWarshall() {
	for (int k = 1; k <= N; ++k) {
		for (int i = 1; i <= N; ++i) {
			for (int j = 1; j <= N; ++j) {
				if (dist[i][k] + dist[k][j] < dist[i][j]) {
					dist[i][j] = dist[i][k] + dist[k][j];
				}
			}
		}
	}

	for (int i = 1; i <= N; ++i) {
		for (int j = 1; j <= N; ++j) {
			if (dist[i][j] == INF) { cout << "0 "; }
			else { cout << dist[i][j] << ' '; }
		}
		cout << '\n';
	}
}