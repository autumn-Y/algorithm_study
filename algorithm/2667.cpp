// https://www.acmicpc.net/problem/2667
// 그래프 탐색

#include <iostream>
#include <stdio.h>
#include <vector>
#include <algorithm>
#include <queue>
#include <utility>
#include <string>
using namespace std;

int N;
int map[26][26];
vector<int> v;
int x[4] = {-1, 1, 0, 0};
int y[4] = {0, 0, -1, 1};
bool visited[26][26] = {false};

void bfs(int nx, int ny) {
    int cnt = 1;
    queue<pair<int, int>> q;

    q.push(make_pair(nx, ny));
    visited[nx][ny] = true;

    while(!q.empty()) {
        nx = q.front().first;
        ny = q.front().second;
        q.pop();
        
        for(int i = 0; i < 4; i++) {
            int dx = nx + x[i];
            int dy = ny + y[i];

            if(visited[dx][dy] == false && map[dx][dy] == 1) {
                visited[dx][dy] = true;
                cnt++;
                q.push(make_pair(dx, dy));
            }
        }
    }

    v.push_back(cnt);
    return;
}

void search() {
    // 우선 2차원 배열 전부 돌면서 bfs 갈 길 point 찾기
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < N; j++) {
            if(map[i][j] == 0) continue;
            if(visited[i][j]) continue;
            bfs(i, j);
        }
    }
    return;
}



int main() {
    cin >> N;

    // input : 지도의 크기 N (정사각형, 5 ~ 25)
    // N개의 자료 입력
    // output: 총 단지수 출력, 각 단지내 집의 수 오름차순 정렬

    // 이건 너무 명확한 bfs 문제!
    // bfs는 queue를 이용하는 알고리즘!
    // bfs 탐색은 상하좌우를 계속 탐색할 거고
    // 한번 탐색하면 단지 수를 vector에서 넣고
    // 나중에 정렬해서 출력하기

    // 아 이거 인풋이 string이네
    string temp;
    for(int i = 0; i < N; i++) {
        cin >> temp;
        for(int j = 0; j < N; j++) {
            map[i][j] = temp[j] - '0';
        }
    }

    search();
    sort(v.begin(), v.end());

    cout << v.size() << endl;
    for(auto it : v) {
        cout << it << endl;
    }
}