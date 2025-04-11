#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int main() {
    int n, r;
    cin >> n >> r;

    vector<vector<int>> computer(n + 1);

    for (int i = 0; i < r; i++) {
        int a, b;
        cin >> a >> b;
        computer[a].push_back(b);
        computer[b].push_back(a); 
    }

    // BFS로 1번 컴퓨터부터 전염될 수 있는 컴퓨터를 찾아봄
    vector<bool> visited(n + 1, false); 
    queue<int> q;
    int count = 0; // 바이러스에 걸리는 컴퓨터 수

    q.push(1);
    visited[1] = true;

    while (!q.empty()) {
        int now = q.front();
        q.pop();

        // 현재 컴퓨터와 연결된 컴퓨터들 탐색
        for (int next : computer[now]) {
            if (!visited[next]) {
                visited[next] = true;
                q.push(next);
                count++;
            }
        }
    }

    // 1번 컴퓨터를 제외한 전염된 컴퓨터 수 출력
    cout << count << "\n";

    return 0;
}