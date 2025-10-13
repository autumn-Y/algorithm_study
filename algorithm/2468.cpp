// https://www.acmicpc.net/problem/2468

#include <iostream>
#include <vector>
#include <queue>
#include <cstring>
#include <algorithm>
using namespace std;

// 광역 2차원 배열
int arr[100][100];
bool visited[100][100] = {false};
int cnt, N;

// 상하좌우
int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};

void search(int height) {
    // 안전한 영역 = 상하좌우가 다 붙어있는 것, 1칸도 1개의 영역
    // 현재 height랑 비교해서 잠기는지 여부 판단
    // 잠기면 visited true
    // 안잠기면 bfs 실행

    // 전체를 돌아야해
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < N; j++) {
            if(visited[i][j]) continue;
            bfs(i, j, height);
            cnt++;
        }
    }
}

void bfs(int x, int y, int height) {
    // x, y 좌표를 모두 저장하는 큐
    queue<pair<int, int>> q;
    
    ///
}

int main() {
    // input : 2차원 배열의 행과 열 개수 N (2이상 100이하)
    // 영역의 높이 정보 입력
    cin >> N;

    // 입력을 받으면서 최대 높이를 알아야해
    // 높이 1부터 최대 높이까지 안전한 영역의 개수를 구해야함
    int hmax = -1;
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < N; j++) {
            cin >> arr[i][j];
            if(arr[i][j] > hmax) hmax = arr[i][j];
        }
    }

    // output : 장마철에 물에 잠기지 않는 안전한 영역의 최대 개수
    
    // main에서는 높이따라 탐색하기만 할게요
    int result = 0;
    for(int i = 1; i <= hmax; i++) {
        cnt = 0;
        search(i);
        if(result < cnt) result = cnt;

        // visited 초기화
        for(int j = 0; j < N; j++) {
            memset(visited[j], false, N);
        }
    }

    cout << result;
}