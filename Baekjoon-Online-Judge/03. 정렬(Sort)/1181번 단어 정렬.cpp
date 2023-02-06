/*
* @title    : 1181번 단어 정렬(실버 5)
* @content  : 정렬
* @author   : 탁준석
* @date     : 230206
* @time     : 20ms
* @memory   : 3976KB
* @state    : 완료
*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool compare(const string& a, const string& b);

int N;

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> N;
	vector<string> guitar(N);
	for (int i = 0; i < N; ++i) { cin >> guitar[i]; }

	sort(guitar.begin(), guitar.end(), compare);
	guitar.erase(unique(guitar.begin(), guitar.end()), guitar.end());
	for (const auto& e : guitar) { cout << e << '\n'; }
	return 0;
}

bool compare(const string& a, const string& b) {
	if (a.length() == b.length()) {
		return a < b;
	}
	return a.length() < b.length();
}