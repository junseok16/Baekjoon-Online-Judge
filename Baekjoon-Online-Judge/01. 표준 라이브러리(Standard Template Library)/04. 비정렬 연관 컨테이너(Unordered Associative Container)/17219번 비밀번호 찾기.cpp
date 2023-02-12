/*
* @title    : 17219번 비밀번호 찾기(실버 4)
* @content  : 비정렬 연관 컨테이너
* @author   : 탁준석
* @date     : 230212
* @time     : 140ms
* @memory   : 16052KB
* @state    : 완료
*/

#include <iostream>
#include <unordered_map>
using namespace std;

unordered_map<string, string> umap;

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	int N, M;
	cin >> N >> M;
	for (int i = 0; i < N; ++i) {
		string site, password;
		cin >> site >> password;
		umap.insert({ site, password });
	}

	for (int j = 0; j < M; ++j) {
		string site;
		cin >> site;
		cout << umap[site] << '\n';
	}
	return 0;
}