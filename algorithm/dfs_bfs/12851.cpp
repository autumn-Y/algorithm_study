// https://www.acmicpc.net/problem/12851

#include <iostream>
#include <queue>
#include <utility>
using namespace std;

int n, k;
int ans[2] = {100001, 0}; 
bool visited[100001] = {false};

void search() {
    // bfs로 풀건데!
    // 우선 왔던 좌표 또 가면 안되니까 중복 확인할거고
    // 지금 좌표가 동생 좌표면 확인 
    // 근데 가장 빠른 시간이 몇개인지 확인해야하니까
    // 계속 찾을때까지 돌자?

    queue<pair<int, int>> q;
    q.push(make_pair(n, 0));
    visited[n] = true;

    while(!q.empty()) {
        int x = q.front().first;
        int t = q.front().second;
        q.pop();
        visited[x] = true;
        
        if(ans[0] < t) break;

        // 동생 찾았다
        if(x == k) {
            if(ans[0] == t) ans[1]++;
            
            else {
                ans[0] = t;
                ans[1] = 1;
            }

            continue;
        }

        // -1 움직이기
        int nx = x - 1;
        if(nx >= 0 && nx <= 100000 && !visited[nx]) {
            q.push({nx, t + 1});
        }
        
        // + 1 움직이기
        nx = x + 1;
        if(nx >= 0 && nx <= 100000 && !visited[nx]) {
            q.push({nx, t + 1});
        }

        // * 2 움직이기
        if(x * 2 <= 100000 && !visited[x * 2]) {
            q.push({x * 2, t + 1});
        }
    }
}

int main() {
    cin >> n >> k;
    search();

    cout << ans[0] << endl << ans[1];
}