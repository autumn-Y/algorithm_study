// https://www.acmicpc.net/problem/1260
// adjacent list로 구현하기

#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <cstring>
using namespace std;

// vector를 사용해서 인접 리스트로 구현하기
// 1부터 정점이 시작하니까 맞춰주기
vector<int> v[10002];
bool visited[1001] = {false};

// dfs 함수
void dfs(int target) {
    // 타겟 숫자에 연결된 애들을 다 훑어봐야해
    // 우선 타겟으로 들어온 숫자는 방문 처리
    cout << target << " ";
    visited[target] = true;

    for(int i = 0; i < v[target].size(); i++) {
        // 들를 앤지 아닌지 확인해야해
        if(visited[v[target][i]]) continue;
        dfs(v[target][i]); 
    }

    return;
}

// bfs 함수
void bfs(int target) {
    // 나랑 연결된 애들 다 탐색하고 그 다음거 탐색할거야
    // bfs는 큐로 구현한다
    queue<int> q;

    // q에 target을 넣고 시작
    q.push(target);
    visited[target] = true;
    
    // 시작 접점의 주변 애들 다 넣으면서 갈거니까 q가 비면 탐색이 끝난 것
    while(!q.empty()) {
        // q의 top이 탐색 태상
        int x = q.front();
        cout << x << " ";

        // 이미 탐색 대상이 되었으니 pop 해야함
        q.pop();

        for(int i = 0; i < v[x].size(); i++) {
            if(visited[v[x][i]]) continue;
            q.push(v[x][i]);
            visited[v[x][i]] = true;
        }
    }
}

int main() {
    // input: 정점 개수 N, 간선 개수 M, 탐색 시작 정점 V
    // 간선이 연결하는 두 정점의 번호
    // 양방향 간선 고려해야하고, M개 input이 들어온다는 말!

    int N, M, V, a, b;
    cin >> N >> M >> V;

    for(int i = 0; i < M; i++) {
        cin >> a >> b;
        // 양방향 간선 고려
        v[a].push_back(b);
        v[b].push_back(a);
    }

    // 인접리스트로 구현할 경우, 정렬해주는 과정이 필요함
    // 왜냐하면 정점 번호가 작은 것을 먼저 방문
    for(int i = 0; i < M; i++) {
        sort(v[i].begin(), v[i].end());
    }
    
    // 결과를 보여주려면 재귀 통과할 때 / 큐 팝 할 때 출력하자
    // output 1 : dfs 수행 결과
    // 인수로 시작점을 보내줘야함
    dfs(V);

    cout << endl;

    // visited를 정리하는 작업이 필요해요
    // 선언 이후에 배열을 초기화하려면, fill 이나 memset
    // memset(배열 시작 주소, 0 또는 -1, 배열 크기)
    // fill(초기화 시작 주소, 초기화 끝주소, 초기화 값)
    memset(visited, false, 1001);
    
    // output 2 : bfs 수행 결과
    bfs(V);

    return 0;
}