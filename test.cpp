#include <iostream>
#include <queue>
#include <utility>
#include <vector>
#include <functional>
#include <list>
#include <map>
#include <set>
#include <algorithm>
using namespace std;

int main() {
    vector<int> v = {5, 2, 9, 1, 7};

    // 1. push_back
    v.push_back(10);

    // 2. pop_back
    v.pop_back();

    // 3. size
    cout << v.size() << endl;

    // 4. empty
    cout << "is empty? " << (v.empty() ? "yes" : "no") << endl;

    // 5. front
    cout << "front: " << v.front() << endl;

    // 6. back
    cout << "back: " << v.back() << endl;

    // 7. at : 인덱스로 접근 (범위 체크)
    cout << "element at index 2: " << v.at(2) << endl;

    // 8. operator[] : 인덱스로 접근 (범위 체크 없음)
    cout << "element at index 3: " << v[3] << endl;

    // 9. insert
    v.insert(v.begin() + 2, 99);

    // 10. erase
    v.erase(v.begin() + 1);

    // 11. sort
    sort(v.begin(), v.end());

    // 12. reverse
    reverse(v.begin(), v.end());

    // 13. find : 특정 값 찾기
    auto it = find(v.begin(), v.end(), 99);
    if(it != v.end()) {
        cout << "found 99 at index: " << distance(v.begin(), it) << endl;
    }

    // 14. emplace_back
    v.emplace_back(42);

    // 15. print all
    cout << "vector contents: ";
    for(int x : v) {
        cout << x << " ";
    }
    cout << endl;

    // 16. clear
    v.clear();

    return 0;
}