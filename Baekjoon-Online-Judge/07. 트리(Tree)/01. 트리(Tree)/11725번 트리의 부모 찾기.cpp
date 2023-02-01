/*
* @title    : 11725번 트리의 부모 찾기(실버 2)
* @content  : 트리
* @author   : 탁준석
* @date     : 230131
* @time     : 48ms
* @memory   : 8060KB
* @state    : 완료
*/

#include <iostream>
#include <vector>
#include <queue>
using namespace std;

void makeTree();
void bfs(int x);

vector<vector<int>> adj;
vector<int> parent;
queue<int> q;

int N;

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);
	makeTree();
	bfs(1);
	return 0;
}

void makeTree() {
	cin >> N;
	adj = vector<vector<int>>(N + 1, vector<int>());
	parent = vector<int>(N + 1, -1);

	// 루트 노드의 부모 노드는 없으므로 0으로 초기화합니다.
	parent[1] = 0;

	for (int i = 0; i < N - 1; ++i) {
		int u, v;
		cin >> u >> v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
}

void bfs(int x) {
	q.push(x);

	while (!q.empty()) {
		int node = q.front();
		q.pop();

		for (const auto& e : adj[node]) {
			// 부모 노드가 아닌 자식 노드만 큐에 넣습니다.
			if (parent[node] != e) {
				q.push(e);
				parent[e] = node;
			}
		}
	}

	// 루트 노드를 제외한 노드의 부모 노드를 출력합니다.
	for (unsigned int i = 2; i < parent.size(); ++i) {
		cout << parent[i] << '\n';
	}
}