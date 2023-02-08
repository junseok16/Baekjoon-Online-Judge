/*
* @title    : 1149번 RGB거리(실버 1)
* @content  : 동적 계획법
* @author   : 탁준석
* @date     : 230125
* @time     : 0ms
* @memory   : 2164KB
* @state    : 완료
*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<vector<int>> cost, table;

int N;

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> N;
	cost = vector<vector<int>>(N, vector<int>(3, 0));
	table = vector<vector<int>>(N, vector<int>(3, 0));

	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < 3; ++j) {
			cin >> cost[i][j];
		}
	}
	// 1번 집의 RGB 비용을 초기화합니다.
	table[0][0] = cost[0][0];
	table[0][1] = cost[0][1];
	table[0][2] = cost[0][2];

	// 상향 방식으로 점화식을 구현합니다.
	for (int i = 1; i < N; ++i) {
		// table[i][j]는 i번째 집을 색깔 별로 칠하는 데 드는 최소 비용입니다.
		table[i][0] = cost[i][0] + min(table[i - 1][1], table[i - 1][2]);
		table[i][1] = cost[i][1] + min(table[i - 1][2], table[i - 1][0]);
		table[i][2] = cost[i][2] + min(table[i - 1][0], table[i - 1][1]);
	}

	// 모든 집을 칠하는 최소 비용을 출력합니다.
	cout << *min_element(table[N - 1].begin(), table[N - 1].end()) << '\n';
	return 0;
}