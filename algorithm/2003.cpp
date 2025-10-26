// https://www.acmicpc.net/problem/2003

#include <iostream>
using namespace std;

int main() {
    // input: N, M
    int N, M, temp;
    cin >> N >> M;

    int arr[100000] = {0};
    int acc_arr[100000] = {0};
    // 이 문제의 포인트는 i부터 j가 맨끝이나 맨첫이 아니라는거야

    int start = 0;
    int end = 0;
    int sum = 0; 
    int ans = 0;;

    for(int i = 0; i < N; i++) {
        cin >> arr[i];
    }
    
    while (true) {
        if (sum >= M) {
            if (sum == M) ans++;
            sum -= arr[start++];
        } 
        
        else if (end == N) {
            break;
        } 
        
        else {
            sum += arr[end++];
        }
    }

    // output: 합이 M이 되는 경우의 수 출력
    cout << ans;
} 