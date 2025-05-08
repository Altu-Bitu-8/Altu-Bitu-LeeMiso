#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const int NUM = 1e9;
int n;
int w[10][10];         // 비용 행렬
bool visited[10];      // 방문 여부
int min_cost = NUM;     // 최소 비용 저장

void backtracking(int start, int now, int sum, int count) {
    if (count == n) {
        if (w[now][start] != 0) {
            min_cost = min(min_cost, sum + w[now][start]);
        }
        return;
    }

    for (int next = 0; next < n; next++) {
        if (!visited[next] && w[now][next] != 0) {
            visited[next] = true;
            backtracking(start, next, sum + w[now][next], count + 1);
            visited[next] = false;  // 백트래킹
        }
    }
}

int main() {
    cin >> n;

    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            cin >> w[i][j];

    visited[0] = true;
    backtracking(0, 0, 0, 1);

    cout << min_cost << "\n";

    return 0;
}

