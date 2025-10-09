// https://www.acmicpc.net/problem/12873

#include <iostream>
#include <queue>
#include <cmath>
using namespace std;

int main() {
    ios::sync_with_stdio(0), cin.tie(0);

    int N;
    int turn = 1;
    long long move = 1;
    queue<int> q;

    cin >> N;

    // 큐에 값 넣기
    for(int i = 1; i <= N; i++) {
        q.push(i);
    }

    // 대상자가 한명만 남을 때까지
    while(q.size() != 1) {
        // t^3 % 남은 사람 수 만큼 이동하기
        move = pow(turn, 3);
        move %= q.size();

        // move == 0일 때 남은 사람 수 만큼 이동하기
        if(move == 0) move = q.size();

        // move만큼 사람 세기
        // 맨 앞 사람을 다시 큐 뒤로 넣어주는 방식으로 해결하기
        // 당사자는 다시 뒤로 가면 안되니까 move를 먼저 빼주고 시작하기
        while(--move) {
            q.push(q.front());
            q.pop();
        }

        // 그 이후에 큐 앞에 있는 사람이 당사자
        q. pop();

        turn++;
    }

    cout << q.front();
    return 0;
}