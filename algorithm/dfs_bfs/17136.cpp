// https://www.acmicpc.net/problem/17136
// set을 써서 중복 제거하고 모든 경우의 수 중 최솟값 구할 수 있다

#include <iostream>
#include <set>
#include <algorithm>
using namespace std;

int board[10][10];
int papers[6] = {0, 5, 5, 5, 5, 5};
set<int> result;

int find_max(int x, int y) {
    // 한번에 정사각형 모양으로 가능한질 봐야하니까
    // 우선 영역을 넘어가면 안되니까 늘어날 수 있는 범위부터 정하자
    int max_len = min(10 - x, 10 - y);
    
    for(int i = 1; i <= max_len; i++) {
        for(int a = x; a < x + i; a++) {
            for(int b = y; b < y + i; b++) {
                if(board[a][b] == 0) return i - 1;
            }
        }
    }

    return max_len;
}   

void cover(int x, int y, int l) {
    for(int a = x; a < x + l; a++) {
        for(int b = y; b < y + l; b++) {
            board[a][b] = 0;
        }
    }
}

void uncover(int x, int y, int l) {
    for(int a = x; a < x + l; a++) {
        for(int b = y; b < y + l; b++) {
            board[a][b] = 1;
        }
    }
}

int search(int cnt) {
    // 종료 조건은 색종이를 더이상 붙일 수 없으면
    // 재귀함수를 돌릴 때 사용한 색종이의 개수를 인수로 넣어야 트랙킹이 가능
    // 근데 재귀 돌때마다 0부터 계속 돌면 손해
    // 인수에 현재 좌표도 같이 넣어줘야겠다

    for(int i = 0; i < 10; i++) {
        for(int j = 0; j < 10; j++) {
            // 색종이를 붙여야하는 경우
            if(board[i][j] == 1) {
                // 우선 최대로 크게 붙일 수 있는 색종이를 찾고
                int max_size = find_max(i, j);

                // 현재 자리에 붙일 수 있는 색종이 다 붙여보기
                for(int k = max_size; k > 0; k--) {
                    // 아직 색종이가 남아있으면
                    if(papers[k] > 0) {
                        // 붙인 부분 0으로 바꾸기
                        cover(i, j, k);
                        papers[k]--;

                        // 다음 1 찾아가기
                        result.insert(search(cnt + 1));

                        // 돌아오면 복원
                        uncover(i, j, k);
                        papers[k]++;
                    }

                    // 더이상 붙일 색종이가 없으면
                    else return -1;
                }
            }
        }
    }
    
    // 어쨌든 간에 재귀를 다 돌아서 빠져나온다고 가정했을 때
    // 그 경우는 색종이를 다 붙인 경우이다
    return cnt;
}

int main() {
    // 10 x 10 종이의 각 칸에 적힌 수
    // 모든 1을 덮는데 필요한 색종이의 최소 개수
    // 1을 모두 덮는 것이 불가능한 경우에는 -1을 출력한다

    // 조건 1. 색종이는 종이 경계 밖으로 나가면 안된다
    // 조건 2. 겹쳐서도 안된다
    // 조건 3. 0이 있는 칸에는 색종이가 있으면 안된다

    // 걍 다 돌려본다 = Brute force 다!
    for(int i = 0; i < 10; i++) {
        for(int j = 0; j < 10; j++) {
            cin >> board[i][j];
        }
    }

    // 전체 보드 돌면서 1 찾으면
    // 거기에 붙일 수 있는 색종이 경우를 모두 탐색하기
    // 재귀함수를 통해서 각 경우에 경우를 쌓아가기
    
    search(0);

    // -1 제거
    result.erase(-1);

    // 최솟값 프린트
    cout << *result.begin();
}