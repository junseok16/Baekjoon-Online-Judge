/*
* @title    : 1991번 트리 순회(실버 1)
* @content  : 트리
* @author   : 탁준석
* @date     : 230214
* @time     : 0ms
* @memory   : 2020KB
* @state    : 완료
*/

#include <iostream>
#include <vector>
using namespace std;

void makeTree();
void preOrder(char node);
void inOrder(char node);
void postOrder(char node);

vector<char> leftChild, rightChild;

int N;

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);

	makeTree();
	preOrder('A');
	cout << '\n';
	inOrder('A');
	cout << '\n';
	postOrder('A');
	cout << '\n';
	return 0;
}

void makeTree() {
	cin >> N;
	leftChild = vector<char>(N, '.');
	rightChild = vector<char>(N, '.');

	for (int i = 0; i < N; ++i) {
		char node, left, right;
		cin >> node >> left >> right;
		leftChild[node - 'A'] = left;
		rightChild[node - 'A'] = right;
	}
}

void preOrder(char node) {
	cout << node;
	if (leftChild[node - 'A'] != '.') { preOrder(leftChild[node - 'A']); }
	if (rightChild[node - 'A'] != '.') { preOrder(rightChild[node - 'A']); }
}

void inOrder(char node) {
	if (leftChild[node - 'A'] != '.') { inOrder(leftChild[node - 'A']); }
	cout << node;
	if (rightChild[node - 'A'] != '.') { inOrder(rightChild[node - 'A']); }
}

void postOrder(char node) {
	if (leftChild[node - 'A'] != '.') { postOrder(leftChild[node - 'A']); }
	if (rightChild[node - 'A'] != '.') { postOrder(rightChild[node - 'A']); }
	cout << node;
}