// https://www.acmicpc.net/problem/10974
// 완전탐색연습 1

#include <iostream>
#include <cstring>
#include <stdio.h>
using namespace std;

int N;
int ans[9];
bool visited[9] = {false};

// 그냥 냅따까라 걍 돌려?
void permute(int now) {
    if(now == N) {
        for(int j = 0; j < N; j++) {
            printf("%d ", ans[j]);
        }
        printf("\n");
        return;
    }

    for(int i = 0; i < N; i++) {
        if(visited[i]) continue;
        visited[i] = true;
        ans[now] = i + 1;
        permute(now +1);
        visited[i] = false;
    } 
}

int main() {
    // input N 
    cin >> N;

    permute(0);
}