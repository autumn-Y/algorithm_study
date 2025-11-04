//https://www.acmicpc.net/problem/14889

#include <iostream>
#include <stdio.h>
#include <vector>
#include <cmath>
using namespace std;

int N;
bool team[22] = {false};
int power[21][21];
// bool visited[21] = {false};
int ans = 1e9;

void search(int cnt, int idx) {
    // 재귀함수 종료조건은 cnt == N/2
    // 여기서 스타트팀과 링크팀의 능력치 합을 구해서
    // 그 차가 최소가 되면 업뎃 쳐야함

    // 아 근데 team을 플래그로 결정하는 문제점은
    // 능력치는 쌍방이라는 거지
    // 그럼 이차원 배열을 돌면서 쌍방이 같은 팀인지 확인하면 됨!!
    // 플래그로 해도 되겠다

    // 하 근데 이랬는데 시간초과뜸
    // 그럼 벡터로 분류해놓고 시작할까?


    if(cnt == N/2) {
        int temp;
        int start = 0;
        int link = 0;
 
        for(int i = 1; i <= N; i++) {
            // 스타트팀은 = 0
            // 링크팀은 = 1
            for(int j = 1; j <= N; j++) {
                if(team[i] == true && team[j] == true) {
                    start += power[i][j];
                }

                if(team[i] == false && team[j] == false) {
                    link += power[i][j];
                }
            }
        }
        temp = abs(start - link);
        if(temp < ans) ans = temp;
        return;
    }   

    // 중복이 안되고 오름차순 순열로 갈거기 때문에
    // visited가 필요
    // 근데 이번 문제에서 visited로 팀을 나눠보자
    for(int i = idx; i < N; i++) {
        team[i] = true;
        search(cnt + 1, i + 1);
        team[i] = false;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
    // input N(4 <= N <= 20)
    // 각 줄은 N개의 수로 이루어져 있고
    // 1 <= Sij <= 100
    // Sii == 0

    // Sij는 i번 사람과 j번 사람이 같은 팀에 속했을 때,
    // 팀에 더해지는 능력치
    // 팀의 능력치 = 팀에 속한 쌍의 능력치의 합
    // 즉 i와 j가 같은 팀에 속한 경우
    // Sij + Sji가 두 팀의 능력치가 됨

    // 우선 각 팀은 N/2 명씩 갈거고
    // 그럼 N개 중에 N/2개 선택한 경우랑 같네??
    // 스타트 팀(0)과 링크 팀(1)을 플래그로 저장하는 배열을 하나두고
    // DFS로 백트래킹해서 순열을 고른 다음에
    // 마지막에 그걸 계산하는 부분을 넣으면 될거 같아

    // 이번엔 중복을 허용하지 않으면서
    // 정렬은 오름차순으로 순서도 없는 경우로 생각하면 되겠다

    // 능력치는 2차원 배열로 받자

    scanf("%d", &N);
    
    for(int i = 1; i <= N; i++) {
        for(int j = 1; j <= N; j++) {
            scanf("%d", &power[i][j]);
        }
    }
    // output 스타트팀과 링크팀의 능력치 차이의 최솟값

    search(0, 1);

    printf("%d", ans);
}