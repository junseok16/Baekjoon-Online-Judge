/*
* @title    : 9934번 완전 이진 트리(실버 1)
* @content  : 트리
* @author   : 탁준석
* @date     : 230215
* @time     : 0ms
* @memory   : 2208KB
* @state    : 완료
*/

#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

vector<vector<int>> tree;
vector<int> seq;

int K;

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> K;
	int size = pow(2, K);

	tree = vector<vector<int>>(K, vector<int>());
	seq = vector<int>(size - 1, 0);
	for (int i = 0; i < size - 1; ++i) { cin >> seq[i]; }

	int n = K - 1;
	while (n >= 0) {
		for (int i = pow(2, K - n - 1) - 1; i < size - 1; i = i + pow(2, K - n)) {
			tree[n].push_back(seq[i]);
		}
		--n;
	}

	for (const auto& e : tree) {
		for (const auto& f : e) {
			cout << f << ' ';
		}
		cout << '\n';
	}
	return 0;
}