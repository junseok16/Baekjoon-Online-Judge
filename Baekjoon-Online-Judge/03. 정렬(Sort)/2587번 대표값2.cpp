/*
* @title    : 2587번 대표값2(브론즈 2)
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

	int sum = 0;
	vector<int> seq(5, 0);

	for (int i = 0; i < 5; ++i) { cin >> seq[i]; }
	sort(seq.begin(), seq.end());

	for (const auto& e : seq) { sum += e; }
	cout << sum / 5 << '\n' << seq[2] << '\n';
	return 0;
}