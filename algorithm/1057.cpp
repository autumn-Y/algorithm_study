// https://www.acmicpc.net/problem/1057
// 완전탐색연습 2

#include <iostream>
#include <cmath>
using namespace std;

int main() {
    // input: 참가자 수 N, 김지민과 임한수의 번호
    // 2 <= N <= 10만
    // 김지민의 번호는 임한수보다 작거나 같다
    int N, K, L;
    cin >> N >> K >> L;

    // 토너먼트이긴 하지만, 다른 팀에 누가 올라오는지는 전혀 노상관이다
    // 내가 알고싶은건 김지민과 임한수가 이겨서 올라왔을 때
    // 얘들이 결국 토너먼트에서 만나는지의 여부이다

    // 그럼 고려해야하는 점은 이겨서 다음 토너먼트에 올라갔을 때
    // 어떤 값으로 갱신할 수 있는가이다

    // 다음 라운드에서 김지민과 임한수가 몇번째 선수인지 update하자
    // (현재 번호) + 1 / 2 : 몫으로 업데이트
    // 2명씩 묶었을 때 둘이 같은 값에 속한다고 어떻게 판단할까
    // 그건 업데이트 된 값이 같으면 된는거임

    // 전체 사람 수는 토너먼트로 진행될 때 최대 라운드수를 구하는 데 쓰자
    // N명이면 총 log(n)을 올림한 수

    int round = ceil(log2(N));
    int temp = 0;

    for(int i = 0; i < round; i++) {
        K = (K + 1) / 2;
        L = (L + 1) / 2;
        
        if(L == K) {
            cout << i + 1;
            break;
        }

        temp++;
    }

    if(temp == round) cout << -1;

    // output : 김지민과 임한수가 대결하는 라운드 번호
    // 대결하지 않을 때는 -1 출력 

    return 0;
}