// https://www.acmicpc.net/problem/1018
// brute force 알고리즘 연습

#include <iostream>
#include <stdio.h>
#include <string>
#include <cmath>
using namespace std;

string w_start[8] = {
    "WBWBWBWB",
    "BWBWBWBW",
    "WBWBWBWB",
    "BWBWBWBW",
    "WBWBWBWB",
    "BWBWBWBW",
    "WBWBWBWB",
    "BWBWBWBW"
};

string b_start[8] = {
    "BWBWBWBW",
    "WBWBWBWB",
    "BWBWBWBW",
    "WBWBWBWB",
    "BWBWBWBW",
    "WBWBWBWB",
    "BWBWBWBW",
    "WBWBWBWB"
};

string board[51];

int w_cnt(int x, int y) {
    int cnt = 0;

    for(int i = 0; i < 8; i++) {
        for(int j = 0; j < 8; j++) {
            if(board[x + i][y + j] != w_start[i][j]) cnt++;
        }
    }

    return cnt;
}

int b_cnt(int x, int y) {
    int cnt = 0;

    for(int i = 0; i < 8; i++) {
        for(int j = 0; j < 8; j++) {
            if(board[x + i][y + j] != b_start[i][j]) cnt++;
        }
    }

    return cnt;
}

int main() {
    // input: n, m (8 ~ 50)
    // 보드의 각 행의 상태 B or W
    // 다시 칠해야하는 정사각형의 개수의 최솟값

    // 검은색과 흰색이 번갈아서 칠해져 있어야 함
    // 변을 공유하는 두개의 사각형은 다른 색으로 칠해져 있어야함
    
    // !! 보드판을 체스판처럼 8 x 8로 잘라낸 후에
    // 다시 칠해야하는 부분 구하기

    // 그냥 냅다 걍 비교때리면 되는 문제임

    int n, m, temp;
    string str;
    int ans = 10000000;

    cin >> n >> m;
    for(int i = 0; i < n; i++) {
        cin >> board[i];
    }

    for(int i = 0; i + 8 <= n; i++) {
        for(int j = 0; j + 8 <= m; j++) {
            temp = min(w_cnt(i, j), b_cnt(i, j));
            if(ans > temp) ans = temp;
        }
    }

    cout << ans;
}