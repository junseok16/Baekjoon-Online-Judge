/*
* @title    : 2696번 중앙값 구하기(골드 2)
* @content  : 우선순위 큐
* @author   : 탁준석
* @date     : 230422
* @time     : 0ms
* @memory   : 2156KB
* @state    : 완료
*/

#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int T, M;

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> T;
	for (int t = 0; t < T; ++t) {
		priority_queue<int, vector<int>, less<int>> maxHeap;
		priority_queue<int, vector<int>, greater<int>> minHeap;
		vector<int> median;

		cin >> M;
		for (int m = 0; m < M; ++m) {
			int number;
			cin >> number;

			// 두 힙이 비어있는 경우, 최대 힙에 숫자를 넣습니다.
			if (maxHeap.size() == minHeap.size()) {
				maxHeap.push(number);
			}
			else {
				minHeap.push(number);
			}

			// 최대 힙의 최대 숫자가 최소 힙의 최소 숫자보다 큰 경우, 맞바꿉니다.
			if (maxHeap.size() > 0 && minHeap.size() > 0) {
				if (maxHeap.top() > minHeap.top()) {
					int maxNumber = maxHeap.top();
					int minNumber = minHeap.top();

					maxHeap.pop();
					minHeap.pop();

					maxHeap.push(minNumber);
					minHeap.push(maxNumber);
				}
			}
			
			// 홀수 번째 수를 읽을 때마다 중앙값을 저장합니다.
			if (m % 2 == 0) {
				median.push_back(maxHeap.top());
			}
		}

		// 중앙값의 개수를 출력합니다.
		cout << median.size() << '\n';

		// 중앙값을 한 줄에 10개씩 출력합니다.
		for (unsigned int j = 0; j < median.size(); ++j) {
			cout << median[j] << ' ';

			if (j % 10 == 9) {
				cout << '\n';
			}
		}
		cout << '\n';
	}

	return 0;
}