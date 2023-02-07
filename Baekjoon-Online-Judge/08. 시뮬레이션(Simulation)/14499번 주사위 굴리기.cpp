/*
* @title    : 14499번 주사위 굴리기(골드 4)
* @content  : 시뮬레이션
* @author   : 탁준석
* @date     : 230207
* @time     : 0ms
* @memory   : 2020KB
* @state    : 완료
*/

#include <iostream>
#include <vector>
using namespace std;

void copy(int x, int y);

vector<vector<int>> map;
int N, M, X, Y, K;
int Top, Bottom, Left, Right, Front, Back;

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> N >> M >> X >> Y >> K;
	map = vector<vector<int>>(N, vector<int>(M, 0));

	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < M; ++j) {
			cin >> map[i][j];
		}
	}

	// 동쪽은 1, 서쪽은 2, 북쪽은 3, 남쪽은 4입니다.
	for (int k = 0; k < K; ++k) {
		int direction;
		cin >> direction;

		int temp;
		switch (direction) {
		
		// 동쪽으로 이동한 경우
		case 1:
			// 범위를 벗어나는 경우
			if (Y + 1 >= M) { break; }
			temp = Top;
			Top = Left;
			Left = Bottom;
			Bottom = Right;
			Right = temp;
			copy(X, ++Y);
			break;

		// 서쪽으로 이동한 경우
		case 2:
			if (Y - 1 < 0) { break; }
			temp = Top;
			Top = Right;
			Right = Bottom;
			Bottom = Left;
			Left = temp;
			copy(X, --Y);
			break;
	
		// 북쪽으로 이동한 경우
		case 3:
			if (X - 1 < 0) { break; }
			temp = Top;
			Top = Back;
			Back = Bottom;
			Bottom = Front;
			Front = temp;
			copy(--X, Y);
			break;

		// 남쪽으로 이동한 경우
		case 4:
			if (X + 1 >= N) { break; }
			temp = Top;
			Top = Front;
			Front = Bottom;
			Bottom = Back;
			Back = temp;
			copy(++X, Y);
			break;
		}
	}
}

void copy(int x, int y) {
	// 이동한 칸의 숫자가 0인 경우
	if (map[x][y] == 0) {
		map[x][y] = Bottom;
	}
	// 이동한 칸의 숫자가 0이 아닌 경우
	else {
		Bottom = map[x][y];
		map[x][y] = 0;
	}
	cout << Top << '\n';
}