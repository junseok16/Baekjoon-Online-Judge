/*
* @title    : 1309번 동물원(실버 1)
* @content  : 동적 계획법
* @author   : 탁준석
* @date     : 230128
* @time     : 0ms
* @memory   : 2412KB
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

	// 메모이제이션을 위해 배열을 선언하고 초깃값을 설정합니다.
	vector<int> table(100000 + 1, 0);
	table[1] = 3;
	table[2] = 7;

	// 상향 방식으로 동물원 점화식을 구현합니다.
	for (int i = 3; i <= 100000; ++i) {
		table[i] = (2 * table[i - 1] + table[i - 2]) % 9901;
	}
	cout << table[N] << '\n';
	return 0;
}