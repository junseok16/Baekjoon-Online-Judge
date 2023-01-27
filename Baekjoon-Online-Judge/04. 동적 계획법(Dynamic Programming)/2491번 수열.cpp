/*
* @title    : 2491번 수열(실버 4)
* @content  : 동적 계획법
* @author   : 탁준석
* @date     : 230127
* @time     : 8ms
* @memory   : 3196KB
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
	vector<int> increaseSeq(N + 1, 0);
	vector<int> decreaseSeq(N + 1, 0);
	vector<int> seq(N + 1, 0);

	for (int i = 1; i <= N; ++i) {
		cin >> seq[i];
	}

	// 연속해서 커지는 수열의 길이를 구합니다.
	int increment = 0;
	for (int i = 1; i <= N; ++i) {
		// 상향 방식으로 점화식을 정의합니다.
		if (seq[i - 1] <= seq[i]) {
			increaseSeq[i] = increaseSeq[i - 1] + 1;
		}
		else { increaseSeq[i] = 1; }
		
		// 가장 긴 길이를 갱신합니다.
		if (increaseSeq[i] > increment) {
			increment = increaseSeq[i];
		}
	}

	// 연속해서 작아지는 수열의 길이를 구합니다.
	int decrement = 0;
	for (int i = 1; i <= N; ++i) {
		// 상향 방식으로 점화식을 정의합니다.
		if (seq[i - 1] >= seq[i]) {
			decreaseSeq[i] = decreaseSeq[i - 1] + 1;
		}
		else { decreaseSeq[i] = 1; }

		// 가장 긴 길이를 갱신합니다.
		if (decreaseSeq[i] > decrement) {
			decrement = decreaseSeq[i];
		}
	}
	
	cout << max(increment, decrement) << '\n';
	return 0;
}