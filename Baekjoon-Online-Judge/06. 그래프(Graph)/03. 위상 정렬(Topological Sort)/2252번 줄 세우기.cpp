/*
* @title    : 2252번 줄 세우기(골드 3)
* @content  : 위상 정렬
* @author   : 탁준석
* @date     : 230201
* @time     : 32ms
* @memory   : 4228KB
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
    indegree = vector<int>(N + 1, 0);

    for (int i = 0; i < M; ++i) {
        int A, B;
        cin >> A >> B;
        adj[A].push_back(B);
        ++indegree[B];
    }
}

void topologicalSort() {
    // 진입 차수가 0인 정점을 큐에 넣습니다.
    for (int i = 1; i <= N; ++i) {
        if (indegree[i] == 0) {
            q.push(i);
        }
    }

    while (!q.empty()) {
        int node = q.front();
        q.pop();
        sorted.push_back(node);

        // 간선으로 연결된 정점의 진입 차수를 1만큼 감소시킵니다.
        for (const auto& e : adj[node]) {
            // 진입 차수가 0인 정점을 큐에 넣습니다.        
            if (--indegree[e] == 0) {
                q.push(e);
            }
        }
    }

    for (const auto& e : sorted) {
        cout << e << ' ';
    }
}