// https://www.acmicpc.net/problem/2566

#include <iostream>
#include <vector>
#include <stdio.h>
using namespace std;

int main() {
    int max = -1;
    int now, row, col;
    
    for(int i = 0; i < 9; i++) {
        for(int j = 0; j < 9; j++) {
            cin >> now;
            if(now > max) {
                max = now;
                row = i;
                col = j;
            }
        }
    }

    cout << max << endl;
    cout << row + 1 << " " << col + 1;
}