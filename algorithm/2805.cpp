// https://www.acmicpc.net/problem/2805
// 알고리즘은 맞았지만 변수 타입을 long long으로 하지 않아서 틀렸던 문제!
// binary_search

#include <iostream>
#include <stdio.h>
#include <algorithm>
using namespace std;

int main() {
    // input : 나무의 수 N (<= 1000000)
    // 상근이가 집으로 가져가려고 하는 나무의 길이 M(<= 2000000000)
    // 나무의 높이의 합은 항상 M보다 크거나 같음 = 상근이는 항상 집에 나무를 가져갈 수 있음
    // 나무의 높이 <= 1000000000

    // 절단기에 높이 H 지정
    // H미터 위로 올라가서 한줄에 연속해 있는 나무를 모두 절단
    // 그럼 H미터 보다 큰 나무는 다 잘리고, 잘린 나무의 합만큼 상근이가 가져감
    // output : 적어도 M미터의 나무를 집에 가져가기 위해 절단기에 설정할 수 있는 높이의 최댓값
    
    // 나는 이 문제를 BINARY SEARCH로 풀거야
    // 나무의 수가 10만개라.. 우선 배열로 구현해서 for문으로 탐색하기 하자
    
    long long N, M, mid, temp;
    long long ans = 0;
    long long min = 1;
    long long max = 0;
    long long tree[1000001];
    
    cin >> N >> M;
    for(int i = 0; i < N; i++) {
        cin >> tree[i]; 
        if(tree[i] > max) max = tree[i];
    }

    // binary search 구간
    // while문 조건 : min <= max
    
    while(min <= max) {
        mid = (min + max) / 2;
        temp = 0;
        for(int i = 0; i < N; i++) {
            if(tree[i] <= mid) continue;
            temp += tree[i] - mid; 
        }
    
        // 만약 절단한 나무의 길이가 M보다 작으면 H를 줄여야하니까 max = mid - 1    
        if(temp < M) {
            max = mid - 1;
        } 

        // 만약 절단한 나무의 길이가 M보다 크거나 같으면 H를 키워야 하니까 min = mid + 1    
        else {
            ans = mid;
            min = mid + 1;
        }
    }

    cout << ans;

    return 0;
}