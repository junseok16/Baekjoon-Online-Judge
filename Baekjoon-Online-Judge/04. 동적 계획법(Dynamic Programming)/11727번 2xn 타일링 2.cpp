/*
* @title    : 11727번 2xn 타일링 2(실버 3)
* @content  : 동적 계획법
* @author   : 탁준석
* @date     : 230109
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

	// 메모이제이션을 위한 배열을 선언합니다.
	vector<int> table(1000 + 1, 0);

	// 점화식의 초깃값을 설정합니다.
	table[1] = 1;
	table[2] = 3;
	table[3] = 5;

	// 상향 방식으로 2xn 타일링 점화식을 정의합니다.
	for (int i = 4; i <= n; ++i) {
		table[i] = (table[i - 1] + 2 * table[i - 2]) % 10007;
	}

	cout << table[n] << '\n';
	return 0;
}