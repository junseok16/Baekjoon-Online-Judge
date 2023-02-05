/*
* @title    : 1806번 부분합(골드 4)
* @content  : 투 포인터
* @author   : 탁준석
* @date     : 230205
* @time     : 8ms
* @memory   : 2412KB
* @state    : 완료
*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void twoPointers();

vector<int> seq;

int N, S;

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> N >> S;
	seq = vector<int>(N + 1, 0);
	for (int i = 0; i < N; ++i) { cin >> seq[i]; }
	twoPointers();
	return 0;
}

void twoPointers() {
	int left = 0, right = 0, sum = seq[0], length = seq.size() + 1;

	while (left <= right && right < N) {
		if (sum < S) {
			sum += seq[++right];
		}
		else if (S <= sum) {
			length = min(length, right - left + 1);
			sum -= seq[left++];
		}
	}

	if (length == seq.size() + 1) { length = 0; }
	cout << length << '\n';
}