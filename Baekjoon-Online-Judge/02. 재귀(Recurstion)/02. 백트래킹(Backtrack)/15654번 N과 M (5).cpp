/*
* @title    : 15654번 N과 M (5)(실버 3)
* @content  : 백트래킹
* @author   : 탁준석
* @date     : 230418
* @time     : 28ms
* @memory   : 2024KB
* @state    : 완료
*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void Permutation(unsigned int index);

vector<int> sequence, set;
vector<bool> visited;
int N, M;

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> N >> M;
	set = vector<int>(N, 0);
	visited = vector<bool>(N, false);
	sequence = vector<int>(M, 0);

	for (int n = 0; n < N; ++n) {
		cin >> set[n];
	}
	sort(set.begin(), set.end());

	// 순열을 구합니다.
	Permutation(0);
	return 0;
}

void Permutation(unsigned int index) {
	// 수열이 가득 찬 경우, 수열을 출력합니다.
	if (index == sequence.size()) {
		for (const auto& e : sequence) {
			cout << e << ' ';
		}
		cout << '\n';
		return;
	}

	// 수열이 가득 차지 않은 경우
	for (int i = 0; i < N; ++i) {
		if (visited[i] == false) {
			visited[i] = true;
			sequence[index] = set[i];
			Permutation(index + 1);
			visited[i] = false;
		}
	}
}