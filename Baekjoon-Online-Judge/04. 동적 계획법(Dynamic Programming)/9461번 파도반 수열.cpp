/*
* @title    : 9461번 파도반 수열(실버 3)
* @content  : 동적 계획법
* @author   : 탁준석
* @date     : 230128
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

	int T, N;
	vector<long long> P(101, 0);

	cin >> T;

	// 점화식의 초깃값을 설정합니다.
	P[1] = P[2] = P[3] = 1;
	P[4] = P[5] = 2;


	// P[i]는 나선에 있는 정삼각형의 한 변의 길이입니다.
	for (int i = 6; i <= 100; ++i) {
		P[i] = P[i - 1] + P[i - 5];
	}

	for (int i = 0; i < T; ++i) {
		cin >> N;
		cout << P[N] << '\n';
	}
	return 0;
}