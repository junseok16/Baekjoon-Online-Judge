/*
* @title    : 9933번 민균이의 비밀번호(브론즈 1)
* @content  : 비정렬 연관 컨테이너
* @author   : 탁준석
* @date     : 230213
* @time     : 0ms
* @memory   : 2160KB
* @state    : 완료
*/

#include <iostream>
#include <algorithm>
#include <unordered_set>
using namespace std;

unordered_set<string> uset;

int N;

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> N;
	for (int i = 0; i < N; ++i) {
		string pw;
		cin >> pw;

		string rpw = pw;
		reverse(rpw.begin(), rpw.end());

		// 원본 문자열과 뒤집은 문자열이 같은 경우
		if (pw == rpw) {
			cout << pw.length() << ' ' << pw[pw.length() / 2] <<'\n';
			break;
		}

		// 원본 문자열 혹은 뒤집은 문자열이 uset에 있는 경우
		if (uset.find(pw) != uset.end()) {
			cout << pw.length() << ' ' << pw[pw.length() / 2] <<'\n';
			break;
		}
		else {
			// 원본 문자열과 뒤집은 문자열을 uset에 넣습니다.
			uset.insert(pw);
			uset.insert(rpw);
		}
	}
	return 0;
}