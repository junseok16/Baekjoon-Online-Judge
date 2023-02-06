/*
* @title    : 10825번 국영수(실버 4)
* @content  : 정렬
* @author   : 탁준석
* @date     : 230206
* @time     : 84ms
* @memory   : 6716KB
* @state    : 완료
*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <tuple>
using namespace std;

bool compare(const tuple<string, int, int, int>& a, const tuple<string, int, int, int>& b);

int N;

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> N;
	vector<tuple<string, int, int, int>> grade(N);
	for (int i = 0; i < N; ++i) {
		string name;
		int korean, english, math;
		cin >> name >> korean >> english >> math;
		grade[i] = { name, korean, english, math };
	}

	sort(grade.begin(), grade.end(), compare);
	for (const auto& e : grade) {
		cout << get<0>(e) << '\n';
	}
	return 0;
}

bool compare(const tuple<string, int, int, int>& a, const tuple<string, int, int, int>& b) {
	auto [nameA, koreanA, englishA, mathA] = a;
	auto [nameB, koreanB, englishB, mathB] = b;

	if (koreanA == koreanB) {
		if (englishA == englishB) {
			if (mathA == mathB) {
				return nameA < nameB;
			}
			return mathA > mathB;
		}
		return englishA < englishB;
	}
	return koreanA > koreanB;
}