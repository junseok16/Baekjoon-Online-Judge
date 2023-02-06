/*
* @title    : 10814번 나이순 정렬(실버 5)
* @content  : 정렬
* @author   : 탁준석
* @date     : 230206
* @time     : 44ms
* @memory   : 9848KB
* @state    : 완료
*/

#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

bool compare(const pair<int, string>& a, const pair<int, string>& b);

int N;

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> N;
	vector<pair<int, string>> member;
	for (int i = 0; i < N; ++i) {
		int age;
		string name;
		cin >> age >> name;
		member.push_back({ age, name });
	}

	stable_sort(member.begin(), member.end(), compare);
	for (const auto& e : member) {
		cout << e.first << ' ' << e.second << '\n';
	}
	return 0;
}

bool compare(const pair<int, string>& a, const pair<int, string>& b) {
	return a.first < b.first;
}