#include <iostream>
#include <vector>
#include <queue>

using namespace std;

vector<int> family[101];
bool check[101];

// DFS로 깊이를 계산하는 함수
int findDepth(int person, int target, int depth) {
    if (person == target) {
        return depth; 
    }
    
    check[person] = true;
    
    for (int next : family[person]) {
        if (!check[next]) {
            int result = findDepth(next, target, depth + 1);
            if (result != -1) {
                return result;
            }  // 촌수를 찾았다면 그 값을 리턴
        }
    }
    return -1;  // 찾지 못한 경우
}

int main() {
    int n, person1, person2, m;
    cin >> n >> person1 >> person2 >> m;

    // 부모-자식 관계 입력
    for (int i = 0; i < m; ++i) {
        int x, y;
        cin >> x >> y;
        family[x].push_back(y);  // x는 y의 부모
        family[y].push_back(x);  // y는 x의 자식
    }

    int depth = findDepth(person1, person2, 0); 
    if (depth != -1) {
        cout << depth << "\n";
    } else {
        cout << -1 << "\n"; 
    }

    return 0;
}