/*
* @title    : 2751번 수 정렬하기 2(실버 5)
* @content  : 정렬
* @author   : 탁준석
* @date     : 230206
* @time     : 276ms
* @memory   : 5928KB
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

	sort(seq.begin(), seq.end(), less<int>());
	for (const auto& e : seq) {
		cout << e << '\n';
	}
	return 0;
}