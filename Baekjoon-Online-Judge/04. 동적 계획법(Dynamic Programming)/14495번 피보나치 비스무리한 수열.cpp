/*
* @title    : 14495번 피보나치 비스무리한 수열(실버 4)
* @content  : 동적 계획법
* @author   : 탁준석
* @date     : 230126
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

	int n;
	cin >> n;
	vector<long long> table(116 + 1, 0);

	// 점화식의 초깃값을 설정합니다.
	table[1] = table[2] = table[3] = 1;

	// 상향 방식으로 피보나치 비스무리한 점화식을 정의합니다.
	for (int i = 4; i <= 116; ++i) {
		table[i] = table[i - 1] + table[i - 3];
	}

	cout << table[n] << '\n';
	return 0;
}