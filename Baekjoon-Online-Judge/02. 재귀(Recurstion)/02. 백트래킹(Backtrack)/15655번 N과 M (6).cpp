/*
* @title    : 15655번 N과 M (6)(실버 3)
* @content  : 백트래킹
* @author   : 탁준석
* @date     : 230418
* @time     : 0ms
* @memory   : 2024KB
* @state    : 완료
*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void Combination(unsigned int index, int begin);

vector<int> sequence, set;
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

	// 조합을 구합니다.
	Combination(0, 0);
	return 0;
}

void Combination(unsigned int index, int begin) {
	// 수열이 가득 찬 경우, 수열을 출력합니다.
	if (index == sequence.size()) {
		for (const auto& e : sequence) {
			cout << e << ' ';
		}
		cout << '\n';
		return;
	}

	// 수열이 가득 차지 않은 경우
	for (int i = begin; i < N; ++i) {
		sequence[index] = set[i];
		Combination(index + 1, i + 1);
	}
}