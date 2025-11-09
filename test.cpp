#include <iostream>
#include <stdio.h>
using namespace std;

int N, M;
int arr[9];
bool visited[9] = {false};

void dfs(int idx, int cnt) {
    // 종료 조건 : cnt == M
    if(cnt == M) {
        for(int i = 0; i < M; i++) {
            printf("%d ", arr[i]);
        }
        printf("\n");
        return;
    }

    // 아니면 1부터 재귀 돌때마다 확인 해줘야함
    for(int i = idx; i <= N; i++) {
        //if(visited[i]) continue;
        //visited[i] = true;
        arr[cnt] = i;
        dfs(i, cnt + 1);
        //visited[i] = false;
    }
    return;
}

int main() {
    cin >> N >> M;

    // 중복 허용 안함, 사전 순으로 증가
    dfs(1, 0);
}