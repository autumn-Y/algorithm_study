// https://www.acmicpc.net/problem/14888

#include <iostream>
using namespace std;

int N;
int num[11];
int comput[4];
int ans_min = 1e9;
int ans_max = -1e9;

// dfs에서 탐색하고 다시 돌아왔을 때,
// 그 전의 연산값을 가지고 있어야함
// dfs의 탐색 범위를 우리가 idx 범위로 할 때는
// for문이나 while로 해서 1 -> 2 -> 하겠지?
// 근데 이 경우에는 연산자를 기준으로 생각하면
// 덧셈을 먼저 고려 / 뺄셈을 먼저 고려 / ...
// 이런식으로 dfs를 돌리면 어떻게 되나?
// 그럼 연산은 하고 dfs를 돌려버리면 되지!
// 인자를 계속 넘겨버리는 방식도 있을 거 같고, 
// 어떤 자료구조를 하나 두고 그걸 업뎃 치는 것도 방법이겠다

void dfs(int plus, int minus, int mul, int div, int idx, int result) {
    // 우선 연산자 순서는 중복없는 순열 처리
    // dfs는 idx로 따라가면서 확인하자
    
    if(idx == N - 1) {
        // 이번 경우의 수 연산값이 max나 min 경우인지 확인;
        if(result > ans_max) ans_max = result;
        if(result < ans_min) ans_min = result;
        return;
    }

    // dfs는 덧셈, 뺄셈, 곱셈, 나눗셈
    if(plus > 0) {
        dfs(plus - 1, minus, mul, div, idx + 1, result + num[idx + 1]);
    }

    if(minus > 0) {
        dfs(plus, minus - 1, mul, div, idx + 1, result - num[idx + 1]);
    }

    if(mul > 0) {
        dfs(plus, minus, mul - 1, div, idx + 1, result * num[idx + 1]);
    }

    if(div > 0) {
        dfs(plus, minus, mul, div - 1, idx + 1, result / num[idx + 1]);
    }
}

int main() {
    // input: 숫자 개수 N (2 ~ 11)
    // 1 <= Ai <= 100
    // 합이 N-1인 4개의 정수 : + - * % 개수

    // 조건 1. 주어진 수의 순서를 바꾸면 안됨
    // 조건 2. 연산자 우선순위를 무시하고 앞에서부터 진행해야함
    // 조건 3. 나눗셈은 정수 나눗셈으로 몫만 취함
    // 조건 4. 음수/양수 c++14의 기준을 따름 = 따로 취할 행동 없음
    // = 양수로 바꾼 뒤 몫을 취하고, 이 몫을 음수로 바꿈

    // 주어진 수는 배열 저장, idx 저장해서 타겟 수가 몇번째인지 팔로우
    // 사칙연산도 배열로 저장해서 1, 2, 3, 4 순열 조합하던가

    cin >> N;
    for(int i = 0; i < N; i++) {
        cin >> num[i];
    }

    for(int i = 0; i < 4; i++) {
        cin >> comput[i];
    }

    // 우선 이번 케이스 연산 값 저장하는 변수
    // max 값과 min 값을 저장하는 변수

    dfs(comput[0], comput[1], comput[2], comput[3], 0, num[0]);

    // output: 만들 수 있는 식의 최대값과 최소값
    cout << ans_max << endl;
    cout << ans_min;

    return 0;
}