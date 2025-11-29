// https://www.acmicpc.net/problem/17136r

#include <iostream>
#include <algorithm>
using namespace std;

int board[10][10];
int papers[6] = {0, 5, 5, 5, 5, 5};
int result = 10000;

int find_max(int x, int y) {
    // 한번에 정사각형 모양으로 가능한질 봐야하니까
    // 우선 영역을 넘어가면 안되니까 늘어날 수 있는 범위부터 정하자
    int max_len = min(10 - x, 10 - y);
    max_len = min(max_len, 5);
    
    // (x, y)엔 이미 1 x 1 색종이를 붙일 수 있으니까
    // i는 양옆으로 다음 칸의 거리를 의미
    // 즉, i = 1일 때는 2x2의 경우를 탐색하는 것
    for(int i = 1; i < max_len; i++) {
        for(int a = x; a <= x + i; a++) {
            for(int b = y; b <= y + i; b++) {
                if(board[a][b] == 0) return i;
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

bool left_paper() {
    for(int i = 0; i < 10; i++) {
        for(int j = 0; j < 10; j++) {
            if(board[i][j] == 1) return false;
        }
    }

    return true;
}

void search(int cnt) {
    // 종료 조건은 색종이를 더이상 붙일 수 없으면
    // 재귀함수를 돌릴 때 사용한 색종이의 개수를 인수로 넣어야 트랙킹이 가능
    
    // 종료 조건 1. 더 이상 붙일 색종이가 없다
    if(left_paper()) {
        if(cnt < result) result = cnt;
        return;
    }

    // 종료 조건 2. 애초에 이미 최솟값이 아닌 경우이다
    if(cnt > result) return;

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
                        search(cnt + 1);

                        // 돌아오면 복원
                        uncover(i, j, k);
                        papers[k]++;
                    }
                }

                return;
            }
        }
    }
    
    // 어쨌든 간에 재귀를 다 돌아서 빠져나온다고 가정했을 때
    // 그 경우는 색종이를 다 붙인 경우이다
    return;
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

    if(result == 10000) result = -1;

    cout << result;
}