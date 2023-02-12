/*
* @title    : 7785번 회사에 있는 사람(실버 5)
* @content  : 비정렬 연관 컨테이너
* @author   : 탁준석
* @date     : 230212
* @time     : 84ms
* @memory   : 12884KB
* @state    : 완료
*/

#include <iostream>
#include <unordered_set>
#include <vector>
#include <algorithm>
using namespace std;

unordered_set<string> uset;

int n;

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;
	for (int i = 0; i < n; ++i) {
		string name, status;
		cin >> name >> status;

		if (status == "enter") { uset.insert(name); }
		else if (status == "leave") { uset.erase(name); }
	}

	vector<string> employee(uset.begin(), uset.end());
	sort(employee.begin(), employee.end(), greater<string>());
	for (const auto& e : employee) {
		cout << e << '\n';
	}
}