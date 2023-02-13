/*
* @title    : 2910번 빈도 정렬(실버 2)
* @content  : 정렬
* @author   : 탁준석
* @date     : 230212
* @time     : 0ms
* @memory   : 2160KB
* @state    : 완료
*/

#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
using namespace std;

bool compare(int a, int b);

unordered_map<int, pair<int, int>> umap;
vector<int> seq;

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int N, C;
	cin >> N >> C;
	seq = vector<int>(N, 0);

	for (int i = 0; i < N; ++i) {
		int n;
		cin >> n;
		seq[i] = n;

		if (umap.find(n) != umap.end()) {
			++umap[n].first;
		}
		else {
			umap[n].first = 1;
			umap[n].second = i;
		}
	}

	sort(seq.begin(), seq.end(), compare);
	for (const auto& e : seq) {
		cout << e << ' ';
	}
	return 0;
}

bool compare(int a, int b) {
	if (umap[a].first == umap[b].first) {
		return umap[a].second < umap[b].second;
	}
	return umap[a].first > umap[b].first;
}