// https://www.acmicpc.net/problem/10870

#include <iostream>
using namespace std;

int fibonacci(int now) {
    // 종료조건이 뭐지?
    // 애초에 n번째 피보나치 수가 뭐냐라고 물으면
    // n에서 부터 쌓아나가야 하나?
    // 와 내가 완전히 반대로 생각하고 있었네
    // 맨 끝까지 내려가서 차례로 리턴하면서 값을 반환해야 했던 거네

    // 그니까 종료 값이 0
    if(now == 0) {
        return 0;
    }
    
    // 그리고 0, 1까지 그래프가 내려가니까
    if(now == 1) {
        return 1;
    }

    // 이렇게 두개의 값을 반환하면서 더해올거니까
    return fibonacci(now - 1) + fibonacci(now - 2);
}

int main() {
    // input : N
    int N;
    cin >> N;

    // output : n번째 피보나치 수 출력
    cout << fibonacci(N);
}   