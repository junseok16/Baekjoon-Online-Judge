/*
* @title    : 1463번 1로 만들기(실버 3)
* @content  : 동적 계획법
* @author   : 탁준석
* @date     : 230128
* @time     : 4ms
* @memory   : 5928KB
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

	// 메모이제이션을 위한 배열을 선언합니다.
	vector<int> table(1000000 + 1, 0);

	// 점화식의 초깃값을 설정합니다.
	table[2] = table[3] = 1;
	
	// 상향 방식으로 1로 만들기 점화식을 정의합니다.
	for (int i = 4; i <= 1000000; ++i) {
		// table[i]는 i를 1로 만들기 위해 필요한 최소 연산 횟수입니다.
		table[i] = table[i - 1] + 1;
		if (i % 2 == 0) { 
			table[i] = min(table[i], table[i / 2] + 1);
		}
		if (i % 3 == 0) { 
			table[i] = min(table[i], table[i / 3] + 1);
		}
	}
	cout << table[N] << '\n';
	return 0;
}