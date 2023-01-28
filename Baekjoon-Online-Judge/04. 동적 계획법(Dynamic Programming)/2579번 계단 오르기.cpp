/*
* @title    : 2579번 계단 오르기(실버 3)
* @content  : 동적 계획법
* @author   : 탁준석
* @date     : 230128
* @time     : 0ms
* @memory   : 2152KB
* @state    : 완료
*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int N;
	cin >> N;

	vector<int> stair(300 + 1, 0);
	vector<vector<int>> table(300 + 1, vector<int>(3, 0));

	for (int i = 1; i <= N; ++i) { cin >> stair[i]; }

	// 점화식의 초깃값을 설정합니다.
	table[1][0] = stair[1];
	table[1][1] = stair[1];
	table[1][2] = 0;

	// 상향 방식으로 계단 오르기 점화식을 구현합니다.
	for (int i = 2; i <= 300; ++i) {
		// 이전 계단을 밟고 현재 계단을 밟은 경우
		table[i][0] = stair[i] + table[i - 1][1];

		// 이전 계단을 밟지 않고 현재 계단을 밟은 경우
		table[i][1] = stair[i] + table[i - 1][2];

		// 현재 계단을 밟지 않은 경우
		table[i][2] = max(table[i - 1][0], table[i - 1][1]);
	}

	// 마지막 계단을 밟았을 때, 점수의 최댓값을 출력합니다.
	cout << *max_element(table[N].begin(), table[N].end() - 1) << '\n';
	return 0;
}