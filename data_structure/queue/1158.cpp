// https://www.acmicpc.net/problem/1158

#include <iostream>
#include <queue>
using namespace std;

int main() {
    int N, K, cnt, idx;
    bool visited[5000] = {false};
    queue<int> q;
    
    cin >> N >> K; 
    
    idx = K;
    cnt = K;

    while(q.size() != N) {
        // 다음 idx 찾기: 카운트한 수가 K가 될 때까지 탐색
        // 만약 idx가 N-1이면 다시 0으로 바꿔주기        
        while(cnt != K) {
            idx++;
            if(idx == N + 1) idx = 1;

            if(visited[idx - 1] == false) {
                cnt++;
            }
        }

        // q에 넣기
        q.push(idx);
        visited[idx - 1] = true;

        // cnt 초기화
        cnt = 0;
    }

    // output print
    cout << "<";
    for(int i = 0; i < N-1; i++) {
        cout << q.front() <<", ";
        q.pop();
    }
    cout << q.front() << ">";

    return 0;
}