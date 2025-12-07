// https://www.acmicpc.net/problem/1987
// bfs는 최단거리를 구할 때!!
// 이 문제처럼 최대 칸 수를 구해야 할 땐 dfs!!

#include <iostream>
#include <queue>
#include <string>
using namespace std;

int r, c;
int ans = 0;
int board[21][21];
bool visited[26] = {false};
int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, -1, 1};

void dfs(int x, int y, int t) {
    // 종료 조건?
    if(t > ans) ans = t;

    for(int i = 0; i < 4; i++) {
        int nx = x + dx[i];
        int ny = y + dy[i];

        if(nx >= 0 && nx < r && ny >=0 && ny < c && !visited[board[nx][ny]]) {
            visited[board[nx][ny]] = true;
            dfs(nx, ny, t + 1);
            visited[board[nx][ny]] = false;
        }
    }
}

int main() {
    // 들렀던 알파벳인지 봐야함
    cin >> r >> c;
    string s;

    for(int i = 0; i < r; i++) {
        cin >> s;
        for(int j = 0; j < c; j++) {
            board[i][j] = s[j] - 'A';
        }
    }

    visited[board[0][0]] = true;
    dfs(0, 0, 1);
    
    cout << ans;
    return 0;
}