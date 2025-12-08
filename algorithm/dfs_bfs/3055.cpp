// https://www.acmicpc.net/problem/3055

#include <iostream>
#include <queue>
#include <tuple>
#include <utility>
#include <string>
using namespace std;

int r, c, s_x, s_y, d_x, d_y;
int ans = 5000;
char map[51][51];
int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};

bool h_visited[51][51];
bool w_visited[51][51];
queue<pair<int, int>> water;

// 아이디어는 물도 bfs로 퍼트리고
// 고슴도치(S -> D)도 bfs로 이동 시켜서 최소 거리를 구하는 것

void water_fill(int n) {
    // 이렇게 bfs를 돌려야하는 게 여러개 생겨버리면 어렵다!!
    while(n--) {
        int x = water.front().first;
        int y = water.front().second;
        water.pop();
        
        for(int i = 0; i < 4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];
            
            // 홍수 가능 : 범위 내 + 탐색 한적 없음 + 빈칸
            if(nx >= 0 && nx < r && ny >= 0 && ny < c && !w_visited[nx][ny] && map[nx][ny] == '.') {
                map[nx][ny] = '*';
                w_visited[nx][ny] = true;
                water.push({nx, ny});
            }
        }
    }
}

void search() {
    // bfs를 하면서 저장해야하는 것?
    // 고슴도치의 좌표와 지금까지 이동한 시간!
    queue<tuple<int, int, int>> q;
    q.push({s_x, s_y, 0});
    h_visited[s_x][s_y] = true;

    while(!q.empty()) {
        // 우선 물을 먼저 채워볼까
        int siz = water.size();
        water_fill(siz);

        int h_siz = q.size();

        while(h_siz--) {
            int x = get<0>(q.front());
            int y = get<1>(q.front());
            int t = get<2>(q.front());
            q.pop();

            // 만나면 거기서 stop 해버려도 된다
            if(x == d_x && y == d_y) {
                ans = t;
                return;
            }

            for(int i = 0; i < 4; i++) {
                int nx = x + dx[i];
                int ny = y + dy[i];

                // 이동 불가능 1. 지도 범위를 벗어남
                if(nx < 0 || nx >= r || ny < 0 || ny >= c) continue;

                // 이동 불가능 2. 물이나 돌이 있거나 이미 왔던 곳(최소거리)
                if(map[nx][ny] == '*' || map[nx][ny] == 'X' || h_visited[nx][ny]) continue;

                // 이동 가능
                q.push({nx, ny, t + 1});
                h_visited[nx][ny] = true;
            }
        }   
    }
}

int main() {
    cin >> r >> c;
    string s;

    for(int i = 0; i < r; i++) {
        cin >> s;    
        for(int j = 0; j < c; j++) {
            map[i][j] = s[j];
            
            // 고슴도치(s)
            if(map[i][j] == 'S') {
                s_x = i;
                s_y = j;
            }


            // 비버(d)
            if(map[i][j] == 'D') {
                d_x = i;
                d_y = j;
            }

            // 처음 물의 좌표
            if(map[i][j] == '*') {
                water.push({i, j});
                w_visited[i][j] = true;
            }

        }
    }
    
    search();
    
    if(ans == 5000) cout << "KAKTUS";
    else cout << ans;
}