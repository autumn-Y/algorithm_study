// https://www.acmicpc.net/problem/16165
// map의 value로 vector 사용 가능!!

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <map>
using namespace std;

int main() {
    // input : 입력받을 걸그룹의 수 N, 문제 수 M
    // 팀의 이름, 걸그룹 인원수, 멤버 이름
    // 모든 글자는 알파벳 소문자
    // 중복 이름 없음

    // 퀴즈는 두줄 : 팀의 이름/멤버이름, 퀴즈 종류(0, 1)
    // 0: 팀의 이름
    // 1: 멤버 이름

    int N, M, mem_num;
    // 0: key - 팀 이름, value - 멤버 벡터
    map<string, vector<string>> quiz_0;
    // 1: key - 멤버 이름, value - 팀 이름
    map<string, string> quiz_1;
    
    cin >> N >> M;
    
    // #1. 걸그룹 입력 영역
    while(N-- > 0) {
        string team, name;
        vector<string> v;
        v.clear();

        cin >> team >> mem_num;
        for(int i = 0; i < mem_num; i++) {
            cin >> name;
            v.push_back(name);
            quiz_1.insert({name, team});
        }    
        sort(v.begin(), v.end());
        quiz_0.insert({team, v});
    }

    // #2. 퀴즈부분
    // output: 퀴즈에 대한 답 출력
    // 0 : 해당 팀에 속한 멤버의 이름을 사전식으로 한명씩 출력
    // 1 : 해당 멤버가 속한 팀의 이름을 출력

    while(M-- > 0) {
        int num;
        string quiz;
        cin >> quiz >> num;
        // 0번 유형 퀴즈 : 팀을 입력으로
        if(num == 0) {
            for(int i = 0; i < quiz_0[quiz].size(); i++) {
                cout << quiz_0[quiz][i] << endl;
            }
        }

        // 1번 유형 퀴즈
        else if(num == 1) {
            cout << quiz_1[quiz] << endl;
        }
    }

    return 0;
}