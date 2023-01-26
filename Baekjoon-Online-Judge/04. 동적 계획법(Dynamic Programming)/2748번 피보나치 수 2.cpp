/*
* @title    : 2748번 피보나치 수 2(브론즈 1)
* @content  : 동적 계획법
* @author   : 탁준석
* @date     : 230115
* @time     : 0ms
* @memory   : 2020KB
* @state    : 완료
*/

#include <iostream>
#include <vector>
using namespace std;

long long fibonacci(int n);

// 피보나치 수의 범위를 저장할 수 있도록 long long으로 배열을 선언합니다.
vector<long long> table;

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n;
	cin >> n;
	// 메모이제이션하기 위한 테이블을 정의합니다.
	table = vector<long long>(n + 1, 0);
	cout << fibonacci(n) << '\n';
	return 0;
}

long long fibonacci(int n) {
	// 상향 방식(반복문)으로 점화식을 정의합니다.
	for (int i = 0; i <= n; ++i) {
		if (i == 0 || i == 1) {
			table[i] = i;
		}
		else {
			table[i] = table[i - 2] + table[i - 1];
		}
	}
	return table[n];
}