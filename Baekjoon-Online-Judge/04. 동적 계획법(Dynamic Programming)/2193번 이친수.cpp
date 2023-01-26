/*
* @title    : 2193번 이친수(실버 3)
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

	int N;
	cin >> N;
	vector<long long> pinary(N + 1, 0);

	// 점화식의 초깃값을 설정합니다.
	pinary[1] = pinary[2] = 1;

	// 상향 방식으로 이친수 점화식을 정의합니다.
	for (int i = 3; i <= N; ++i) {
		pinary[i] = pinary[i - 1] + pinary[i - 2];
	}
	cout << pinary[N] << '\n';
	return 0;
}