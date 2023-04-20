/*
* @title    : 15656번 N과 M (7)(실버 3)
* @content  : 백트래킹
* @author   : 탁준석
* @date     : 230418
* @time     : 480ms
* @memory   : 2024KB
* @state    : 완료
*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void RepetitionPermutation(unsigned int index);

vector<int> set, sequence;

int N, M;

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> N >> M;
	set = vector<int>(N, 0);
	sequence = vector<int>(M, 0);
	
	for (int n = 0; n < N; ++n) {
		cin >> set[n];
	}
	sort(set.begin(), set.end());

	// 중복 순열을 구합니다.
	RepetitionPermutation(0);
	return 0;
}

void RepetitionPermutation(unsigned int index) {
	// 수열이 가득 찬 경우, 수열을 출력합니다.
	if (index == sequence.size()) {
		for (const auto& e : sequence) {
			cout << e << ' ';
		}
		cout << '\n';
		return;
	}

	// 수열이 가득 차지 않은 경우
	for (int i = 0; i < N; ++i) {
		// 중복되어야 하므로 visited 배열이 없어도 됩니다.
		sequence[index] = set[i];
		RepetitionPermutation(index + 1);
	}
}