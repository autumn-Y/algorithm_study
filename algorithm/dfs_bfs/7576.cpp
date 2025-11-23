// https://www.acmicpc.net/problem/7576

#include <iostream>
#include <stdio.h>
#include <queue>
#include <utility>
using namespace std;

int m, n;
int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};

int tomato[1001][1001];
int rot_to = 0; 
int day = 0;
queue<pair<int, int>> q;

void bfs() {
    int x, y, nx, ny;

    while(!q.empty()) {
        x = q.front().first;
        y = q.front().second;
        q.pop();

        for(int i = 0; i < 4; i++) {
            nx = x + dx[i];
            ny = y + dy[i];
            
            // 범위를 넘어가거나
            // 이미 방문한 토마토면 pass
            if(nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
            
            if(tomato[nx][ny] == 0) {
                tomato[nx][ny] = tomato[x][y] + 1;
                q.push(make_pair(nx, ny));
                rot_to++;

                if(tomato[nx][ny] > day) day = tomato[nx][ny];
            }
        }
    }
}

int main() {
    // input : 상자의 크기를 나타내는 두 정수 m, n (2 ~ 1000)
    // m = 상자 가로 칸의 수, n = 상자 세로 칸의 수
    // 그 다음부턴 m개의 상자 가로줄에 들어있는 토마토의 상태
    // 1 = 익은 토마토, 0 = 익지 않은 토마토, -1 = 토마토가 들어있지 않은 칸
    // output: 토마토가 모두 익을 때까지 최소 날짜
    // 0 = 저장 시 부터 모든 토마토가 익은 상태일시
    // -1 = 모두 익지 못하는 상황

    // 조건 1. 익은 토마토의 상하좌우에 있는 토마토가 익음
    // 이건 BFS다!
    // 우선 토마토가 있는 모든 정점을 큐에 집어넣어
    // 익은 토마토는 BFS를 돌면서 또 확인 되겠지?
    // visited가 필요할 거고!
    // 모든 토마토가 익었는지 확인하려면 토마토 익힐 때마다 토마토 개수세서
    // 익은 토마토 개수 = 전체 - 토마토 없는 칸 이면 끝!

    cin >> m >> n;
    int est_ans = m * n;

    for(int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> tomato[i][j];  
            // 익은 토마토 좌표 q에 삽입하고 개수세기
            if(tomato[i][j] == 1) {
                q.push(make_pair(i, j));
                rot_to++;
            }
            
            // 토마토 없으면 visited = true 로 만들기
            if(tomato[i][j] == -1) {
                est_ans--;
            }
        }
    }

    if(est_ans == rot_to) {
        cout << 0;
        return 0;
    }

    bfs();

    if(est_ans == rot_to) cout << day - 1;
    else cout << -1;

    return 0;
}