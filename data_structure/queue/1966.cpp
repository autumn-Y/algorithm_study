// https://www.acmicpc.net/problem/1966

#include <iostream>
#include <queue>
using namespace std;


int main() {
    int T, N, M, prior, cnt, idx;
    queue<pair<int, int>> q;
    priority_queue<int> pq;

    cin >> T;

    for(int t = 0; t < T; t++) {
        q = {};
        pq = {};
        cnt = 0;

        cin >> N >> M;

        for(int i = 0; i < N; i++) {
            cin >> prior;
            q.push(make_pair(prior, i));
            pq.push(prior);
        }

        // 탐색하기
        while(!q.empty()) {
            prior = q.front().first;
            idx = q.front().second;
            q.pop();

            // 뒤에 더 큰 우선 순위가 있는지 확인
            if(prior == pq.top()) {
                ++cnt;
                if(idx == M) break;
                pq.pop();
            }

            else {
                q.push(make_pair(prior, idx));
            }
        }

        cout << cnt << endl;
    }
}