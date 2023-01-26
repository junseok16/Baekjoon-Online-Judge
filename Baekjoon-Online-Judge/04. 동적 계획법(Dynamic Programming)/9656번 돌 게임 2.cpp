/*
* @title    : 9656번 돌 게임 2(실버 4)
* @content  : 동적 계획법
* @author   : 탁준석
* @date     : 230119
* @time     : 0ms
* @memory   : 2020KB
* @state    : 완료
*/

#include <iostream>
using namespace std;

int N;

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> N;
	if (N % 2 == 0) { cout << "SK" << '\n'; }
	else { cout << "CY" << '\n'; }
	return 0;
}