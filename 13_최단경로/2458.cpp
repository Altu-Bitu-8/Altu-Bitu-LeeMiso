#include <iostream>
#include <vector>

using namespace std;

const int INF = 1e9;

void floydWarshall(int n, vector<vector<int>> &graph) {
    for (int k = 1; k <= n; k++) {
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                if (graph[i][k] && graph[k][j]) {
                    graph[i][j] = 1; 
                }
            }
        }
    }
}

int main() {
    int n, m;
    cin >> n >> m;

    vector<vector<int>> graph(n + 1, vector<int>(n + 1, 0));

    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        graph[a][b] = 1; 
    }

    floydWarshall(n, graph);

    int result = 0;
    for (int i = 1; i <= n; i++) {
        int taller = 0, shorter = 0;
        for (int j = 1; j <= n; j++) {
            if (graph[i][j]) taller++; 
            if (graph[j][i]) shorter++;
        }
        if (taller + shorter == n - 1) result++;
    }

    cout << result << '\n';
    return 0;
}
