#include <iostream>
#include <vector>
#include <queue>
#include <tuple>

using namespace std;

const int INF = 1e9; 
int dx[4] = {0, 0, -1, 1}; 
int dy[4] = {-1, 1, 0, 0};

int dijkstra(const vector<vector<int>> &cave, int n) {
    vector<vector<int>> dist(n, vector<int>(n, INF));
    priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>, greater<>> pq;

    dist[0][0] = cave[0][0];
    pq.push({dist[0][0], 0, 0});

    while (!pq.empty()) {
        auto [cost, x, y] = pq.top(); pq.pop();
        if (cost > dist[x][y]) continue;

        for (int dir = 0; dir < 4; dir++) {
            int nx = x + dx[dir];
            int ny = y + dy[dir];

            if (nx >= 0 && ny >= 0 && nx < n && ny < n) {
                int next_cost = cost + cave[nx][ny];
                if (next_cost < dist[nx][ny]) {
                    dist[nx][ny] = next_cost;
                    pq.push({next_cost, nx, ny});
                }
            }
        }
    }
    return dist[n - 1][n - 1];
}

int main() {
    int n, test_case = 1;
    while (cin >> n, n != 0) {
        vector<vector<int>> cave(n, vector<int>(n));
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++)
                cin >> cave[i][j];

        int result = dijkstra(cave, n);
        cout << "Problem " << test_case++ << ": " << result << '\n';
    }
    return 0;
}
