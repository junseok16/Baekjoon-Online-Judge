/*
* @title    : 1309번 동물원(실버 1)
* @content  : 동적 계획법
* @author   : 탁준석
* @date     : 230128
* @time     : 8ms
* @memory   : 7532KB
* @state    : 완료
*/

#include <iostream>
#include <vector>
using namespace std;

const int mod = 9901;

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int N;
	cin >> N;

	// 메모이제이션을 위해 배열을 선언하고 초깃값을 설정합니다.
	vector<vector<int>> table(100000 + 1, vector<int>(3, 0));
	table[1][0] = table[1][1] = table[1][2] = 1;

	// 상향 방식으로 동물원 점화식을 구현합니다.
	for (int i = 2; i <= 100000; ++i) {
		// 현재 XO로 가두는 경우, 이전에는 OX, XX로 가둘 수 있습니다.
		table[i][0] = (table[i - 1][1] + table[i - 1][2]) % mod;

		// 현재 OX로 가두는 경우, 이전에는 XO, XX로 가둘 수 있습니다.
		table[i][1] = (table[i - 1][0] + table[i - 1][2]) % mod;

		// 현재 XX로 가두는 경우, 이전에는 XO, OX, XX로 가둘 수 있습니다.
		table[i][2] = (table[i - 1][0] + table[i - 1][1] + table[i - 1][2]) % mod;
	}
	cout << (table[N][0] + table[N][1] + table[N][2]) % mod << '\n';
	return 0;
}