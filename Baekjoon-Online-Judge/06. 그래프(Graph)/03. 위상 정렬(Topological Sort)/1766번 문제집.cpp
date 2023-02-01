/*
* @title    : 1766번 문제집(골드 2)
* @content  : 위상 정렬
* @author   : 탁준석
* @date     : 230201
* @time     : 28ms
* @memory   : 4216KB
* @state    : 완료
*/

#include <iostream>
#include <vector>
#include <queue>
using namespace std;

void makeGraph();
void topologicalSort();

vector<vector<int>> adj;
vector<int> indegree, sorted;

// 최소 힙으로 구성된 우선순위 큐를 선언합니다.
priority_queue<int, vector<int>, greater<int>> pq;

int N, M;

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    makeGraph();
    topologicalSort();
    return 0;
}

void makeGraph() {
    cin >> N >> M;
    adj = vector<vector<int>>(N + 1);
    indegree = vector<int>(N + 1, 0);

    for (int i = 0; i < M; ++i) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        ++indegree[v];
    }
}

void topologicalSort() {
    for (int i = 1; i <= N; ++i) {
        if (indegree[i] == 0) { pq.push(i); }
    }

    while (!pq.empty()) {
        int node = pq.top();
        pq.pop();
        sorted.push_back(node);

        for (const auto& e : adj[node]) {
            if (--indegree[e] == 0) { pq.push(e); }
        }
    }

    for (const auto& e : sorted) {
        cout << e << ' ';
    }
}