/*
* @title    : 2670번 연속부분최대곱(실버 4)
* @content  : 동적 계획법
* @author   : 탁준석
* @date     : 230127
* @time     : 0ms
* @memory   : 2020KB
* @state    : 완료
*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdio>
using namespace std;

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int N;
	cin >> N;

	// 메모이제이션을 위한 배열을 선언합니다.
	vector<double> real(N + 1, 0.0);
	real[0] = 1.0;

	for (int i = 1; i <= N; ++i) {
		cin >> real[i];
		
		// 이전까지 곱한 값이 1.0보다 크거나 같은 경우, 이번 실수도 곱해야 최대값이 나옵니다.
		if (real[i - 1] >= 1.0) { real[i] *= real[i - 1]; }
	}

	double max = *max_element(real.begin() + 1, real.end());

	// 소숫점 셋째 자리(.3)까지 double 형식(lf)의 실수를 출력합니다.
	printf("%.3lf", max);
	return 0;
}