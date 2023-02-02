/*
* @title    : 1197번 최소 스패닝 트리(골드 4)
* @content  : 최소 신장 트리
* @author   : 탁준석
* @date     : 230201
* @time     : 36ms
* @memory   : 3356KB
* @state    : 완료
*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <tuple>
using namespace std;

void makeGraph();
void kruskal();
void initialize();
bool isDisjoint(int x, int y);
void Union(int x, int y);
int Find(int x);

vector<tuple<int, int, int>> edge;
vector<int> parent;

int V, E, sumOfWeight;

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    makeGraph();
    kruskal();
    return 0;
}

void initialize() {
    for (int i = 1; i <= V; ++i) {
        parent[i] = i;
    }
}

void Union(int x, int y) {
    x = Find(x);
    y = Find(y);
    parent[y] = x;
}

int Find(int x) {
    if (parent[x] == x) { return x; }
    else { return parent[x] = Find(parent[x]); }
}

bool isDisjoint(int x, int y) {
    x = Find(x);
    y = Find(y);
    return x != y ? true : false;
}

void makeGraph() {
    cin >> V >> E;
    edge = vector<tuple<int, int, int>>(E);
    parent = vector<int>(V + 1, 0);
    initialize();

    // 간선 리스트를 정의합니다.
    for (int i = 0; i < E; ++i) {
        int A, B, C;
        cin >> A >> B >> C;
        edge[i] = { C, A, B };
    }
    // 간선 리스트를 가중치를 기준으로 오름차순으로 정렬합니다.
    sort(edge.begin(), edge.end());
}

void kruskal() {
    for (unsigned int i = 0; i < edge.size(); ++i) {
        // 구조적 바인딩으로 튜플 adj를 분리합니다.
        auto [weight, from, to] = edge[i];

        // 두 정점이 다른 집합에 있는 경우
        if (isDisjoint(from, to) == true) {
            Union(from, to);
            sumOfWeight += weight;
        }
    }
    cout << sumOfWeight << '\n';
}