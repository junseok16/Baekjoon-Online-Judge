/*
* @title    : 2623번 음악프로그램(골드 3)
* @content  : 위상 정렬
* @author   : 탁준석
* @date     : 2302021
* @time     : 0ms
* @memory   : 2168KB
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
queue<int> q;

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
    indegree = vector<int>(N + 1);

    for (int i = 0; i < M; ++i) {
        int numOfSinger, u;
        cin >> numOfSinger >> u;

        for (int j = 0; j < numOfSinger - 1; ++j) {
            int v;
            cin >> v;
            adj[u].push_back(v);
            ++indegree[v];
            u = v;
        }
    }
}

void topologicalSort() {
    for (int i = 1; i <= N; ++i) {
        if (indegree[i] == 0) { q.push(i); }
    }

    while (!q.empty()) {
        int node = q.front();
        q.pop();
        sorted.push_back(node);

        for (const auto& e : adj[node]) {
            if (--indegree[e] == 0) { q.push(e); }
        }
    }

    // 사이클이 있는 그래프인 경우, 위상 정렬을 할 수 없습니다.
    if (sorted.size() < N) {
        cout << 0 << '\n';
    }
    else {
        for (const auto& e : sorted) { cout << e << '\n'; }
    }
}
