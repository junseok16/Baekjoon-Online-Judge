/*
* @title    : 14916번 거스름돈(실버 5)
* @content  : 동적 계획법
* @author   : 탁준석
* @date     : 230117
* @time     : 0ms
* @memory   : 2412KB
* @state    : 완료
*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int change(int n);

// 메모이제이션을 위한 배열을 선언합니다.
vector<int> table;

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n;
	cin >> n;
	table = vector<int>(100000 + 1, 0);
	cout << change(n) << '\n';
	return 0;
}

int change(int n) {
	// 점화식의 초깃값을 설정합니다.
	table[1] = table[3] = -1;
	table[2] = table[5] = 1;
	table[4] = table[7] = 2;
	table[6] = 3;
	table[8] = 4;

	// 상향 방식으로 점화식을 정의합니다.
	for (int i = 9; i <= 100000; ++i) {
		table[i] = min(table[i - 2], table[i - 5]) + 1;
	}
	return table[n];
}