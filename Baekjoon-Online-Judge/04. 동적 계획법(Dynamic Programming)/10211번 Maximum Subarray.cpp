/*
* @title    : 10211번 Maximum Subarray(실버 4)
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
using namespace std;

int T, N;

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> T;
	for (int i = 0; i < T; ++i) {
		cin >> N;

		// 메모이제이션을 위한 배열을 선언합니다.
		vector<int> subarray(N + 1, 0);

		for (int j = 1; j <= N; ++j) {
			int num;
			cin >> num;

			// 상향 방식으로 최대 부분합 점화식을 정의합니다.
			if (subarray[j - 1] > 0) { subarray[j] = subarray[j - 1] + num; }
			else { subarray[j] = num; }
		}

		// 최대 부분합을 출력합니다.
		cout << *max_element(subarray.begin() + 1, subarray.end()) << '\n';
	}
	return 0;
}