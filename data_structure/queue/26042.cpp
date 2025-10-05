// https://www.acmicpc.net/problem/26042

#include <iostream>
#include <queue>
using namespace std;

int main() {
    int n, order, s_num;
    int max_size = 0;
    int min_snum = 10000000;

    queue<int> q;

    cin >> n;

    for(int i = 0; i < n; i++) {
        cin >> order;
        if(order == 1) {
            cin >> s_num;
            q.push(s_num);

            if(q.size() > max_size) {
                max_size = q.size();\
                
                min_snum = s_num;
            }

            else if(q.size() == max_size && min_snum > s_num) {
                min_snum = s_num;
            }
        }

        else q.pop();
    }

    cout << max_size << " " << min_snum;

    return 0;
}