#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int getMax(const vector<int>& sushi, int n, int d, int k, int c) {
    vector<int> count(d + 1, 0);
    int unique = 0;

    for (int i = 0; i < k; ++i) {
        if (count[sushi[i]] == 0) unique++;
        count[sushi[i]]++;
    }

    int answer = (count[c] == 0) ? unique + 1 : unique;

    for (int left = 0; left < n; ++left) {
        int right = (left + k) % n;

        count[sushi[left]]--;
        if (count[sushi[left]] == 0) unique--;

        if (count[sushi[right]] == 0) unique++;
        count[sushi[right]]++;

        // 현재 종류 + 쿠폰 초밥 포함 여부
        int total = (count[c] == 0) ? unique + 1 : unique;
        answer = max(answer, total);
    }

    return answer;
}

int main() {
    int n, d, k, c;
    cin >> n >> d >> k >> c;

    vector<int> sushi(n);
    for (int i = 0; i < n; ++i) {
        cin >> sushi[i];
    }

    int result = getMax(sushi, n, d, k, c);
    cout << result << endl;

    return 0;
}
