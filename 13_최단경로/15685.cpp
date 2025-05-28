#include <iostream>
#include <vector>

using namespace std;

bool visited[101][101];
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, -1, 0, 1};

void drawDragonCurve(int x, int y, int d, int g) {
    vector<int> directions;
    directions.push_back(d);

    for (int i = 0; i < g; i++) {
        int size = directions.size();
        for (int j = size - 1; j >= 0; j--) {
            directions.push_back((directions[j] + 1) % 4);
        }
    }

    visited[y][x] = true;

    for (int dir : directions) {
        x += dx[dir];
        y += dy[dir];
        if (x >= 0 && x <= 100 && y >= 0 && y <= 100) {
            visited[y][x] = true;
        }
    }
}

int countSquares() {
    int count = 0;
    for (int y = 0; y < 100; y++) {
        for (int x = 0; x < 100; x++) {
            if (visited[y][x] && visited[y][x+1] && visited[y+1][x] && visited[y+1][x+1])
                count++;
        }
    }
    return count;
}

int main() {
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        int x, y, d, g;
        cin >> x >> y >> d >> g;
        drawDragonCurve(x, y, d, g);
    }
    cout << countSquares() << '\n';
    return 0;
}