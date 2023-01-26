/*
* @title    : 13301번 타일 장식물(실버 5)
* @content  : 동적 계획법
* @author   : 탁준석
* @date     : 230117
* @time     : 0ms
* @memory   : 2020KB
* @state    : 완료
*/

#include <iostream>
#include <vector>
using namespace std;

// 메모이제이션을 위한 배열을 선언합니다.
vector<long long> table;

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int N;
	cin >> N;
	table = vector<long long>(80 + 1, 0);

	// 점화식의 초깃값을 설정합니다.
	table[1] = 4;
	table[2] = 6;

	// 상향 방식으로 점화식을 구현합니다.
	for (int i = 3; i <= 80; ++i) {
		table[i] = table[i - 1] + table[i - 2];
	}
	cout << table[N] << '\n';
	return 0;
}