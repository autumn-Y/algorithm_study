// https://www.acmicpc.net/problem/3052

#include <iostream>
#include <set>
using namespace std;

int main() {
    int now;
    set<int> s;

    for(int i = 0; i < 10; i++) {
        cin >> now;
        s.insert(now % 42);
    }

    cout << s.size();

    return 0;
}