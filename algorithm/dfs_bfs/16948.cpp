// https://www.acmicpc.net/problem/16948

#include <iostream>
#include <queue>
#include <tuple>
using namespace std;

int n, r1, c1, r2, c2;
bool visited [201][201];
int dx[6] = {-2, -2, 0, 0, 2, 2};
int dy[6] = {-1, 1, -2, 2, -1, 1};
int ans = -1;

void bfs() {
    queue<tuple<int, int, int>> q;
    q.push({r1, c1, 0});
    visited[r1][c1] = true;

    while(!q.empty()) {
        int x = get<0>(q.front());
        int y = get<1>(q.front());
        int t = get<2>(q.front());
        q.pop();

        if(x == r2 && y == c2) {
            ans = t;
            return;
        }

        for(int i = 0; i < 6; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];
            if(nx >= 0 && nx <= n && ny >=0 && ny <= n && !visited[nx][ny]) {
                q.push({nx, ny, t + 1});
                visited[nx][ny] = true;
            }
        }
    }
}   

int main() {
    cin >> n;
    cin >> r1 >> c1 >> r2 >> c2;

    bfs();

    cout << ans;
    return 0; 
}