/*
* @title    : 9507번 Generations of Tribbles(실버 4)
* @content  : 동적 계획법
* @author   : 탁준석
* @date     : 230127
* @time     : 0ms
* @memory   : 2020KB
* @state    : 완료
*/

#include <iostream>
#include <vector>
using namespace std;

long long koong(int n);

vector<long long> table;

int t, n;

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> t;
	table = vector<long long>(68, 0);

	for (int i = 0; i < t; ++i) {
		cin >> n;
		koong(n);
		cout << table[n] << '\n';
	}
	return 0;
}

long long koong(int n) {
	if (table[n] > 0) {
		return table[n];
	}

	if (n < 2) { return table[n] = 1; }
	else if (n == 2) { return table[n] = 2; }
	else if (n == 3) { return table[n] = 4; }
	else {
		return table[n] = koong(n - 1) + koong(n - 2) + koong(n - 3) + koong(n - 4);
	}
}