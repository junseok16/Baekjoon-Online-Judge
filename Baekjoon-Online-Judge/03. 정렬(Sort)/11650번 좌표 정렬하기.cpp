/*
* @title    : 11650번 좌표 정렬하기(실버 5)
* @content  : 정렬
* @author   : 탁준석
* @date     : 230206
* @time     : 44ms
* @memory   : 3688KB
* @state    : 완료
*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N;

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> N;
	vector<pair<int, int>> coordinate;
	for (int i = 0; i < N; ++i) {
		int x, y;
		cin >> x >> y;
		coordinate.push_back({ x, y });
	}

	sort(coordinate.begin(), coordinate.end());
	for (const auto& e : coordinate) {
		cout << e.first << ' ' << e.second << '\n';
	}
	return 0;
}