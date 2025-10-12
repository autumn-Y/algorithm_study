// https://www.acmicpc.net/problem/1406

# include <iostream>
# include <list>
# include <string>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    string str;
    list<char> lst_f, lst_b;
    int M;
    char order, ch;

    cin >> str >> M;
    
    for(int i = 0; i < str.length(); i++) {
        lst_f.push_back(str[i]);
    }

    while(M--) {
        cin >> order;

        // L: 앞 리스트 마지막을 뒷 리스트 앞으로
        if(order == 'L') {
            // 앞 리스트가 빈 리스트이면 무시
            if(lst_f.empty()) continue;
            lst_b.push_front(*lst_f.rbegin());
            lst_f.pop_back();
        }

        // D: 뒷 리스트 앞을 앞 리스트 마지막으로
        if(order == 'D') {
            // 뒷 리스트가 빈 리스트면 무시
            if(lst_b.empty()) continue;
            lst_f.push_back(*lst_b.begin());
            lst_b.pop_front();
        }

        // B: 앞 리스트 마지막을 삭제
        if(order == 'B') {
            // 앞 리스트가 빈칸이면 무시
            if(lst_f.empty()) continue;
            lst_f.pop_back();
        }

        // P: 앞 리스트 마지막에 삽입
        if(order == 'P') {
            cin >> ch;
            lst_f.push_back(ch);
        }
    }

    for(auto x : lst_f) cout << x;
    for(auto x : lst_b) cout << x;
}

/* First try
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    string str;
    list<char> lst;
    int M, input;
    char order, ch;

    cin >> str;
    cin >> M;
    
    int cursor = str.length();

    for(int i = 0; i < str.length(); i++) {
        lst.push_back(str[i]);
    }

    while(M--) {
        cin >> order;

        // L
        if(order == 'L') {
            // 맨 앞이면 무시
            if(cursor == 0) continue;
            cursor--;
        }

        // D
        else if(order == 'D') {
            // 맨 뒤면 무시
            if(cursor == lst.size()) continue;
            cursor++;
        }

        // B
        else if(order == 'B') {
            // 맨 앞이면 무시
            if(cursor == 0) continue;

            lst.erase(next(lst.begin(), --cursor));
        }

        // P $
        else if(order == 'P') {
            cin >> ch;
            //맨 앞일 때
            if(cursor == 0) lst.push_front(ch);
            //맨 끝일 때
            else if(cursor == lst.size()) lst.push_back(ch);

            // 중간일 때
            else lst.insert(next(lst.begin(), cursor), ch);
            
            cursor++;   
        }

        else continue;
    }

    for(auto x : lst) {
        cout << x;
    }

    return 0;
}
*/