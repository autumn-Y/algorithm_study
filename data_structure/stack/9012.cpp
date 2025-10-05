// https://www.acmicpc.net/problem/9012

#include <iostream>
#include <stack>
#include <string>
using namespace std;

int main() {
    // "(" 이면 push, ")" 이면 pop
    // pop 하려고 하는데 empty 거나,
    // 탐색을 다 끝냈는데 stack에 남아있으면 NO
    // 탐색을 다 끝냈는데 empty면 yes

    int T, j;
    stack<char> st;
    string s;

    cin >> T;

    for(int i = 0; i < T; i++) {
        cin >> s;
        st = {};

        for(j = 0; j < s.length(); j++) {
            if(s[j] == '(') st.push(s[j]);
            
            else {
                if(st.empty()) break;
                st.pop();
            }
        }
        if(st.empty() && j == s.length()) cout << "YES" << endl;

        else {
            cout << "NO" << endl;;
        }
    }
}