/*
* @title    : 20055번 컨베이어 벨트 위의 로봇(골드 5)
* @content  : 시뮬레이션
* @author   : 탁준석
* @date     : 230207
* @time     : 48ms
* @memory   : 2024KB
* @state    : 완료
*/

#include <iostream>
#include <queue>
using namespace std;

deque<pair<int, bool>> belt;
int N, K;

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> N >> K;
	for (int i = 0; i < 2 * N; ++i) {
		int durability;
		cin >> durability;
		belt.push_back({ durability, false });
	}

	// belt[0]은 올리는 위치, belt[N - 1]은 내리는 위치입니다.
	int numOfZeroBelt = 0, level = 0;
	while (numOfZeroBelt < K) {
		++level;

		// 벨트가 각 칸 위에 있는 로봇과 함께 한 칸 이동합니다.
		belt.push_front(belt.back());
		belt.pop_back();

		// 내리는 위치에 있는 칸에 로봇이 도착한 경우, 로봇을 내립니다.
		if (belt[N - 1].second == true) { belt[N - 1].second = false; }

		// 가장 먼저 벨트에 올라간 로봇부터 한 칸 이동합니다.
		for (int i = N - 2; i > 0; --i) {
			if (belt[i].second == true && belt[i + 1].second == false && belt[i + 1].first > 0) {
				belt[i + 1].second = true;
				belt[i].second = false;

				// 내구도가 0이 된 칸의 개수를 셉니다.
				if (--belt[i + 1].first == 0) { ++numOfZeroBelt; }
			}
		}

		// 내리는 위치에 있는 칸에 로봇이 도착한 경우, 로봇을 내립니다.
		if (belt[N - 1].second == true) { belt[N - 1].second = false; }

		// 올리는 위치에 있는 칸의 내구도가 0보다 크면 로봇을 올립니다.
		if (belt[0].first > 0) {
			belt[0].second = true;

			// 내구도가 0이 된 칸의 개수를 셉니다.
			if (--belt[0].first == 0) { ++numOfZeroBelt; }
		}
	}
	cout << level <<'\n';
	return 0;
}