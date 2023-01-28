/*
* @title    : 1904번 01타일(실버 3)
* @content  : 동적 계획법
* @author   : 탁준석
* @date     : 230128
* @time     : 12ms
* @memory   : 9836KB
* @state    : 완료
*/

#include <iostream>
#include <vector>
using namespace std;

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int N;
	cin >> N;

	vector<long long> table(1000001, 0);

	// 점화식의 초깃값을 설정합니다.
	table[1] = 1;
	table[2] = 2;

	// 상향 방식으로 01타일 점화식을 정의합니다.
	for (int i = 3; i <= N; ++i) {
		// table[i]는 i개의 타일로 만들 수 있는 2진 수열의 가짓수입니다.
		table[i] = (table[i - 1] + table[i - 2]) % 15746;
	}

	cout << table[N] << '\n';
	return 0;
}