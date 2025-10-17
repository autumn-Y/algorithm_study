// https://www.acmicpc.net/problem/10974

#include <iostream>
#include <cstring>
using namespace std;

int N;
int ans[9];
bool visited[9] = {false};

// 그냥 냅따까라 걍 돌려?
void permute(int now) {
    if(now == N) {
        for(int j = 0; j < N; j++) {
            cout << ans[j] << " ";
        }
        cout << endl;
        return;
    }

    for(int i = 0; i < N; i++) {
        if(visited[i]) continue;
        visited[i] = true;
        ans[now] = i + 1;
        permute(now +1);
        visited[i] = false;
    } 
}

int main() {
    // input N 
    cin >> N;

    permute(0);
}