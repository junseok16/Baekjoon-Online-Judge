/*
* @title    : 11403번 경로 찾기(실버 1)
* @content  : 깊이 우선 탐색
* @author   : 탁준석
* @date     : 230106
* @time     : 0ms
* @memory   : 2152KB
* @state    : 완료
*/

#include<iostream>
#include<vector>
using namespace std;

void MakeGraph();
void DFSAll();
void DFS(int x);

vector<vector<int>> adj;
vector<bool> visited;

int N;

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    MakeGraph();
    DFSAll();
}

void MakeGraph() {
    cin >> N;
    adj = vector<vector<int>>(N, vector<int>());

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            int e;
            cin >> e;

            // 인접 행렬을 인접 리스트로 재정의합니다.
            if (e == 1) {
                adj[i].push_back(j);
            }
        }
    }
}

void DFSAll() {
    for (int i = 0; i < N; i++) {
        visited = vector<bool>(N, false);
        DFS(i);

        for (int j = 0; j < N; j++) {
            cout << visited[j] << ' ';
        }
        cout << '\n';
    }
}

void DFS(int x) {
    for (int i = 0; i < adj[x].size(); i++) {
        if (visited[adj[x][i]] == false) {
            visited[adj[x][i]] = true;
            DFS(adj[x][i]);
        }
    }
}