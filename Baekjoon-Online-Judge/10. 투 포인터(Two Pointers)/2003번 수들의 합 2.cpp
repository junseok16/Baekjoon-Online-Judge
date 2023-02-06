/*
* @title    : 2003번 수들의 합 2(실버 4)
* @content  : 투 포인터
* @author   : 탁준석
* @date     : 230205
* @time     : 0ms
* @memory   : 2220KB
* @state    : 완료
*/

#include <iostream>
#include <vector>
using namespace std;

void twoPointers();

vector<long long> seq;

int N, M;

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> N >> M;
	seq = vector<long long>(N + 1, 0);
	for (int i = 0; i < N; ++i) { cin >> seq[i]; }
	twoPointers();
	return 0;
}

void twoPointers() {
	long long sum = seq[0], numOfCase = 0;
	int left = 0, right = 0;

	while (left < N && right < N) {
		if (M < sum) {
			sum -= seq[left++];
		}
		else if (sum < M) {
			sum += seq[++right];
		}
		else {
			sum += seq[++right];
			++numOfCase;
		}
	}
	cout << numOfCase << '\n';
}