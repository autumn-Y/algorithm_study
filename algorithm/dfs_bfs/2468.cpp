#include <iostream>
#include <queue>
#include <cstring>
#include <algorithm>
using namespace std;

// 광역변수 : 2차원 배열, visitied, cnt
int area[100][100];
bool visited[100][100] = {false};
int cnt, N;

// 상하좌우 영역 탐색
int dx[4] = { -1, 1, 0, 0 };
int dy[4] = { 0, 0, -1, 1 };

void bfs(int x, int y, int h) {
	// bfs 시작 지점에서 물에 잠기지 않은 영역 찾기
	int bx, by, ax, ay;
	queue<pair<int, int>> q;

	q.push(make_pair(x, y));

	while (!q.empty()) {
		bx = q.front().first;
		by = q.front().second;
		q.pop();

		// for문 돌면서 상하좌우 확인
		for (int i = 0; i < 4; i++) {
			// 이동 후 좌표 계산
			ax = bx + dx[i];
			ay = by + dy[i];

			// 영역 밖이면 넘어가기
			if (ax < 0 || ax >= N || ay < 0 || ay >= N) continue;

			if (visited[ax][ay]) continue;
			visited[ax][ay] = true;

			if (area[ax][ay] <= h) continue;
			q.push(make_pair(ax, ay));
		}
	}
}

void search(int height) {
	// 인수로 들어온 height만큼 잠길 때 영역 탐색
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (visited[i][j]) continue;

			// 방문 처리하고
			visited[i][j] = true;

			if (area[i][j] <= height) continue;
			
			// 비의 양보다 높을 때에만 탐색하기
			bfs(i, j, height);
			cnt++;
		}
	}
}



int main() {
	// input: 2차원 배열 N
	cin >> N;
	int ans = -1;

	// 가장 높은 높이 정보를 알아야함
	// bfs를 1부터 hamx까지 돌면서 안전한 영역이 최대인 경우를 찾아야 함
	int hmax = -1;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> area[i][j];
			if (area[i][j] > hmax) hmax = area[i][j];
		}
	}

	// output : 물에 잠기지 않는 안전한 영역의 최대 개수
	for (int h = 0; h <= hmax; h++) {
		// cnt, visited 초기화
		cnt = 0;
		for (int i = 0; i < N; i++) {
			memset(visited[i], false, 100);
		}

		search(h);
		if (cnt > ans) ans = cnt;
	}	

	cout << ans;
}