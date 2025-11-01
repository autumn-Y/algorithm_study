// https://www.acmicpc.net/problem/15649

#include <iostream>
#include <stdio.h>
using namespace std;

int N, M;
int arr[9];
bool visited[9] = {false};


// 재귀함수로 구하면 좋을거 같은데??
void bt(int depth) {
    // 그럼 이번이 3번째이면 멈추는 조건으로 하면 될거 같은데?
    // 재귀를 돌면서 앞에 값이 뭔지는 배열로 저장해두자
    
    // 종료조건
    if(depth == M) {
        for(int i = 0; i < M; i++) {
            printf("%d ", arr[i]);
            //cout << arr[i] << " ";
        }
        printf("\n");
        //cout << endl;
        return;
    }

    for(int i = 1; i <= N; i++) {
        if(visited[i]) continue;
        visited[i] = true;
        arr[depth] = i;
        bt(depth + 1);
        visited[i] = false;
    }

}

int main() {
    // input: 자연수 N, M
    // 1부터 N까지 자연수 중에서 중복없이 M개를 고른 수열을 모두 구해라

    cin >> N >> M;

    bt(0);

    // output: 문제의 조건을 만족하는 수열 출력
    // 중복되는 수열을 여러번 출력하면 안됨
    // 각 수열은 공백으로 구분해서 출력
    // 수열은 사전 순으로 증가하는 순서로 출력

}