// https://www.acmicpc.net/problem/13913

#include <iostream>
#include <queue>
#include <stack>
#include <utility>
using namespace std;

int n, k;
// 갔던 좌표 또 가면 어차피 최소 거리 아님
bool visited[100001];
int parents[100001];
int dx[2] = {-1, 1};
int ans;
stack<int> s;

void search() {
    // path 탐색은 부모를 기록해서 하자
    // 거꾸로 탐색할 거기 때문에 스택을 활용하자
    queue<pair<int, int>> q;

    q.push(make_pair(n, 0));
    visited[n] = true;

    while(!q.empty()) {
        int x = q.front().first;
        int t = q.front().second;
        q.pop();
        visited[x] = true;

        // 종료 조건
        if(x == k) {
            int temp = x;

            while(temp != n) {
                s.push(temp);
                temp = parents[temp];
            }
            s.push(temp);
            
            ans = t;
            return;
        }

        // -1 움직이기
        int nx = x - 1;
        if(nx >= 0 && nx <= 100000 && !visited[nx]) {
            q.push({nx, t + 1});
            visited[nx] = true;
            parents[nx] = x;
        }
        
        // + 1 움직이기
        nx = x + 1;
        if(nx >= 0 && nx <= 100000 && !visited[nx]) {
            q.push({nx, t + 1});
            visited[nx] = true;
            parents[nx] = x;
        }

        // * 2 움직이기
        if(x * 2 <= 100000 && !visited[x * 2]) {
            q.push({x * 2, t + 1});
            visited[x * 2] = true;
            parents[x * 2] = x;
        }
    }
}

int main() {
    cin >> n >> k;
    search();
    cout << ans << endl;
    int temp = s.size();
    for(int i = 0; i < temp; i++) {
        cout << s.top() << " ";
        s.pop();
    }

    return 0;
}