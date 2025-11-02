// https://www.acmicpc.net/problem/2559

#include <iostream>
using namespace std;

int main() {
    // N: 온도를 측정한 전체 날짜의 수 (<= 100000)
    // K: 합을 구하기 위한 연속적인 날짜의 수 ( <= K)
    // 매일 측정한 온도를 나타내는 N개의 정수 (-100 ~ 100)

    // output: 연속적인 K일의 온도의 합이 최대가 되는 값을 출력

    // 우선 입력을 받으면서 누적합도 같이 구한다
    // 그리고 K만큼 차이나는 front와 back 변수를 두고
    // back이 마지막 날짜기 갈 때까지
    // sum[back] - sum[front+1]
    // front : 1부터 시작
    // back : front + K - 1

    int arr[100001];
    int sum[100001] = {0, };
    int N, K, front, back, temp, max;

    cin >> N >> K;
    for(int i = 0; i < N; i++) {
        cin >> arr[i];
        sum[i + 1] = sum[i] + arr[i];
    }

    front = 1;
    back = front + K -1;
    max = -1e9;

    while(back <= N) {
        temp = sum[back] - sum[front - 1];
        if(temp > max) max = temp;
        front++;
        back++;
    }

    cout << max;
}