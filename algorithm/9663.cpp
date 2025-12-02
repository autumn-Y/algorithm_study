// https://www.acmicpc.net/problem/9663
// try1. 2차원 배열로 보드를 바꾸기 -> 시간이 너무 오래걸린다
// try2. 풀이법 찾기 - 가로 / 대각선을 1차원 배열로 파악하기

#include <iostream>
using namespace std;

int n;
// 0이면 가능, 1이면 불가능
int board[15][15];
int ans = 0;

void search(int n_col) {
    // 종료조건 1. 보드의 맨 끝 행 까지 갔다 왔는가??
    if(n_col >= n) {  
        ans++;
        return;       
    }

    // 
    for(int col = 0; col < n; col++) {
        
    }
}       

int main() {
    // 퀸은 가로, 새로, 대각선 방향으로
    // 앞에 기물이 가로막지 않는 한 원하는 만큼 이동 가능

    // NxN 체스판에 퀸 N개가 서로 공격할 수 없게 놓는 경우의 수

    // DFS로 체스말을 하나씩 놓아가면서 다음 경우 찾기
    // 그리고 체스 하나를 두면 보드에 놓으면 안되는 경우 업데이트 하기
    cin >> n;
    search(n);
    cout << ans;
}