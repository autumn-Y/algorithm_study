// https://www.acmicpc.net/problem/11725

#include <iostream>
#include <stdio.h>
#include <vector>
#include <queue>
using namespace std;

#define MAX 100000 + 1
int n;
vector<int> v[MAX];
int parents[MAX];
bool visited[MAX] = {false};

void bfs() {
    queue<int> q;
    q.push(1);
    visited[1] = true;

    while(!q.empty()) {
        int root = q.front();
        q.pop();
        
        for(int i = 0; i < v[root].size(); i++) {
            if(!visited[v[root][i]]) {
                q.push(v[root][i]);
                visited[v[root][i]] = true;
                parents[v[root][i]] = root;
            }
        }
    }
}

int main() {
    int n, a, b;

    cin >> n;
    for(int i = 0; i < n - 1; i++) {
        cin >> a >> b;
        v[a].push_back(b);
        v[b].push_back(a);
    }
    
    bfs();
    
    for(int i = 2; i <= n; i++) {
        printf("%d\n", parents[i]);
    }
}