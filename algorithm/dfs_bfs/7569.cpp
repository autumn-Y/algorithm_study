// https://www.acmicpc.net/problem/7569

// 3차원 배열이 되나봐!!
// queue<tuple<int, int, int,>> 로 3차원 큐도 가능
// q.push(make_tuple(1, 2, 3));
// get<0>(q.front()) == 1;

#include <iostream>
#include <stdio.h>
#include <queue>
#include <tuple>
using namespace std;

int n, m, h;
int day = 0;
int rot_to;
int tomato[101][101][101];
queue<tuple<int, int, int>> q;

int dx[6] = {-1, 1, 0, 0, 0, 0};
int dy[6] = {0, 0, -1, 1, 0, 0};
int dz[6] = {0, 0, 0, 0, -1, 1};

void bfs() {
    int x, y, z, nx, ny, nz;

    while(!q.empty()) {
        x = get<1>(q.front());
        y = get<2>(q.front());
        z = get<0>(q.front());
        q.pop();

        for(int i = 0; i < 6; i++) {
            nx = dx[i] + x;
            ny = dy[i] + y;
            nz = dz[i] + z;

            // 범위 확인 하기
            if(nx < 0 || nx >= n || ny < 0 || ny >= m || nz < 0 || nz >= h) continue;
            
            // 토마토가 있으면 익기 시작한 토마토의 날 + 1
            // 그리고 q에 넣기

            if(tomato[nz][nx][ny] == 0) {
                q.push({nz, nx, ny});
                rot_to++;
                tomato[nz][nx][ny] = tomato[z][x][y] + 1;

                if(tomato[nz][nx][ny] > day) day = tomato[nz][nx][ny];
            }
        }
    }
}

int main() {
    // m =  상자 가로칸, n = 상자 세로 칸, h = 쌓아올려지는 상자 수 (2 ~ 100)
    // 1: 익은 토마토, 0: 안익은 토마토, -1: 토마토가 들어있지 않은 칸
    // 토마토는 위, 아래, 왼쪽, 오른쪽, 앞, 뒤 여섯 방향
    // 위는 면이 하나 위, 아래는 면이 하나 아래
    // 뭐 bfs 돌려서 최소 일수 찾아내는 건 같은데 문제는 3차원 배열이다
    // 3차원이기 때문에 z축도 생각해야한다

    cin >> m >> n >> h;
    int est_to = n * m * h;
    rot_to = 0;

    // h층에
    for(int i = 0; i < h; i++) {
        // 가로
        for(int j = 0; j < n; j++) {
            // 세로
            for(int k = 0; k < m; k++) {
                cin >> tomato[i][j][k];

                if(tomato[i][j][k] == 1) {
                    q.push({i, j, k});
                    rot_to++;
                }

                else if(tomato[i][j][k] == -1) est_to--;
            }
        }
    }

    // 저장될 때부터 모두 익어있는 상태
    if(est_to == rot_to) {
        cout << 0;
        return 0;
    }
    
    bfs();

    if(est_to == rot_to) cout << day - 1;
    else cout << -1;
}