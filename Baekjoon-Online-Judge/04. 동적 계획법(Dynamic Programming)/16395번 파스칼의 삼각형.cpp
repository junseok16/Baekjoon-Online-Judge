/*
* @title    : 16395번 파스칼의 삼각형(실버 5)
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

int bino(int n, int r);

// 메모이제이션을 위한 배열을 선언합니다.
vector<vector<int>> table;

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int N, K;
	cin >> N >> K;
	table = vector<vector<int>>(N + 1, vector<int>(K + 1, -1));
	cout << bino(N - 1, K - 1) << '\n';
	return 0;
}

int bino(int n, int r) {
	// 기본 조건입니다.
	if (n == r || r == 0) {
		return 1;
	}

	int& ret = table[n][r];

	// 메모이제이션으로 이전에 계산한 값을 불러옵니다.
	if (table[n][r] > -1) {
		return ret;
	}
	// 재귀 조건으로 피보나치 점화식을 정의합니다.
	else {
		return ret = bino(n - 1, r - 1) + bino(n - 1, r);
	}
}