/*
* @title    : 1764번 듣보잡(실버 4)
* @content  : 비정렬 연관 컨테이너
* @author   : 탁준석
* @date     : 230213
* @time     : 56ms
* @memory   : 7508KB
* @state    : 완료
*/

#include <iostream>
#include <unordered_set>
#include <set>
using namespace std;

unordered_set<string> us;
set<string> s;

int N, M;

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> N >> M;
	for (int i = 0; i < N; ++i) {
		string name;
		cin >> name;
		us.insert(name);
	}

	for (int i = 0; i < M; ++i) {
		string name;
		cin >> name;

		if (us.find(name) != us.end()) {
			s.insert(name);
		}
	}

	cout << s.size() << '\n';
	for (const auto& e : s) {
		cout << e << '\n';
	}
	return 0;
}