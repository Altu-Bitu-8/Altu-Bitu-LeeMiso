#include <iostream>
#include <vector>

using namespace std;

bool dfs(int current, int target, int dist, int &answer, vector<vector<pair<int, int>>> &graph, vector<bool> &visited) {
    if (current == target) {
        answer = dist;
        return true;
    }

    visited[current] = true;

    for (int i = 0; i < graph[current].size(); ++i) {
        int next = graph[current][i].first;
        int weight = graph[current][i].second;

        if (!visited[next]) {
            if (dfs(next, target, dist + weight, answer, graph, visited)) {
                return true;
            }
        }
    }

    return false;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, m;
    cin >> n >> m;

    vector<vector<pair<int, int>>> graph(n + 1);

    for (int i = 0; i < n - 1; ++i) {
        int a, b, length;
        cin >> a >> b >> length;
        graph[a].push_back({b, length});
        graph[b].push_back({a, length});
    }

    for (int i = 0; i < m; ++i) {
        int a, b;
        cin >> a >> b;
        vector<bool> visited(n + 1, false);
        int answer = 0;
        dfs(a, b, 0, answer, graph, visited);
        cout << answer << '\n';
    }

    return 0;
}
