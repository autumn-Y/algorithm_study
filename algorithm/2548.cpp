// https://www.acmicpc.net/problem/2548
// 완전탐색연습 3

#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    // input : 자연수 개수 N
    // N 개의 자연수
    int N, temp;
    cin >> N;
    int sum = 0;
    vector<int> v;

    for(int i = 0; i < N; i++) {
        cin >> temp;
        v.push_back(temp);
    }

    sort(v.begin(), v.end());


    // 홀수면 가운데 값
    // 짝수개면 값 2개 중에 작은거
    int mid;

    // output: 대표 자연수 출력, 두 개 이상일 경우 작은 것 출력
    if(N % 2 == 0) cout << v[N/2 - 1];
    else cout << v[N/2];

    return 0;
}