//https://www.acmicpc.net/problem/1697

#include <iostream>
#include <queue>
#include <utility>
using namespace std;

int n, k;
// 갔던 좌표 또 가면 어차피 최소 거리 아님
bool visited[100001];
int dx[2] = {-1, 1};

void search() {
    queue<pair<int, int>> q;

    q.push(make_pair(n, 0));
    visited[n] = true;

    while(!q.empty()) {
        int x = q.front().first;
        int t = q.front().second;
        q.pop();

        // 종료 조건
        if(x == k) {
            cout << t << endl;
            return;
        }

        // x + 1 , x - 1 좌표 이동
        for(int i = 0; i < 2; i++) {
            // 범위 확인 & 방문 확인
            int nx = x + dx[i];
            if(!visited[nx] && nx >= 0 && nx <= 100000) {
                q.push({nx, t + 1});
                visited[nx] = true;
            }
        }

        // 순간 이동
        if(x * 2 <= 100000 && !visited[x * 2]) {
            q.push({x * 2, t + 1});
            visited[x * 2] = true;
        }
    }
}

int main() {
    cin >> n >> k;
    search();
}