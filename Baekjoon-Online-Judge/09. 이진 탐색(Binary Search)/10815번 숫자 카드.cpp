/*
* @title    : 10815번 숫자 카드(실버 5)
* @content  : 이진 탐색
* @author   : 탁준석
* @date     : 230419
* @time     : 236ms
* @memory   : 3952KB
* @state    : 완료
*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> cards;

int N, M;

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> N;
	cards = vector<int>(N, 0);
	for (int n = 0; n < N; ++n) {
		cin >> cards[n];
	}
	sort(cards.begin(), cards.end());

	cin >> M;
	for (int m = 0; m < M; ++m) {
		int number;
		cin >> number;

		if (binary_search(cards.begin(), cards.end(), number)) {
			cout << 1 << ' ';
		}
		else {
			cout << 0 << ' ';
		}
	}
	return 0;
}