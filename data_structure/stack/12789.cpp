// https://www.acmicpc.net/problem/12789

#include <iostream>
#include <stack>
using namespace std;

int arr[1000];

int main() {
    // 몇 번이 들어갈 차례인지 확인하는 변수 필요하고
    // 현재 차례보다 큰 숫자가 들어가면 스택에 push
    // top 계속 확인해서 현재 차례인지 확인하고
    // 더이상 줄에 서있는 사람이 없으면 계속 pop
    // stack이 비면 Nice, 아님 Sad

    int n, temp;
    int now = 1;
    stack<int> st;

    cin >> n;

    for(int i = 0; i < n; i++) {
        cin >> temp;
        if(temp == now) {
            now ++;
        }

        else {
            st.push(temp);
        }

        while(!st.empty() && st.top() == now) {
            st.pop();
            now++;
        }
    }

    if(st.empty()) cout << "Nice";
    else cout << "Sad";
}