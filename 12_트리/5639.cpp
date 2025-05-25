#include <iostream>
#include <vector>
using namespace std;

vector<int> preorder;

void solve(int start, int end) {
    if (start >= end) 
        return;

    int root = preorder[start];
    int idx = start + 1;

    while (idx < end && preorder[idx] < root) {
        idx++;
    }

    solve(start + 1, idx);
    solve(idx, end);
    cout << root << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int x;
    while (cin >> x) {
        preorder.push_back(x);
    }

    solve(0, preorder.size());

    return 0;
}
