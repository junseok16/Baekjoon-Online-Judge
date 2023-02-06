/*
* @title    : 1920번 수 찾기(실버 4)
* @content  : 이진 탐색
* @author   : 탁준석
* @date     : 230206
* @time     : 52ms
* @memory   : 2412KB
* @state    : 완료
*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> seq;

int N, M;

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> N;
	seq = vector<int>(N, 0);
	for (int i = 0; i < N; ++i) { cin >> seq[i]; }
	sort(seq.begin(), seq.end());

	cin >> M;
	for (int j = 0; j < M; ++j) {
		int t;
		cin >> t;
		cout << binary_search(seq.begin(), seq.end(), t) << '\n';
	}
	return 0;
}