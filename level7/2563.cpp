// https://www.acmicpc.net/problem/2563

#include <iostream>
#include <stdio.h>
#include <vector>
#include <string>
using namespace std;

int main() {
    int board[100][100] = {0};
    int n, a, b;
    int cnt = 0;

    cin >> n;
    
    // 색종이 칠하기
    for(int i = 0; i < n; i++) {
        cin >> a >> b;
        for(int x = a; x < a + 10; x++) {
            for(int y = b; y < b + 10; y++) {
                board[x][y] = 1;
            }
        }
    }

    // 칠해진 부분 세기
    for(int i = 0; i < 100; i++) {
        for(int j = 0; j < 100; j++) {
            if(board[i][j] == 1) cnt++;
        }
    }

    cout << cnt;

    return 0;
}