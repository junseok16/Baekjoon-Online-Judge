#include <iostream>
#include <algorithm>
#include <vector>
#include <tuple>
using namespace std;

bool compare(const tuple<string, int, int, int>& a, const tuple<string, int, int, int>& b);
int N;

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> N;
	vector<tuple<string, int, int, int>> info(N);

	// 학생 수만큼 이름, 국어, 영어, 수학 점수를 받습니다.
	for (int i = 0; i < N; ++i) {
		string name;
		int korean, english, math;
		cin >> name >> korean >> english >> math;
		info[i] = { name, korean, english, math };
	}

	// 비교 함수에 근거하여 배열을 정렬합니다.
	sort(info.begin(), info.end(), compare);
	for (const auto& e : info) {
		cout << get<0>(e) << '\n';
	}
	return 0;
}

// 주어진 조건에 맞도록 배열을 정렬합니다.
bool compare(const tuple<string, int, int, int>& a, const tuple<string, int, int, int>& b) {
	if (get<1>(a) == get<1>(b)) {
		if (get<2>(a) == get<2>(b)) {
			if (get<3>(a) == get<3>(b)) {
				// 모든 점수가 같으면 이름이 사전 순으로 증가하는 순서로 정렬합니다.
				return get<0>(a) < get<0>(b);
			}
			// 국어와 영어 점수가 같으면 수학 점수가 감소하는 순서로 정렬합니다.
			return get<3>(a) > get<3>(b);
		}
		// 국어 점수가 같으면 영어 점수가 증가하는 순서로 정렬합니다.
		return get<2>(a) < get<2>(b);
	}
	// 국어 점수가 감소하는 순서로 정렬합니다.
	return get<1>(a) > get<1>(b);
}