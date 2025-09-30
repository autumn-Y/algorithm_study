// https://www.acmicpc.net/problem/2745

#include <iostream>
#include <stdio.h>
#include <string>
#include <cmath>
using namespace std;

int main() {
    string s;
    int B, len;
    int ans = 0;

    cin >> s >> B;
    len = s.length();

    for(int i = 0; i < len; i++) {
        // string에서 값 추출
        if('0' <= s[i] && s[i] <= '9') {
            ans += (s[i] - '0') * pow(B, len-i-1);
        }        
        else {
            ans += (s[i]-'A'+10) * pow(B, len-i-1);
        }
    }

    cout << ans;

    return 0;
}