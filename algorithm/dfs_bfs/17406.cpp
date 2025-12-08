// https://www.acmicpc.net/problem/17406

#include <iostream>
#include <vector>
#include <tuple>
#include <utility>
using namespace std;

int n, m, k;
int board[51][51];
vector<tuple<int, int, int>> v;
int ans = 10000;
bool visited[7] = {false};

void arr_turn(int order) {
    // 시계방향으로 돌리기
    int r = get<0>(v[order]);
    int c = get<1>(v[order]);
    int s = get<2>(v[order]);

    int s_x = r - s;
    int s_y = c - s;
    int e_x = r + s;
    int e_y = c + s;
    int dist = e_x - s_x + 1;

    int before, now, x, y, nx, ny;
    while(dist != 1) {
        // 시계방향 업데이트 ->
        x = s_x;
        y = s_y;
        ny = y + 1;
        
        before = board[x][y];
        while(ny <= e_y) {
            now = board[x][ny];
            board[x][ny] = before;
            before = now;
            ny++;
        }

        // |
        // v
        y = e_y;
        nx = x + 1;
        before = board[x][y];

        while(nx <= e_x) {
            now = board[nx][y];
            board[nx][y] = before;
            before = now;
            nx++;
        }

        // <-
        x = e_x;
        ny = y - 1;
        before = board[x][y];

        while(ny >= s_y) {
            now = board[x][ny];
            board[x][ny] = before;
            before = now;
            ny--;
        }

        // ^
        // |
        y = s_y;
        nx = x - 1;
        before = board[x][y];

        while(nx >= s_x) {
            now = board[nx][y];
            board[nx][y] = before;
            before = now;
            nx--;
        }

        // 시작점, 끝점 dist update
        s_x = s_x + 1;
        e_x = e_x - 1;
        dist = e_x - s_x + 1;
    }
}

void arr_return(int order) {
    // 시계 반대 방향으로 돌리기
    // end point 부터 업뎃치면 된다                                     
    int r = get<0>(v[order]);
    int c = get<1>(v[order]);
    int s = get<2>(v[order]);

    int s_x = r - s;
    int s_y = c - s;
    int e_x = r + s;
    int e_y = c + s;
    int dist = e_x - s_x + 1;

    int before, now, x, y, nx, ny;
    while(dist != 1) {
        // ^
        // |
        

        // <-

        // |
        // v

        // ->

        // 시작점, 끝점 dist update
        s_x = s_x + 1;
        e_x = e_x - 1;
        dist = e_x - s_x + 1;
    }
}

void search(int depth) {
    // 종료 조건 1. dfs detph가 k가 되었을 때
    if(depth == k) {
        int temp;
        int min = 10000;
        for(int i = 0; i < n; i++) {
            temp = 0;
            for(int j = 0; j < m; j++) {
                temp += board[i][j];
            }
            if(temp < min) min = temp;
        }

        if(min < ans) ans = min;
        return;
    }

    // dfs 구간 : k개의 순서 있는 중복 없는 순열
    for(int i = 0; i < k; i++) {
        if(visited[i] == false) {
            visited[i] = true;
            arr_turn(i);
            search(depth + 1);
            arr_return(i);
            visited[i] = false;
        }
    }
}

int main() {
    // 포인트는 회전 k개의 회전 연산을 모두 한다는 것
    // dfs로 각 경우의 수 마다 계산하고 돌아오는 거 반복해야겠는데?
    cin >> n >> m >> k;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            cin >> board[i][j];
        }
    }

    for(int i = 0; i < k; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        v.push_back({a, b, c});
    }

    search(0);
    cout << ans;
}