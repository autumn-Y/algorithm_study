// https://www.acmicpc.net/problem/15651

#include <iostream>
#include <stdio.h>
using namespace std;

int N, M;
int arr[8];

void search(int cnt) {
    // 종료 조건은 M개의 수를 고르면!
    // 중복을 허용하기 때문에 visited는 필요가 없음
    // cnt만 인수로 받으면 될듯

    if(cnt == M) {
        for(int i = 0; i < M; i++) {
            printf("%d ", arr[i]);
        }
        printf("\n");
        return;
    }

    for(int i = 1; i <= N; i++) {
        arr[cnt] = i;
        search(cnt + 1);
    }
    return;
}

int main() {
    // 1부터 N까지 자연수 중에서 M을 고른 수열
    // 같은 수를 여러번 골라도 됨
    // 사전순으로 증가하는 순서대로 출력

    scanf("%d %d", &N, &M);
    search(0);
}