// https://www.acmicpc.net/problem/12605

#include <iostream>
#include <stack>
#include <string>
using namespace std;

int main() {
    int n;
    int now = 1;
    cin >> n;
    cin.ignore();

    for(int now = 1; now <= n; now++) {
        string s;
        stack<string> st;
        string temp, ans;
        getline(cin, s);

        for(int i = 0; i < s.length(); i++) {
            if(s[i] == ' ') {
                st.push(temp);
                st.push(" ");
                temp.clear();
            }

            else temp += s[i];
        }
        st.push(temp);

        while(!st.empty()) {
            ans += st.top();
            st.pop();
        }

        cout << "Case #" << now << ": " << ans << endl;
    }
}