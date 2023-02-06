/*
* @title    : 10816번 숫자 카드 2(실버 4)
* @content  : 이진 탐색
* @author   : 탁준석
* @date     : 230206
* @time     : 312ms
* @memory   : 3976KB
* @state    : 완료
*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N, M;

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> N;
	vector<int> seq(N, 0);
	for (int i = 0; i < N; ++i) { cin >> seq[i]; }
	sort(seq.begin(), seq.end());

	cin >> M;
	for (int j = 0; j < M; ++j) {
		int card;
		cin >> card;
		cout << upper_bound(seq.begin(), seq.end(), card) - lower_bound(seq.begin(), seq.end(), card) << ' ';
	}
	return 0;
}