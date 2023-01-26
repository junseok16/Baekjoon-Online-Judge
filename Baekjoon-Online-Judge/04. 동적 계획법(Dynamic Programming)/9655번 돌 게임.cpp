/*
* @title    : 9655번 돌 게임(실버 5)
* @content  : 동적 계획법
* @author   : 탁준석
* @date     : 230115
* @time     : 0ms
* @memory   : 2020KB
* @state    : 완료
*/

#include <iostream>
#include <vector>
using namespace std;

int N;

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> N;
	if (N % 2 == 0) { cout << "CY" << '\n'; }
	else { cout << "SK" << '\n'; }
	return 0;
}