// https://www.acmicpc.net/problem/9663
// try1. 2차원 배열로 보드를 바꾸기 -> 시간이 너무 오래걸린다
// try2. 풀이법 찾기 - 가로 / 대각선을 1차원 배열로 파악하기

#include <iostream>
#include <algorithm>
using namespace std;

int n;
int ans = 0;
int queen[16];

bool ispossible(int c_idx) {
    for(int i = 0; i < c_idx; i++) {
        // 지금까지 둔 queen들 위치 돌리면서
        // 같은 row가 아닌지
        // 대각선이 아닌지 확인
        if(queen[i] == queen[c_idx] || abs(i - c_idx) == abs(queen[i] - queen[c_idx])) {
            return false;
        }
    }
    return true;
}

void search(int q) {
    // 종료 조건 1. queen을 n개 놓은 경우
    if(q == n) {
        ans++;
        return;
    }

    // 백트래킹 파트
    // queen은 절대 같은 col에 놓을 수 없어
    // 즉, q를 col 인덱스로 쓰면 됨
    for(int i = 0; i < n; i++) {
        // i를 row로 쓰자
        queen[q] = i;
        if(ispossible(q)) {
            search(q + 1);
        }
    }
}

int main() {
    // 퀸은 가로, 새로, 대각선 방향으로
    // 앞에 기물이 가로막지 않는 한 원하는 만큼 이동 가능

    // NxN 체스판에 퀸 N개가 서로 공격할 수 없게 놓는 경우의 수

    // DFS로 체스말을 하나씩 놓아가면서 다음 경우 찾기
    // 그리고 체스 하나를 두면 보드에 놓으면 안되는 경우 업데이트 하기
    cin >> n;
    search(0);
    cout << ans;
}