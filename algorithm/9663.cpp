// https://www.acmicpc.net/problem/9663

#include <iostream>
using namespace std;

int n;
// 0이면 가능, 1이면 불가능
int board[15][15];
int ans = 0;

void cover(int a, int b) {
    // 1. 가로
    for(int i = 0; i < n; i++) {
        board[a][i] = 1;
    } 

    // 2. 세로
    for(int i = 0; i < n; i++) {
        board[i][b] = 1;
    }

    // 3. 대각선
    // 4방향 대각선 좌표 싹 바꿔가면서 확인하기
    int dx[4] = {-1, -1, 1, 1};
    int dy[4] = {1, -1, 1, -1};
    int x = a;
    int y = b;

    for(int i = 0; i < 4; i++) {
        int nx = x + dx[i];
        int ny = y + dy[i];

        while(nx >=0 && nx <n && ny >=0 && ny <n) {
            board[nx][ny] = 1;
            x = nx;
            y = ny;
            nx = x + dx[i];
            ny = y + dy[i];
        }
    }
}

void uncover(int a, int b) {
    // 1. 가로
    for(int i = 0; i < n; i++) {
        board[a][i] = 0;
    } 

    // 2. 세로
    for(int i = 0; i < n; i++) {
        board[i][b] = 0;
    }

    // 3. 대각선
    // 4방향 대각선 좌표 싹 바꿔가면서 확인하기
    int dx[4] = {-1, -1, 1, 1};
    int dy[4] = {1, -1, 1, -1};
    int x = a;
    int y = b;

    for(int i = 0; i < 4; i++) {
        int nx = x + dx[i];
        int ny = y + dy[i];

        while(nx >=0 && nx <n && ny >=0 && ny <n) {
            board[nx][ny] = 0;
            x = nx;
            y = ny;
            nx = x + dx[i];
            ny = y + dy[i];
        }
    }
}

bool check() {
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            // 아직 놓을 곳이 있다
            if(board[i][j] == 0) return false;
        }
    }

    return true;
}

void search(int queen) {
    // 종료 조건 1. 모든 퀸을 보드에 놓음
    if(queen == 0) {
        ans++;
        return;
    }

    // 종료 조건 2. 체스 판에 놓을 곳이 없는 경우
    if(check()) {
        return;
    }

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            // 놓을 수 있는 자리이면 체스 놓기
            if(board[i][j] == 0) {
                board[i][j] = 1;
                cover(i, j);
                search(queen - 1);
                uncover(i, j);
            }
        }
    }
}       

int main() {
    // 퀸은 가로, 새로, 대각선 방향으로
    // 앞에 기물이 가로막지 않는 한 원하는 만큼 이동 가능

    // NxN 체스판에 퀸 N개가 서로 공격할 수 없게 놓는 경우의 수

    // DFS로 체스말을 하나씩 놓아가면서 다음 경우 찾기
    // 그리고 체스 하나를 두면 보드에 놓으면 안되는 경우 업데이트 하기
    cin >> n;
    search(n);
    cout << ans;
}