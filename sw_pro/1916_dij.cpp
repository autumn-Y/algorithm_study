// https://www.acmicpc.net/problem/1916

#include <iostream>
#include <vector>
#include <utility>
#include <queue>
using namespace std;

#define INF 1e9

int n, m, start, target;
vector<pair<int, int>> graph[1005];
int dist[1005];

void dijkstra() {
    priority_queue<pair<int, int>> pq;
    pq.push({0, start});

    while(!pq.empty()) {
        int w = -pq.top().first;
        int now = pq.top().second;
        pq.pop();

        if(dist[now] < w) continue;

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
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    cin >> n >> m;

    int a, b, c;
    for(int i = 0; i < m; i++) {
        cin >> a >> b >> c;
        graph[a].push_back({b, c});
    }

    cin >> start >> target;

    for(int i = 1; i <= n; i++) {
        if(i == start) dist[start] = 0;
        else dist[i] = INF;
    }

    dijkstra();

    cout << dist[target];

    return 0;
}