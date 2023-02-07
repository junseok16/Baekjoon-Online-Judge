/*
* @title    : 11656번 접미사 배열(실버 4)
* @content  : 정렬
* @author   : 탁준석
* @date     : 230207
* @time     : 4ms
* @memory   : 2584KB
* @state    : 완료
*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<string> postfix;

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);

	string s;
	cin >> s;
	int stringSize = s.size();
	for (int i = 0; i < stringSize; ++i) {
		postfix.push_back(s);
		s = s.substr(1);
	}

	sort(postfix.begin(), postfix.end());
	for (const auto& e : postfix) {
		cout << e << '\n';
	}
	return 0;
}