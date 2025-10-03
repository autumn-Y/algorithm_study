// https://www.acmicpc.net/problem/11005

#include <iostream>
#include <cmath>
#include <string>
using namespace std;

int main() {
    int N, B, temp;
    string ans;

    cin >> N >> B;

    while(N != 0) {
        // 나머지는 문자열로 바꿔서 거꾸로 쌓기
        temp = N % B;

        if(temp < 10) {
            ans = char(temp+'0') + ans;
        }

        else {
            ans = char(temp-10+'A') + ans;
        }

        N /= B;
    }

    cout << ans;
    return 0;
}