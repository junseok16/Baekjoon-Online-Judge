/*
* @title    : 11053번 가장 긴 증가하는 부분 수열(실버 2)
* @content  : 동적 계획법
* @author   : 탁준석
* @date     : 230119
* @time     : 0ms
* @memory   : 2020KB
* @state    : 완료
*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> seq, subseq;

int N;

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> N;
	seq = vector<int>(N, 0);
	subseq = vector<int>(N, 0);
	subseq[0] = 1;

	for (int i = 0; i < N; ++i) {
		cin >> seq[i];
	}

	for (unsigned int i = 1; i < seq.size(); ++i) {
		int max = 0, index = 0;

		// subseq[i]는 seq 배열의 i번째 요소 이전에 나온 요소 중에서 seq[i]보다 값이 작은 요소가 갖는 부분 수열 길이의 최댓값입니다.
		for (int j = i - 1; j >= 0; --j) {
			if (seq[j] < seq[i] && max < subseq[j]) {
				max = subseq[j];
				index = j;
			}
		}
		subseq[i] = max == 0 ? 1 : subseq[index] + 1;
	}
	std::cout << *max_element(subseq.begin(), subseq.end()) << '\n';
	return 0;
}