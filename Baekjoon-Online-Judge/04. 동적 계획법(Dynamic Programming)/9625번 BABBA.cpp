/*
* @title    : 9625번 BABBA(실버 5)
* @content  : 동적 계획법
* @author   : 탁준석
* @date     : 230120
* @time     : 0ms
* @memory   : 2020KB
* @state    : 완료
*/

#include <iostream>
#include <vector>
using namespace std;

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int K;
	cin >> K;
	vector<pair<int, int>> table(K + 1);
	
	// 점화식의 초깃값을 설정합니다.
	table[0] = { 1, 0 };
	table[1] = { 0, 1 };

	// 상향 방식으로 점화식을 정의합니다.
	for (int i = 2; i <= K; ++i) {
		table[i].first = table[i - 1].first + table[i - 2].first;
		table[i].second = table[i - 1].second + table[i - 2].second;
	}

	cout << table[K].first << ' ' << table[K].second << '\n';
	return 0;
}