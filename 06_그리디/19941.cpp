#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n, k;
    cin >> n >> k;
    string s;
    cin >> s;

    // 문자열을 문자 배열로 변환
    vector<char> arr(s.begin(), s.end());

    // k부터 1까지 줄여가며 탐색
    for (int dist = k; dist >= 1; --dist) {
        for (int i = 0; i < n; ++i) {
            if (arr[i] == 'P') {
                for (int d = -dist; d <= dist; ++d) {
                    int j = i + d;
                    if (j >= 0 && j < n && arr[j] == 'H') {
                        arr[j] = 'o';  // 햄버거 먹음 표시
                        arr[i] = 'x';  // 먹은 사람 표시 
                        break;
                    }
                }
            }
        }
    }

    // O의 개수 세기
    int result = count(arr.begin(), arr.end(), 'o');
    cout << result << '\n';

    return 0;
}