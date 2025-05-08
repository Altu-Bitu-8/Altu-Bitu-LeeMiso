#include <iostream>
#include <vector>
using namespace std;

int n;
vector<int> numbers;
int op[4]; // + - * / 남은 개수
int MAX = -1000000000;
int MIN = 1000000000;

void backtracking(int idx, int current, vector<int> &ops) {
    if (idx == n) {
        // 모든 숫자를 다 사용한 경우 결과 갱신
        if (current > MAX) MAX = current;
        if (current < MIN) MIN = current;
        return;
    }

    for (int i = 0; i < 4; i++) {
        if (ops[i] > 0) {
            ops[i]--;  // 해당 연산자 사용

            int next = current;
            if (i == 0) next = current + numbers[idx];
            else if (i == 1) next = current - numbers[idx];
            else if (i == 2) next = current * numbers[idx];
            else if (i == 3) {
                if (current < 0)
                    next = -(-current / numbers[idx]);
                else
                    next = current / numbers[idx];
            }

            backtracking(idx + 1, next, ops);  // 다음 단계

            ops[i]++;  // 연산자 되돌리기 (백트래킹)
        }
    }
}

int main() {
    cin >> n;
    numbers.resize(n);

    for (int i = 0; i < n; i++) {
        cin >> numbers[i];
    }

    vector<int> ops(4); // + - * /
    for (int i = 0; i < 4; i++) {
        cin >> ops[i];
    }

    backtracking(1, numbers[0], ops);

    cout << MAX << '\n';
    cout << MIN << '\n';
    return 0;
}
