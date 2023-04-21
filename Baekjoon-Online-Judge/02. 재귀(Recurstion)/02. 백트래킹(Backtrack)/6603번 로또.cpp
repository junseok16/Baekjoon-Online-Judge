/*
* @title    : 6603번 로또(실버 2)
* @content  : 백트래킹
* @author   : 탁준석
* @date     : 230418
* @time     : 0ms
* @memory   : 2020KB
* @state    : 완료
*/

#include <iostream>
#include <vector>
using namespace std;

void Lottery();
void Combination(int index, int begin);

vector<int> S, sequence;

int K;

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);
	Lottery();
	return 0;
}

void Lottery() {
	while (true) {
		cin >> K;
		if (K == 0) {
			break;
		}

		S = vector<int>(K, 0);
		sequence = vector<int>(6, 0);
		for (int k = 0; k < K; ++k) {
			cin >> S[k];
		}

		// 조합을 구합니다.
		Combination(0, 0);
		cout << '\n';
	}
}

void Combination(int index, int begin) {
	// 로또 번호를 다 뽑은 경우, 로또 번호를 출력합니다.
	if (index == 6) {
		for (const auto& e : sequence) {
			cout << e << ' ';
		}
		cout << '\n';
		return;
	}

	for (int i = begin; i < K; ++i) {
		sequence[index] = S[i];
		Combination(index + 1, i + 1);
	}
}