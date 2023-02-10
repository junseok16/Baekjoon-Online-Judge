/*
* @title    : 1431번 시리얼 번호(실버 3)
* @content  : 정렬
* @author   : 탁준석
* @date     : 230210
* @time     : 0ms
* @memory   : 2028KB
* @state    : 완료
*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <cctype>
using namespace std;

bool compare(const string& a, const string& b);
int getDigits(const string& s);

vector<string> guitar;

int N;

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> N;
	guitar = vector<string>(N, "");
	for (int i = 0; i < N; ++i) {
		cin >> guitar[i];
	}

	sort(guitar.begin(), guitar.end(), compare);
	for (const auto& e : guitar) {
		cout << e << '\n';
	}
	return 0;
}

bool compare(const string& a, const string& b) {
	if (a.length() == b.length()) {
		if (getDigits(a) == getDigits(b)) {
			return a < b;
		}
		return getDigits(a) < getDigits(b);
	}
	return a.length() < b.length();
}

int getDigits(const string& s) {
	int sum = 0;

	// 문자열에서 숫자를 추출합니다.
	for (const char e : s) {
		// '0'부터 '9' 사이의 문자(char)가 입력될 경우, 0보다 큰 정수를 반환합니다.
		if (isdigit(e) > 0) {
			sum += e - '0';
		}
	}
	return sum;
}