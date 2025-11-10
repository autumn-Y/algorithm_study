// https://www.acmicpc.net/problem/1018
// brute force 알고리즘 연습

#include <iostream>
#include <stdio.h>
#include <string>
#include <cmath>
using namespace std;

int main() {
    // input: n, m (8 ~ 50)
    // 보드의 각 행의 상태 B or W
    // 다시 칠해야하는 정사각형의 개수의 최솟값

    // 검은색과 흰색이 번갈아서 칠해져 있어야 함
    // 변을 공유하는 두개의 사각형은 다른 색으로 칠해져 있어야함
    
    int n, m;
    string str;

    scanf("%d %d", &n, &m);
    int chess[51][51];
    int temp;
    // 귀찮으니까 B = -1, W = 1

    int cnt = 0;
    
    for(int i = 0; i < n; i++) {
        cin >> str;
        //temp = 0;
        for(int j = 0; j < m; j++) {
            if(str[j] == 'B') chess[i][j] = -1;
            else chess[i][j] = 1;

           //temp += chess[i][j];
        }
        //cnt += abs(temp);
    }

    int start, last;
    start = -chess[0][0];

    for(int i = 0; i < n; i++) {
        last = start;
        for(int j = 0; j < m; j++) {
            // if(i != 0 && last == -1 && j == 0) start = 1;
            // if(i != 0 && last == 1 && j == 0) start = -1;
            start = -last;

            // start(0)랑 같은 건 인덱스 상 짝수번째
            // 다른건 인덱스 상 홀수 번째
            if(j % 2 == 0 && chess[i][j] != start) cnt++;
            if(j % 2 == 1 && chess[i][j] == start) cnt++;
        }
    }

    //if(m % 2 != 0) cnt -= m;

    cout << cnt;

    return 0;
}