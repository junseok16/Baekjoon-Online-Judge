/*
* @title    : 1058번 친구(실버 2)
* @content  : 너비 우선 탐색
* @author   : 탁준석
* @date     : 230201
* @time     : 0ms
* @memory   : 2160KB
* @state    : 완료
*/

#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

void makeGraph();
void bfsAll();
void bfs(int x);

vector<vector<int>> adj;
vector<int> dist, numOfTwoFriends;
queue<int> q;

int N;

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);
	makeGraph();
	bfsAll();
	return 0;
}

void makeGraph() {
	cin >> N;
	adj = vector<vector<int>>(N + 1, vector<int>());
	dist = vector<int>(N + 1, -1);
	numOfTwoFriends = vector<int>(N + 1, 0);

	for (int i = 1; i <= N; ++i) {
		string s;
		cin >> s;

		for (int j = 0; j < N; ++j) {
			if (s[j] == 'Y') { adj[i].push_back(j + 1); }
		}
	}
}

void bfsAll() {
	for (int i = 1; i <= N; ++i) {
		dist = vector<int>(N + 1, -1);
		bfs(i);
	}
	cout << *max_element(numOfTwoFriends.begin(), numOfTwoFriends.end()) << '\n';
}

void bfs(int x) {
	q.push(x);
	dist[x] = 0;

	int twoFriends = 0;
	while (!q.empty()) {
		int node = q.front();
		q.pop();

		for (const auto& e : adj[node]) {
			if (dist[e] < 0) {
				q.push(e);
				dist[e] = dist[node] + 1;
			}
		}
	}

	for (const auto& e : dist) {
		if (e == 1 || e == 2) { ++twoFriends; }
	}
	numOfTwoFriends[x] = twoFriends;
}