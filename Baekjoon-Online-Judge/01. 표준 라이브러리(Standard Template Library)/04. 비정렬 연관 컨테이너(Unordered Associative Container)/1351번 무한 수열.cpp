/*
* @title    : 1351번 무한 수열(골드 5)
* @content  : 비정렬 연관 컨테이너
* @author   : 탁준석
* @date     : 230212
* @time     : 0ms
* @memory   : 2156KB
* @state    : 완료
*/

#include <iostream>
#include <unordered_map>
using namespace std;

long long infiniteSequence(long long n);

unordered_map<long long, long long> table;

long long N, P, Q;

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> N >> P >> Q;

	// 점화식의 초기값을 설정합니다.
	table[0] = 1;
	cout << infiniteSequence(N) << '\n';
	return 0;
}

long long infiniteSequence(long long n) {
	if (table.count(n) > 0) {
		return table[n];
	}

	// 기본 조건입니다.
	if (n == 0) {
		return 1;
	}
	// 하향 방식으로 무한 수열 점화식을 정의합니다.
	else {
		return table[n] = infiniteSequence(n / P) + infiniteSequence(n / Q);
	}
}