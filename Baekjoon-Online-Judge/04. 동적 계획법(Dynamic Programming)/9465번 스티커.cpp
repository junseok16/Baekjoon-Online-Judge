/*
* @title    : 9465번 스티커(실버 1)
* @content  : 동적 계획법
* @author   : 탁준석
* @date     : 230126
* @time     : 100ms
* @memory   : 4664KB
* @state    : 완료
*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int T, n;

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> T;

	for (int i = 0; i < T; ++i) {
		cin >> n;

		vector<vector<int>> sticker(2, vector<int>(n, 0));
		vector<vector<int>> table(3, vector<int>(n, 0));

		for (int i = 0; i < n; ++i) { cin >> sticker[0][i]; }
		for (int j = 0; j < n; ++j) { cin >> sticker[1][j]; }

		// 점화식의 초깃값을 설정합니다.
		table[0][0] = sticker[0][0];
		table[1][0] = sticker[1][0];
		table[2][0] = 0;

		for (int k = 1; k < n; ++k) {
			// 1열의 스티커를 떼는 경우, 이전의 2열 스티커만 떼거나 1, 2열 스티커를 모두 떼지 않은 경우의 최댓값을 구합니다.
			table[0][k] = sticker[0][k] + max(table[1][k - 1], table[2][k - 1]);

			// 2열의 스티커를 떼는 경우, 이전의 1열 스티커만 떼거나 1, 2열 스티커를 모두 떼지 않은 경우의 최댓값을 구합니다.
			table[1][k] = sticker[1][k] + max(table[0][k - 1], table[2][k - 1]);

			// 스티커를 떼지 않는 경우, 이전의 1열 스티커만 떼거나 2열 스티커만 떼는 경우의 최댓값을 구합니다.
			table[2][k] = max(table[0][k - 1], table[1][k - 1]);
		}

		cout << max(max(table[0][n - 1], table[1][n - 1]), table[2][n - 1]) << '\n';
	}
	return 0;
}