#include <iostream>
#include <string>
#include <stack>
using namespace std;

int main() {
    string s;
    s = "test is boring";
    stack<char> st;

    for(int i = 0; i < s.length(); i++) {
        st.push(s[i]);
    }

    for(int i = 0; i < st.size(); i++) {
        cout << st.top();
        st.pop();
    }

    return 0;
}