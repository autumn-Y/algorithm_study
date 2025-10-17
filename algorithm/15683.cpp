// https://www.acmicpc.net/problem/15683

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int origin[8][8];

void dfs() {

}

void fill() {

}

int main() {
    // input : 세로 길이 N, 가로길이 M
    // 초기 값은 전역 arr에 저장
    int N, M;
    cin >> N >> M;

    for(int i = 0; i < N; i++) {
        for(int j = 0; j < M; j++) {
            cin >> origin[i][j];
        }
    }

    // 모든 cctv의 모든 경우를 다 봐야해 = brute force
    // 그리고 그 방향의 뎁스 끝까지 찾아야하니까 dfs 로 구현

    fill();

    
       
}