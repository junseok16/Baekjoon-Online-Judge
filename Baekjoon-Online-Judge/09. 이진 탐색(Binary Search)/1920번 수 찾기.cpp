/*
* @title    : 1920번 수 찾기(실버 4)
* @content  : 이진 탐색
* @author   : 탁준석
* @date     : 230205
* @time     : 52ms
* @memory   : 2412KB
* @state    : 완료
*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int binarySearch(int m);

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
		cout << binarySearch(t) << '\n';
	}
	return 0;
}

int binarySearch(int t) {
	int left = 0;
	int right = seq.size() - 1;

	while (left <= right) {
		int mid = (left + right) / 2;

		if (t > seq[mid]) {
			left = mid + 1;
		}
		else if (t < seq[mid]) {
			right = mid - 1;
		}
		else {
			return 1;
		}
	}
	return 0;
}