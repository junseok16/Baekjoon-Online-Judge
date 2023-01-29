/*
* @title    : 1699번 제곱수의 합(실버 2)
* @content  : 동적 계획법
* @author   : 탁준석
* @date     : 230129
* @time     : 36ms
* @memory   : 2412KB
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

	// table[i]는 i를 제곱수의 합으로 나타내는 항의 최소 개수입니다.
	vector<int> table(100000 + 1, 0);

	// 점화식의 초깃값을 설정합니다.
	table[1] = 1;

	// 상향 방식으로 제곱수의 합 점화식을 구현합니다.
	for (int i = 2; i <= 100000; ++i) {
		table[i] = table[1] + table[i - 1];
		for (int j = 2; j * j <= i; ++j) {
			table[i] = min(table[i], 1 + table[i - j * j]);
		}
	}
	cout << table[N] << '\n';
	return 0;
}