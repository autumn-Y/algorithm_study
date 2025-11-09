// https://www.acmicpc.net/problem/10986

#include <iostream>
using namespace std;

long long mod[1001];

int main() {
    
    // input: N(1 ~ 1000000), M (2 ~ 1000)
    // N개의 수 (1 ~ 10 0000 0000 = 1e9)
    // 연속된 부분 구간의 합이 M으로 나누어 떨어지는 구간의 개수 구하기
    // = Ai ~ Aj의 합이 M으로 나누어 떨어지는 (i, j) 쌍의 개수 구하기

    // 이 문제의 어려운 점은
    // 구간에 속하는 숫자의 개수가 1개부터 N개 까지라는 점
    // 우선 누적합을 구해놓은 배열을 하나 더 두고
    // 그럼 우선 1부터 N까지 도는 아이를 하나 두고
    // 누적합은 LONG LONG으로 만들자
    
    // 모든 구간을 다 돌았더니 시간초과가 발생했다!
    // 누적합을 넘어서 이젠 누적합을 나눈 나머지를 저장하는 배열이 필요하다
    // 누적합을 M으로 나눴을 때 나머지가 0인 구간끼리 조합하거나
    // 나머지가 같은 애들끼리 빼면 나머지가 0이 되므로 같은 애들끼리 조합하거나
    // 그리고 nC2 = n * (n - 1) / 2

    // 이렇게 되면 굳이 배열의 인덱스를 저장할 이유가 없기 때문에
    // map으로 풀었다가 더 이상해져서 완전 깔끔하게 가보자
    // 우선 N과 M의 최대로 보았을 때, 나머지의 최댓값은 1000

    int N, M, temp;
    long long psum = 0;
    
    ios_base::sync_with_stdio(false); cin.tie(NULL);

    cin >> N >> M;
    
    for(int i = 0; i < N; i++) {
        cin >> temp;
        psum += temp;
        mod[psum % M]++;
    }

    long long ans = 0;
    // 탐색의 경우에는 나머지가 M -1 까지 밖에 안나올테니
    for(int i = 0; i <= M; i++) {
        ans += ((mod[i] * (mod[i] - 1)) / 2);
    }

    cout << ans + mod[0];
    return 0;
}
