// https://www.acmicpc.net/problem/2526

#include <iostream>
#include <map>
using namespace std;

int main() {
    int N, P, temp, before, start;
    int now = 0;
    map<int, int> m;

    cin >> N >> P;
    
    // map으로 해서 키는 나머지값, value는 몇번쨰 수인지를 저장하고
    // key가 있는지 확인, 있으면 현재 - value

    m.insert({N, now++});
    before = N;

    while(true) {
        temp = (before * N) % P;

        if(m.find(temp) != m.end()) {
            start = m[temp];
            break;
        }

        m.insert({temp, now++});
        before = temp;
    }
    
    cout << now - start;

    return 0;
}