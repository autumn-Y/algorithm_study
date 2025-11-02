// https://www.acmicpc.net/problem/15650

#include <iostream>
#include <stdio.h>
using namespace std;

int N, M;
bool visited[9] = {false};
int arr[9];

void search(int idx, int cnt) {
    // 나는 이 함수에서 재귀함수로 dfs 탐색을 구현할거고
    // 종료 조건은 cnt가 M인지야
    // 만약에 M만큼 남은 수가 없어서 for문이 끝나면
    // 그냥 return을 해서 끝내버려야하고
    // visted도 혹시 모르니까 우선 해둘까

    if(cnt == M) {
        for(int i = 0; i < M; i++) {
            printf("%d ", arr[i]);
        }
        printf("\n");
        return;
    }
    
    for(int i = idx; i <= N; i++) {
        if(visited[i]) continue;
        visited[i] = true;
        arr[cnt] = i;
        search(i + 1, cnt + 1);
        visited[i] = false;
    }
    
    return;
}

int main() {
    // input N, M (M <= N <= 8)
    // 1부터 M까지 자연수 중 중복없이 M개를 고른 수열
    // 오름차순이어야 함

    // 이전 문제와 다른 점은
    // 이전 문제는 (1, 2) 와 (2, 1)을 다른 경우로 보았다면
    // 이 문제는 같은 경우로 취급한다는 것

    // 그럼 시작값보다 큰 값으로만 dfs 탐색을 해야겠네?
    
    //cin >> N >> M;
    scanf("%d %d", &N, &M);
    search(1, 0);   
}