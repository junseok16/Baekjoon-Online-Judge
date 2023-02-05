/*
* @title    : 2230번 수 고르기(골드 5)
* @content  : 투 포인터
* @author   : 탁준석
* @date     : 230205
* @time     : 20ms
* @memory   : 2412KB
* @state    : 완료
*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void twoPointers();

vector<int> seq;

int N, M;

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> N >> M;
	seq = vector<int>(N, 0);
	for (int i = 0; i < N; ++i) { cin >> seq[i]; }
	sort(seq.begin(), seq.end());
	twoPointers();
	return 0;
}

void twoPointers() {
	int ans = 2e9 + 1;
	int left = 0, right = 0;

	while (left <= right && right < N) {
		if (seq[right] - seq[left] < M) {
			++right;
		}
		else if (M < seq[right] - seq[left]) {
			ans = min(ans, seq[right] - seq[left]);
			++left;
		}
		else {
			ans = M;
			break;
		}
	}
	cout << ans << '\n';
}