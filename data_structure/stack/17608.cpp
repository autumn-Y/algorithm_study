// https://www.acmicpc.net/problem/17608

#include <iostream>
#include <stack>
using namespace std;

int main() {
    stack<int> s;
    int n, h;
    int cnt = 0;
    int max = 0;
    
    cin >> n;

    for(int i = 0; i < n; i++) {
        cin >> h;
        s.push(h);
    }

    for(int i = 0; i < n; i++) {
        h = s.top();
        if(h > max) {
            cnt++;
            max = h;
        }
        s.pop();
    }

    cout << cnt;

    return 0;
}