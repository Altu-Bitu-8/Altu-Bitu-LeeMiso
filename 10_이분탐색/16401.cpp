#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int countCookies(int length, const vector<int>& cookies) {
    int count = 0;
    for (int cookie : cookies) {
        count += cookie / length;
    }
    return count;
}

int binarySearch(int left, int right, int m, const vector<int>& cookies) {
    int answer = 0;
    
    while (left <= right) {
        int mid = (left + right) / 2;
        int installed = countCookies(mid, cookies);

        if (installed >= m) { 
            answer = mid;
            left = mid + 1;
        } 
        else { 
            right = mid - 1;
        }
    }
    
    return answer;
}

int main() {
    int m, n;
    cin >> m >> n;
    
    vector<int> cookies(n);
    for (int i = 0; i < n; i++) {
        cin >> cookies[i]; 
    }

    sort(cookies.begin(), cookies.end());
    int answer = binarySearch(1, cookies.back(), m, cookies);

    cout << answer << endl;
}
