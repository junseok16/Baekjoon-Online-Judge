/*
* @title    : 5648번 역원소 정렬(실버 4)
* @content  : 정렬
* @author   : 탁준석
* @date     : 230210
* @time     : 0ms
* @memory   : 2292KB
* @state    : 완료
*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

vector<long long> seq;

int n;

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;
	for (int i = 0; i < n; ++i) {
		string e;
		cin >> e;
		reverse(e.begin(), e.end());

		// 문자열을 숫자로 변환합니다.
		seq.push_back(stoll(e));
	}

	sort(seq.begin(), seq.end());
	for (const auto& e : seq) { cout << e << '\n'; }
	return 0;
}