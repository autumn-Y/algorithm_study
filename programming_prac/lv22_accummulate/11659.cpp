// https://www.acmicpc.net/problem/11659
// 누적합구하기

#include <iostream>
#include <stdio.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    // input : 수의 개수 N, 합을 구해야하는 횟수 M
    // N개의 수
    // 합을 구해야하는 구간 i와 j

    int N, M, a, b;
    //cin >> N >> M;
    scanf("%d %d", &N, &M);

    // 아이디어는 입력을 받으면서 누적합을 데이터로 배열에 저장하면
    // i부터 j까지의 구간은 
    // j번재 누적합에서 i번재 누적합을 빼는 것으로 구할 수 있다

    int arr[100005];
    int sum[100005];

    sum[0] = 0;
    for(int i = 1; i <= N; i++) {
        scanf("%d", &arr[i]);
        //cin >> arr[i];
        sum[i] = sum[i-1] + arr[i];
    }

    // output: i번째 수부터 j번째 수까지 합 구하기
    for(int i = 0; i < M; i++) {
        scanf("%d %d", &a, &b);
        //cin >> a >> b;
        //cout << arr[b] - arr[a-1] << endl;
        printf("%d\n", sum[b] - sum[a-1]);
    }
}