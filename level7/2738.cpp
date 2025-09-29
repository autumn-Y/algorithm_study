// 두 행렬의 합을 구하는 문제
// https://www.acmicpc.net/problem/2738

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() { 
    int n, m;

    cin >> n >> m;

    int a[n][m];
    int b[n][m];
    int result[n][m];

    for(int i=0; i<n; i++) {
        for(int j=0; j<m; j++) {
            cin >> a[i][j];
        }
    }

    for(int i=0; i<n; i++) {
        for(int j=0; j<m; j++) {
            cin >> b[i][j];
        }
    }
    
    for(int i=0; i<n; i++) {
        for(int j=0; j<m; j++) {
            result[i][j] = a[i][j] + b[i][j];
        }
    }
    
    for(int i=0; i<n; i++) {
        for(int j=0; j<m; j++) {
            cout << result[i][j] << " ";
        }
        cout << endl;
    }
}