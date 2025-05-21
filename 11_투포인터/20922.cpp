#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int findLength(const vector<int>& arr, int k) {
    int count[100001] = {0};
    int left = 0, right = 0;
    int answer = 0;
    int n = arr.size();

    while (right < n) {
        count[arr[right]]++;

        while (count[arr[right]] > k) {
            count[arr[left]]--;
            left++;
        }

        answer = max(answer, right - left + 1);
        right++;
    }

    return answer;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, k;
    cin >> n >> k;

    vector<int> arr(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    int result = findLength(arr, k);
    cout << result << '\n';

    return 0;
}
