// https://www.acmicpc.net/problem/3986

#include <iostream>
#include <string>
#include <stack>
using namespace std;

int main() {
    int N;
    int ans = 0;

    stack<char> st;
    string s;

    cin >> N;

    // 스택이 안비었고, top이 같으면 pop
    // 아니면 push
    // 결국 다 돌았을 때 스택에 남아있으면 좋은 단어가 아님

    for(int i = 0; i < N; i++) {
        cin >> s;
        st = {};

        for(int j = 0; j < s.length(); j++) {
            if(!st.empty() && st.top() == s[j]) {
                st.pop();
            }
            else st.push(s[j]);
        }

        if(st.empty()) ans++;
    }

    cout << ans;
}