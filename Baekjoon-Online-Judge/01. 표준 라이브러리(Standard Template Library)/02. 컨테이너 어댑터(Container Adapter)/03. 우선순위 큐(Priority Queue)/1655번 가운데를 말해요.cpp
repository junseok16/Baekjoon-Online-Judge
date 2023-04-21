/*
* @title    : 1655번 가운데를 말해요(골드 2)
* @content  : 우선순위 큐
* @author   : 탁준석
* @date     : 230420
* @time     : 32ms
* @memory   : 2792KB
* @state    : 완료
*/

#include <iostream>
#include <vector>
#include <queue>
using namespace std;

priority_queue<int, vector<int>, greater<int>> minPQ;
priority_queue<int, vector<int>, less<int>> maxPQ;

int N;

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> N;
	for (int i = 0; i < N; ++i) {
		// 최대 힙과 최소 힙으로 중앙값을 구합니다.
		int integer;
		cin >> integer;

		// 두 힙의 크기가 같은 경우, 새로운 숫자는 최대 힙에 넣습니다.
		if (maxPQ.size() == minPQ.size()) {
			maxPQ.push(integer);
		}
		// 두 힙의 크기가 다른 경우, 새로운 숫자는 최소 힙에 넣습니다.
		else {
			minPQ.push(integer);
		}
		
		if (!maxPQ.empty() && !minPQ.empty()) {
			// 최대 힙의 최댓값이 최소 힙의 최솟값보다 큰 경우, 두 값을 맞바꿉니다.
			if (maxPQ.top() > minPQ.top()) {
				int maxTop = maxPQ.top();
				maxPQ.pop();

				int minTop = minPQ.top();
				minPQ.pop();

				maxPQ.push(minTop);
				minPQ.push(maxTop);
			}
		}

		// 중앙값을 외칩니다.
		cout << maxPQ.top() << '\n';
	}
	return 0;
}