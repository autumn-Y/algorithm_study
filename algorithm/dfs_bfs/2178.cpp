// https://www.acmicpc.net/problem/2178

#include <iostream>
#include <stdio.h>
#include <string>
#include <queue>
#include <utility>
using namespace std;

// 전역변수
int map[101][101];

// 상하좌우 탐색
int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};

void bfs() {
    // dfs를 돌면서 0은 피하고 1은 +1을 해
    // 당연히 visited 안됐는지 확인 해야하고
    // 동서남북을 탐색할 변수의 값에 + 1을 해야하고
    // n, m 에 나오는 결과가 최솟값이 될거야
    // queue 써서 상하좌우 탐색하기

    queue<pair<int, int>> q;
    q.push(make_pair(0, 0));

    int x, y, nx, ny;

    while(!q.empty()) {
        x = q.front().first;
        y = q.front().second;
        q.pop();

        for(int i = 0; i < 4; i++) {
            nx = x + dx[i];
            ny = y + dy[i];
            
            // 이제 미로 값 변경하기
            if(map[nx][ny] == 1) {
                map[nx][ny] += map[x][y];
                q.push(make_pair(nx, ny));
            }

            else continue;
        }
    }
}

int main() {
    // input: N, M (2 ~ 100) => 2차원 배열로 가능
    // string으로 받아서 배열에 쪼개서 넣기

    int n, m;
    string str;
    
    scanf("%d %d", &n, &m);

    for(int i = 0 ; i < n; i++) {
        cin >> str;
        for(int j = 0; j < m; j++) {
            map[i][j] = str[j] - '0';
        }
    }

    
    bfs();
    cout << map[n-1][m-1];
}