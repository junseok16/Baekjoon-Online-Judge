/*
* @title    : 1654번 랜선 자르기(실버 2)
* @content  : 이진 탐색
* @author   : 탁준석
* @date     : 230419
* @time     : 4ms
* @memory   : 2220KB
* @state    : 완료
*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void ParametricSearch();

typedef long long ll;

vector<ll> cables;
int K, N;

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> K >> N;
	cables = vector<ll>(K, 0);
	for (int k = 0; k < K; ++k) {
		cin >> cables[k];
	}
	sort(cables.begin(), cables.end());

	// 매개변수 탐색합니다.
	ParametricSearch();
	return 0;
}

void ParametricSearch() {
	ll bottom = 1;
	ll top = cables[K - 1];

	// 자를 수 있는 최대 랜선의 길이입니다.
	ll maxLength = 0;

	while (bottom <= top) {
		ll amountOfCable = 0;
		ll mid = (bottom + top) / 2;

		// mid 만큼 랜선을 자른 조각의 수를 셉니다.
		for (const auto& cable : cables) {
			amountOfCable += cable / mid;
		}

		// 랜선 조각의 수가 N보다 적은 경우
		if (amountOfCable < N) {
			top = mid - 1;
		}
		// 랜선 조각의 수가 N보다 많거나 같은 경우
		else if (amountOfCable >= N) {
			maxLength = max(maxLength, mid);
			bottom = mid + 1;
		}
	}

	cout << maxLength << '\n';
}