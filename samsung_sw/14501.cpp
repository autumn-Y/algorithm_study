// https://www.acmicpc.net/problem/14501

#include <iostream>
#include <vector>
#include <utility>
#include <cstring>
using namespace std;

int ans;
int N;
vector<int> v[15];
bool visited[15];

void search(int day, int sum) {
    // dfs로 1일차부터 N일차까지 재귀 함수로 탐색
    // 종료 조건은 start == N일때 (start가 0으로 시작하니까)
    // 무조건 마지막날 케이스까지 재귀 돌고 돌아오기
    if(day >= N) {
        // 이때 현재 최대값이랑 비교해서 정답 업뎃해주기
        if(sum > ans) ans = sum;
        return;
    }

    // 재귀 함수 부분
    // 탐색 조건 : 아직 방문하지 않았고, 일을 안하는 범위에 있어야 함
    // 내가 start로 설정한 이유는 start번째 일을 할 경우에 dfs 탐색을 해라인데
    // 그니까 난 이 함수를 무조건 그날 일을 한다고 가정하고 한 거잖아
    // 그럼 메인함수에서 search를 부르기 전에 얘가 가능하지 확인을 먼저 하자
    // start += v[start][0];
    // for(int i = start; i < N; i++) {
    //     if(visited[i]) continue;
    //     // 근데 i를 start에 일을 하고 그 다음에 할 수 있는 날부터 탐색을 하려면
    //     // dfs를 돌기 전에 이 일을 할 수 있는지 판단을 해야하잖아?
    //     // 그래서 available이 필요해
    //     // 내 available은 이미 start를 처리하고 온 것으로 판단할까?
    //     visited[i] = true;
    //     if(available - v[i][0] < 0) continue;
    //     available -= v[i][0];
    //     sum += v[i][1];
    //     search(i, sum, available);
    //     visited[i] = false;
    // }
    if(day + v[day][0] <= N) {
        search(day + v[day][0], sum + v[day][1]);
    }

    // 상담을 못하는 날이면
    search(day + 1, sum);
}

int main() {
    // input : N (1 <= N <= 15)
    // (Ti Pi), 1~N일까지 순서대로
    // Ti: 상담을 완료하는 데 걸리는 기간
    // Pi: 상담을 했을 때 받을 수 있는 금액 
    // idx 접근이 쉬워야 하기 때문에 이중 벡터로 선택하자

    int a, b;

    cin >> N;
    for(int i = 0; i < N; i++) {
        cin >> a >> b;
        v[i].push_back(a);
        v[i].push_back(b);
    }

    // 조건`1. 하루에 하나씩 서로 다른 사람의 상담
    // 조건 2. 한 개의 상담이 끝날 때까지 다른 상담을 할 수 없음
    // 조건 3. N+1일 째에도 해야하는 상담은 잡을 수 없음

    // IDEA 정리
    // 우선 상담 가능한 수의 합이 N 이하여야 함
    // 무작정 탐색이 아니고 1일을 선택했을 때 가능한 수
    // 그 다음 n일을 선택했을 때 가능한 경우
    // 이렇게 완전 탐색해서 얻을 수 있겠다
    ans = -1;
    search(0, 0);
    
    // output: 얻을 수 있는 최대 이익
    cout << ans;

    return 0;
}