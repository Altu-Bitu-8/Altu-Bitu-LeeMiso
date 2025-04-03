#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    // 입력
    int n;
    cin >> n;
    vector<int> a(n), dp(n, 1), arr;

    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    int max_len = 0;  // 최장 LIS 길이
    int max_idx = -1; // LIS의 마지막 위치

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < i; j++) {
            if (a[i] > a[j]) {
                dp[i] = max(dp[i], dp[j] + 1);  // LIS 갱신
            }
        }
        if (max_len < dp[i]) {
            max_len = dp[i];
            max_idx = i;
        }
    }

    // 끝에서부터 추적하며 부분 수열 저장
    int length = max_len;
    for (int i = max_idx; i >= 0; i--) {
        if (dp[i] == length) {
            arr.push_back(a[i]);
            length--;
        }
    }

    // 출력
    cout << max_len << "\n";

    return 0;
}
