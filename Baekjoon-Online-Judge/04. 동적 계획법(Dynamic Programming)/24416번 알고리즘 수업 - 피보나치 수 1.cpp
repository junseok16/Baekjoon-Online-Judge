/*
* @title    : 24416번 알고리즘 수업 - 피보나치 수 1(브론즈 1)
* @content  : 동적 계획법
* @author   : 탁준석
* @date     : 230115
* @time     : 208ms
* @memory   : 2020KB
* @state    : 완료
*/

#include <iostream>
#include <vector>
using namespace std;

long long recursiveFibonacci(int n);
void dynamicFibonacci(int n);

// 메모이제이션을 위한 배열을 선언합니다
vector<int> table;

long long numOfRecursiveFibonacci = 0, numOfDynamicFibonacci = 0;

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	int n;
	cin >> n;

	recursiveFibonacci(n);
	dynamicFibonacci(n);
	cout << numOfRecursiveFibonacci << ' ' << numOfDynamicFibonacci << '\n';
	return 0;
}

// 재귀로 피보나치 함수를 구현합니다.
long long recursiveFibonacci(int n) {
	if (n == 1 || n == 2) {
		++numOfRecursiveFibonacci;
		return 1;
	}
	else {
		return recursiveFibonacci(n - 1) + recursiveFibonacci(n - 2);
	}
}

// 동적 계획법으로 피보나치 함수를 구현합니다.
void dynamicFibonacci(int n) {
	table = vector<int>(40 + 1, 0);
	table[1] = table[2] = 1;

	// 상향 방식(반복문)으로 점화식을 정의합니다.
	for (int i = 3; i <= n; ++i) {
		++numOfDynamicFibonacci;
		table[i] = table[i - 1] + table[i - 2];
	}
}