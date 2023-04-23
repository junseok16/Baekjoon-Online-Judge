/*
* @title    : 11779번 최소비용 구하기 2(골드 3)
* @content  : 다익스트라
* @author   : 탁준석
* @date     : 230422
* @time     : 36ms
* @memory   : 4752KB
* @state    : 완료
*/

#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

#define MAX_INT 0x3f3f3f3f
#define DIST first
#define NODE second
using namespace std;

void MakeGraph();
void Dijkstra();

priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
vector<vector<pair<int, int>>> adj;
vector<int> sp, tp;

int N, M, S, E;

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);
	MakeGraph();
	Dijkstra();
	return 0;
}

void MakeGraph() {
	cin >> N >> M;
	adj = vector<vector<pair<int, int>>>(N + 1, vector<pair<int, int>>());
	sp = vector<int>(N + 1, MAX_INT);
	tp = vector<int>(N + 1, 0);

	for (int m = 0; m < M; ++m) {
		int a, b, c;
		cin >> a >> b >> c;
		adj[a].push_back({ c, b });
	}
	cin >> S >> E;
}

void Dijkstra() {
	pq.push({ 0, S });
	sp[S] = 0;

	while (!pq.empty()) {
		auto tailNode = pq.top();
		pq.pop();

		if (sp[tailNode.NODE] < tailNode.DIST) {
			continue;
		}

		for (const auto& headNode : adj[tailNode.NODE]) {
			if (sp[headNode.NODE] > sp[tailNode.NODE] + headNode.DIST) {
				sp[headNode.NODE] = sp[tailNode.NODE] + headNode.DIST;
				pq.push({ sp[headNode.NODE], headNode.NODE });

				tp[headNode.NODE] = tailNode.NODE;
			}
		}
	}

	cout << sp[E] << '\n';

	// A번째 도시에서 B번째 도시로 가는 경로를 추적합니다.
	vector<int> paths;
	int node = E;
	while (node != S) {
		paths.push_back(node);
		node = tp[node];
	}
	paths.push_back(S);
	reverse(paths.begin(), paths.end());

	cout << paths.size() << '\n';

	for (const auto& path : paths) {
		cout << path << ' ';
	}
}