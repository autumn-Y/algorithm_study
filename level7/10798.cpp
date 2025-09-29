// https://www.acmicpc.net/problem/10798

#include <iostream>
#include <stdio.h>
#include <string>
#include <vector>
using namespace std;

string letter[5];
int len[5];

int main() {
    // string 입력받기
    for(int i = 0; i < 5; i++) {
        cin >> letter[i];
        len[i] = letter[i].length();
    }

    // now가 i번째 string 길이보다 크면 pass
    // 아니면 letter[i][j] 문자 출력 

    for(int now = 0; now < 15; now++) {
        for(int i = 0; i < 5; i++) {
            if(len[i] < now + 1) continue;

            else {
                cout << letter[i][now];
            }
        }
    }

    return 0;
}