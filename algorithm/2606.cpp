// https://www.acmicpc.net/problem/2606

#include <iostream>
#include <vector>
using namespace std;

int ans = 0;
bool visited[101] = {false}; 
vector<int> v[101];

void dfs(int point) {
    // 네트워크 탐색 할 때마다 바이러스 걸린 새로운 컴퓨터 찾으면 ++
    // dfs는 visited 배열이랑 재귀함수, 스택 이용하는 탐색법
    // 다 탐색하면 return을 때려줘야하지?
    
    int target;
    visited[point] = true;

    for(int i = 0; i < v[point].size(); i++) {
        target = v[point][i];

        if(visited[target]) continue;
        ans++;
        dfs(target);
    }
    
    return;
}

int main() {
    // input: 컴퓨터의 수 N (<= 100)
    // 네트워크 상에 서로 직접 연결되어 있는 컴퓨터 쌍의 수 T
    int N, T, a, b;
    cin >> N >> T;

    // 자료구조는 링크드리스트로 구현, 쌍방 처리해줘야함
    for(int i = 0; i < T; i++) {
        cin >> a >> b;
        v[a].push_back(b);
        v[b].push_back(a);
    }

    // 1번만 걸리는 거기 때문에 dfs는 1번 노드만 탐색
    // 네트워크 상에서 연결된 컴퓨터는 전부 바이러스에 걸림
    dfs(1);

    // output: 1번 컴퓨터가 웜 바이러스에 걸렸을 때
    // 웜 바이러스에 걸리게 되는 컴퓨터의 수

    cout << ans;

    return 0;
}