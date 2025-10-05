// https://www.acmicpc.net/problem/30614

#include <iostream>
#include <stack>
#include <string>
#include <cctype>
using namespace std;

int main() {
    int n;
    string log;
    stack<char> st;

    cin >> n;
    cin >> log;

    for(int i = 0; i < n; i++) {
        if(isupper(log[i])) {
            if(st.empty()) continue;
            st.pop();
        }

        if(islower(log[i])) {
            st.push(log[i]);
        }
    }

    if(st.empty()) cout << 1;
    else cout << 0;

    return 0;
}