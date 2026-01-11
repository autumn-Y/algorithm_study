// https://www.acmicpc.net/problem/1753

#include <iostream>
#include <vector>
#include <queue>
#include <utility>
using namespace std;
#define INF 1e9

int v, e, start;
vector<pair<int, int>> graph[20005]; // <연결된 노드, weight>
bool visited[20005];
int dist[300005];

void dijkstra() {
    priority_queue<pair<int, int>> pq;
    pq.push({0, start});

    while(!pq.empty()) {
        // 현재 탐색할 노드와 연결된 노드를 모두 확인
        // dist보다 작으면 값 업데이트하고 push
        int w = -pq.top().first;
        int now = pq.top().second;
        pq.pop();

        for(int i = 0; i < graph[now].size(); i++) {
            int next = graph[now][i].first;
            int n_w = graph[now][i].second;

            if(w + n_w < dist[next]) {
                dist[next] = w + n_w;
                pq.push({-dist[next], next});
            }
        }
    }
}

int main() {
    // GRAPH 초기화
    int a, b, c;
    cin >> v >> e >> start;
    for(int i = 0; i < e; i++) {
        cin >> a >> b>> c;
        graph[a].push_back({b, c});
    }

    for(int i = 1; i <= v; i++) {
        if(i == start) dist[i] = 0;
        else dist[i] = INF;
    }

    dijkstra();

    for(int i = 1; i <= v; i++) {
        if(dist[i] == INF) printf("INF\n");
        else printf("%d\n", dist[i]);
    }
}