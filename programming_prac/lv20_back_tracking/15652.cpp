// https://www.acmicpc.net/problem/15652

#include <iostream>
#include <stdio.h>
using namespace std;

int N, M;
int arr[9];

void search(int idx, int cnt) {
    if(cnt == M) {
        for(int i = 0; i < M; i++) {
            printf("%d ", arr[i]);
        }
        printf("\n");
        return;
    }

    for(int i = idx; i <= N; i++) {
        arr[cnt] = i;
        search(i, cnt + 1);
    }
    return;
}

int main() {
    // 이번 문제는 N개의 자연수 중 M개를 고른 수열을 구하는데
    // 중복 허용이고, 자기 이상의 수만 가능한 비내림차순

    scanf("%d %d", &N, &M);
    search(1, 0);
}