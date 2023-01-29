/*
* @title    : 2750번 수 정렬하기(브론즈 2)
* @content  : 정렬
* @author   : 탁준석
* @date     : 230129
* @time     : 0ms
* @memory   : 2020KB
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

	vector<int> seq(N, 0);
	for (int i = 0; i < N; ++i) { cin >> seq[i]; }

	sort(seq.begin(), seq.end());
	for (const auto& e : seq) {
		cout << e << '\n';
	}
	return 0;
}