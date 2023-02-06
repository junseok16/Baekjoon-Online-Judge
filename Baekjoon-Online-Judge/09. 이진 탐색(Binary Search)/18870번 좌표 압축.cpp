/*
* @title    : 18870번 좌표 압축(실버 2)
* @content  : 이진 탐색
* @author   : 탁준석
* @date     : 230206
* @time     : 480ms
* @memory   : 9840KB
* @state    : 완료
*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> seq, temp;

int N;

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> N;
	seq = vector<int>(N, 0);
	temp = vector<int>(N, 0);

	for (int i = 0; i < N; ++i) {
		cin >> seq[i];
		temp[i] = seq[i];
	}
	sort(temp.begin(), temp.end());

	// temp 배열에서 중복되는 요소를 제외합니다.
	temp.erase(unique(temp.begin(), temp.end()), temp.end());

	for (int i = 0; i < N; ++i) {
		cout << lower_bound(temp.begin(), temp.end(), seq[i]) - temp.begin() << ' ';
	}
	return 0;
}