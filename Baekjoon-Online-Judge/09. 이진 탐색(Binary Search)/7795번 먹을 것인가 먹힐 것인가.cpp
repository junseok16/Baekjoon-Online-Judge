/*
* @title    : 7795번 먹을 것인가 먹힐 것인가(실버 3)
* @content  : 이진 탐색
* @author   : 탁준석
* @date     : 230207
* @time     : 32ms
* @memory   : 2420KB
* @state    : 완료
*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> A, B;
int T, N, M;

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> T;
	for (int i = 0; i < T; ++i) {
		cin >> N >> M;
		A = vector<int>(N, 0);
		B = vector<int>(M, 0);
		for (int j = 0; j < N; ++j) { cin >> A[j]; }
		for (int j = 0; j < M; ++j) { cin >> B[j]; }

		sort(A.begin(), A.end());
		sort(B.begin(), B.end());

		int numOfPair = 0;
		for (const auto& e : A) {
			numOfPair += lower_bound(B.begin(), B.end(), e) - B.begin();
		}
		cout << numOfPair << '\n';
	}
	return 0;
}