/*
* @title    : 1759번 암호 만들기(골드 5)
* @content  : 백트래킹
* @author   : 탁준석
* @date     : 230418
* @time     : 0ms
* @memory   : 2024KB
* @state    : 완료
*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void Combination(int index, int begin, int v, int c);

vector<char> set, password;

int L, C;

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> L >> C;
	set = vector<char>(C, 0);
	password = vector<char>(L, 0);

	for (int c = 0; c < C; ++c) {
		cin >> set[c];
	}
	sort(set.begin(), set.end());

	// 조합을 구합니다.
	Combination(0, 0, 0, 0);
	return 0;
}

void Combination(int index, int begin, int v, int c) {
	// 최소 한 개의 모음과 최소 두 개의 자음을 만족하는 비밀번호를 출력합니다.
	if (index == L && 1 <= v && 2 <= c) {
		for (const auto& e : password) {
			cout << e;
		}
		cout << '\n';
		return;
	}

	for (int i = begin; i < C; ++i) {
		password[index] = set[i];
		
		switch (set[i]) {
		// 문자가 모음인 경우, 모음의 수를 증가시킵니다.
		case 'a':
		case 'i':
		case 'u':
		case 'e':
		case 'o':
			Combination(index + 1, i + 1, v + 1, c);
			break;

		// 문자가 자음인 경우, 자음의 수를 증가시킵니다.
		default:
			Combination(index + 1, i + 1, v, c + 1);
			break;
		}
	}
}