/*
* @title    : 17626번 Four Squares(실버 3)
* @content  : 동적 계획법
* @author   : 탁준석
* @date     : 230129
* @time     : 12ms
* @memory   : 2216KB
* @state    : 완료
*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n;
	cin >> n;

	// table[i]는 i를 제곱수의 합으로 나타내는 항의 최소 개수입니다.
	vector<int> table(50000 + 1, 0);

	// 점화식의 초깃값을 설정합니다.
	table[1] = 1;

	// 상향 방식으로 Four Squares 점화식을 구현합니다.
	for (int i = 2; i <= 50000; ++i) {
		table[i] = table[1] + table[i - 1];
		for (int j = 2; j * j <= i; ++j) {
			table[i] = min(table[i], table[i - j * j] + 1);
		}
	}
	cout << table[n] << '\n';
	return 0;
}