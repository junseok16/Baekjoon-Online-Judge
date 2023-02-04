/*
* @title    : 1197번 최소 스패닝 트리(골드 4)
* @content  : 최소 신장 트리
* @author   : 탁준석
* @date     : 230203
* @time     : 56ms
* @memory   : 7424KB
* @state    : 완료
*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <tuple>
#include <queue>
using namespace std;

void makeGraph();
void prim();

vector<vector<pair<int, int>>> adj;
priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>, greater<tuple<int, int, int>>> pq;
vector<bool> visited;

int V, E, sumOfWeight;

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    makeGraph();
    prim();
    return 0;
}

void makeGraph() {
    cin >> V >> E;
    adj = vector<vector<pair<int, int>>>(V + 1);
    visited = vector<bool>(V + 1, false);

    for (int i = 0; i < E; ++i) {
        int A, B, C;
        cin >> A >> B >> C;
        adj[A].push_back({ C, B });
        adj[B].push_back({ C, A });
    }
}

void prim() {
    for (const auto& e : adj[1]) {
        pq.push({ e.first, 1, e.second });
    }
    visited[1] = true;

    while (!pq.empty()) {
        auto [cost, from, to] = pq.top();
        pq.pop();

        if (visited[to] == false) {
            visited[to] = true;
            sumOfWeight += cost;

            for (const auto& e : adj[to]) {
                if (visited[e.second] == false) {
                    pq.push({ e.first, to, e.second });
                }
            }
        }
    }
    cout << sumOfWeight << '\n';
}