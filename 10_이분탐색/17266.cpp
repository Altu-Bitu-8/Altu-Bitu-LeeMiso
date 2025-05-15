#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool isPossible(int h, vector<int>& position, int n) {
    int prev = 0;

    for (int i = 0; i < position.size(); i++) {
        int left = position[i] - h;
        int right = position[i] + h;

        if (left > prev)
            return false;
        prev = max(prev, right);
    }

    return (prev >= n); 
}

int binarySearch(int n, vector<int>& position) {
    int left = 0;
    int right = n;
    int mid;

    while (left <= right) {
        mid = (left + right) / 2;

        if (isPossible(mid, position, n)) {
            right = mid - 1;
        } 
        else {
            left = mid + 1;
        }
    }

    return left;
}

int main() {
    int n, m;
    vector<int> position;
    cin >> n >> m;
    position.resize(m);

    for (int i = 0; i < m; i++) {
        cin >> position[i];
    }

    cout << binarySearch(n, position) << '\n';
    return 0;
}
