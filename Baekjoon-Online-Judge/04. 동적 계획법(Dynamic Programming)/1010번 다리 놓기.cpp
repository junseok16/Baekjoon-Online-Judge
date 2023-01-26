/*
* @title    : 1010번 다리 놓기(실버 5)
* @content  : 동적 계획법
* @author   : 탁준석
* @date     : 230120
* @time     : 0ms
* @memory   : 2152KB
* @state    : 완료
*/

#include <iostream>
#include <vector>
using namespace std;

long long bino(int n, int r);

// 메모이제이션을 위한 배열을 선언합니다.
vector<vector<long long>> table;

int T, N, M;

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> T;
	for (int i = 0; i < T; ++i) {
		cin >> N >> M;
		table = vector<vector<long long>>(M + 1, vector<long long>(N + 1, -1));
		cout << bino(M, N) << '\n';
	}
	return 0;
}

long long bino(int n, int r) {
	// 기본 조건으로 n개 중에서 n개를 고르는 경우, n개 중에서 0개를 고르는 경우입니다.
	if (n == r || r == 0) {
		return table[n][r] = 1;
	}

	// 메모이제이션으로 이전에 계산된 값을 불러옵니다.
	if (table[n][r] != -1) {
		return table[n][r];
	}
	// 재귀 조건으로 이항 계수 점화식을 정의합니다.
	else {
		return table[n][r] = bino(n - 1, r - 1) + bino(n - 1, r);
	}
}