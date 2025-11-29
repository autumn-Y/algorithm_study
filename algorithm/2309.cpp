// https://www.acmicpc.net/problem/2309

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int height[9];
vector<int> v;
bool _find = false;
int _left = 100;

void search(int idx) {
    if(idx == 7) {
        if(_left == 0) { 
            _find = true;
            sort(v.begin(), v.end());

            for(int i = 0; i < 7; i++) {
                cout << v[i] << endl;
            }
        }

        return;
    }

    if(!_find) {
        for(int i = idx; i < 9; i++) {
            _left -= height[i];
            v.push_back(height[i]);
            search(idx + 1);
            v.pop_back();
            _left += height[i];
        }
    }
}

int main() {
    // 난쟁이들의 키 (< 100)
    // 가능한 정답이 여러가지의 경우에는 아무거나 출력
    // 일곱 난쟁이의 키를 오름차순으로 출력한다
    // 일곱 난쟁이의 합 = 100

    // 이거 bfs 써서 9개 중에 7개 쓰는 조합 찾고
    // 그 조합 중에 합이 100이 되는 경우를 출력하면 될거 같은데?

    for(int i = 0; i < 9; i++) {
        cin >> height[i];
    }

    search(0);

    return 0;
}