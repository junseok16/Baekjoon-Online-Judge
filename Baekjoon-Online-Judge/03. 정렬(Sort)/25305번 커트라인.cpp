/*
* @title    : 25305번 커트라인(브론즈 2)
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

	int N, k;
	cin >> N >> k;

	vector<int> grade(N, 0);
	for (int i = 0; i < N; ++i) { cin >> grade[i]; }
	sort(grade.begin(), grade.end());

	cout << grade[N - k] << '\n';
	return 0;
}