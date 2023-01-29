/*
* @title    : 10817번 세 수(브론즈 3)
* @content  : 정렬
* @author   : 탁준석
* @date     : 230129
* @time     : 0ms
* @memory   : 2020KB
* @state    : 완료
*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);

	vector<int> threeNumbers(3, 0);
	for (int i = 0; i < 3; ++i) {
		cin >> threeNumbers[i];
	}

	sort(threeNumbers.begin(), threeNumbers.end());
	cout << threeNumbers[1] << '\n';
	return 0;
}