/*
* @title    : 5576번 콘테스트(브론즈 2)
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

	vector<int> W(10, 0);
	vector<int> K(10, 0);
	for (unsigned int i = 0; i < W.size(); ++i) { cin >> W[i]; }
	for (unsigned int j = 0; j < K.size(); ++j) { cin >> K[j]; }

	sort(W.begin(), W.end());
	sort(K.begin(), K.end());

	int sumOfW = 0, sumOfK = 0;
	for (int i = 7; i < 10; ++i) { sumOfW += W[i]; }
	for (int j = 7; j < 10; ++j) { sumOfK += K[j]; }
	cout << sumOfW << ' ' << sumOfK << '\n';
	return 0;
}